#include "Filter3D.h"
#include "Slice.h" // Make sure this includes the definition of the Slice class
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // For std::min and std::max
#include "stb_image_write.h" // Needed for saving slices if using stb_image_write in Slice

// // Helper function to create a 3D Gaussian kernel
// std::vector<std::vector<std::vector<double>>> createGaussianKernel(int kernelSize, double sigma) {
//     int range = kernelSize / 2;
//     std::vector<std::vector<std::vector<double>>> kernel(kernelSize, std::vector<std::vector<double>>(kernelSize, std::vector<double>(kernelSize)));
//     double sum = 0.0;

//     for (int x = -range; x <= range; x++) {
//         for (int y = -range; y <= range; y++) {
//             for (int z = -range; z <= range; z++) {
//                 double value = (1 / (pow(sigma, 3) * sqrt(2 * M_PI))) * exp(-(x * x + y * y + z * z) / (2 * sigma * sigma));
//                 kernel[x + range][y + range][z + range] = value;
//                 sum += value;
//             }
//         }
//     }

//     // Normalize the kernel
//     for (int x = 0; x < kernelSize; x++) {
//         for (int y = 0; y < kernelSize; y++) {
//             for (int z = 0; z < kernelSize; z++) {
//                 kernel[x][y][z] /= sum;
//             }
//         }
//     }

//     return kernel;
// }

std::vector<double> createGaussianKernel(double sigma, int kernelSize) {
    int halfSize = kernelSize / 2;
    std::vector<double> kernel(kernelSize);
    double sum = 0.0;
    for (int i = -halfSize; i <= halfSize; ++i) {
        kernel[i + halfSize] = exp(-0.5 * (i * i) / (sigma * sigma)) / (sqrt(2 * M_PI) * sigma);
        sum += kernel[i + halfSize];
    }
    // Normalize the kernel
    for (auto &value : kernel) {
        value /= sum;
    }
    return kernel;
}


std::vector<double> createGaussianKernel(double sigma, int kernelSize);

void applyFilter1D(const std::vector<double>& kernel, std::vector<unsigned char>& data, int width, int height, int depth, char direction) {
    std::vector<unsigned char> result(data.size());
    int halfSize = kernel.size() / 2;

    std::cout << "Applying 1D filter in direction: " << direction << std::endl;

    if (direction == 'x') {
        for (int z = 0; z < depth; ++z) {
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    double filteredValue = 0.0;
                    for (int k = -halfSize; k <= halfSize; ++k) {
                        int xx = std::clamp(x + k, 0, width - 1);
                        filteredValue += kernel[k + halfSize] * data[z * width * height + y * width + xx];
                    }
                    // std::cout << "Filtered value: " << filteredValue << std::endl;
                    result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
                }
            }
        }
    } else if (direction == 'y') {
        for (int z = 0; z < depth; ++z) {
            for (int x = 0; x < width; ++x) {
                for (int y = 0; y < height; ++y) {
                    double filteredValue = 0.0;
                    for (int k = -halfSize; k <= halfSize; ++k) {
                        int yy = std::clamp(y + k, 0, height - 1);
                        filteredValue += kernel[k + halfSize] * data[z * width * height + yy * width + x];
                    }
                    // std::cout << "Filtered value: " << filteredValue << std::endl;
                    result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
                }
            }
        }
    } else if (direction == 'z') {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                for (int z = 0; z < depth; ++z) {
                    double filteredValue = 0.0;
                    for (int k = -halfSize; k <= halfSize; ++k) {
                        int zz = std::clamp(z + k, 0, depth - 1);
                        filteredValue += kernel[k + halfSize] * data[zz * width * height + y * width + x];
                    }
                    // std::cout << "Filtered value: " << filteredValue << std::endl;
                    result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
                }
            }
        }
    }

    data = std::move(result);
    std::cout << "1D filter applied in direction: " << direction << std::endl;
}


void Gaussian3DFilter::apply(Volume& volume) {
    std::cout << "Applying 3D Gaussian Filter with kernel size: " << kernelSize << std::endl;
    
    // Calculate sigma from kernelSize, for example, sigma = kernelSize / 6.0;
    double sigma = kernelSize;

    int width, height, depth;
    volume.getDimensions(width, height, depth);

    // Generate the 1D Gaussian kernel using the locally calculated sigma
    auto kernel = createGaussianKernel(sigma, kernelSize);

    // Retrieve volume data
    std::vector<unsigned char> data = volume.getData();

    // Apply the 1D Gaussian filter along each dimension
    applyFilter1D(kernel, data, width, height, depth, 'x');
    applyFilter1D(kernel, data, width, height, depth, 'y');
    applyFilter1D(kernel, data, width, height, depth, 'z');

    // Update the volume data
    volume.setData(data);
    
    std::cout << "Gaussian filter applied successfully." << std::endl;
}


void Median3DFilter::apply(Volume& volume) {
    // Placeholder for the 3D Median filter algorithm
    std::cout << "Applying 3D Median Filter with kernel size: " << kernelSize << std::endl;
    // Actual filtering logic goes here
}