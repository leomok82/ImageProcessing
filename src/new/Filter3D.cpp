#include "Filter3D.h"
#include "Slice.h" // Make sure this includes the definition of the Slice class
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // For std::min and std::max
#include "stb_image_write.h" // Needed for saving slices if using stb_image_write in Slice

// Helper function to create a 3D Gaussian kernel
std::vector<std::vector<std::vector<double>>> createGaussianKernel(int kernelSize, double sigma) {
    int range = kernelSize / 2;
    std::vector<std::vector<std::vector<double>>> kernel(kernelSize, std::vector<std::vector<double>>(kernelSize, std::vector<double>(kernelSize)));
    double sum = 0.0;

    for (int x = -range; x <= range; x++) {
        for (int y = -range; y <= range; y++) {
            for (int z = -range; z <= range; z++) {
                double value = (1 / (pow(sigma, 3) * sqrt(2 * M_PI))) * exp(-(x * x + y * y + z * z) / (2 * sigma * sigma));
                kernel[x + range][y + range][z + range] = value;
                sum += value;
            }
        }
    }

    // Normalize the kernel
    for (int x = 0; x < kernelSize; x++) {
        for (int y = 0; y < kernelSize; y++) {
            for (int z = 0; z < kernelSize; z++) {
                kernel[x][y][z] /= sum;
            }
        }
    }

    return kernel;
}

std::vector<std::vector<std::vector<double>>> createGaussianKernel(int kernelSize, double sigma);

void Gaussian3DFilter::apply(Volume& volume) {
    std::cout << "Applying 3D Gaussian Filter with kernel size: " << kernelSize << std::endl;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    double sigma = kernelSize / 6.0;
    auto kernel = createGaussianKernel(kernelSize, sigma);

    std::vector<unsigned char> newData(width * height * depth, 0); // New volume data

    for (int z = 0; z < depth; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double filteredValue = 0.0;
                double weightSum = 0.0;

                for (int kz = -kernelSize / 2; kz <= kernelSize / 2; kz++) {
                    for (int ky = -kernelSize / 2; ky <= kernelSize / 2; ky++) {
                        for (int kx = -kernelSize / 2; kx <= kernelSize / 2; kx++) {
                            int xx = std::clamp(x + kx, 0, width - 1);
                            int yy = std::clamp(y + ky, 0, height - 1);
                            int zz = std::clamp(z + kz, 0, depth - 1);

                            double kernelValue = kernel[kz + kernelSize / 2][ky + kernelSize / 2][kx + kernelSize / 2];
                            filteredValue += kernelValue * static_cast<double>(volume.getVoxel(xx, yy, zz));
                            weightSum += kernelValue;
                        }
                    }
                }

                int dataIndex = z * width * height + y * width + x;
                newData[dataIndex] = static_cast<unsigned char>(std::clamp(filteredValue / weightSum, 0.0, 255.0));
            }
        }
    }

    volume.setData(newData);
    std::cout << "Gaussian filter applied successfully." << std::endl;
}

void Median3DFilter::apply(Volume& volume) {
    // Placeholder for the 3D Median filter algorithm
    std::cout << "Applying 3D Median Filter with kernel size: " << kernelSize << std::endl;
    // Actual filtering logic goes here
}