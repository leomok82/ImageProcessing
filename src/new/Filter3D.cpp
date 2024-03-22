#include "Filter3D.h"
#include "Slice.h" // Make sure this includes the definition of the Slice class
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // For std::min and std::max
#include "stb_image_write.h" // Needed for saving slices if using stb_image_write in Slice
#include "Filter3D.h"
#include "Utils.h" // Make sure this includes the QuickSelect and related functions
#include <vector>
#include <iostream>
#include <algorithm>



// std::vector<double> createGaussianKernel(double sigma, int kernelSize) {
//     int halfSize = kernelSize / 2;
//     std::vector<double> kernel(kernelSize);
//     double sum = 0.0;
//     for (int i = -halfSize; i <= halfSize; ++i) {
//         kernel[i + halfSize] = exp(-0.5 * (i * i) / (sigma * sigma)) / (sqrt(2 * M_PI) * sigma);
//         sum += kernel[i + halfSize];
//     }
//     // Normalize the kernel
//     for (auto &value : kernel) {
//         value /= sum;
//     }
//     return kernel;
// }



// void applyFilter1D(const std::vector<double>& kernel, std::vector<unsigned char>& data, int width, int height, int depth, char direction) {
//     std::vector<unsigned char> result(data.size());
//     int halfSize = kernel.size() / 2;

//     std::cout << "Applying 1D filter in direction: " << direction << std::endl;

//     if (direction == 'x') {
//         for (int z = 0; z < depth; ++z) {
//             for (int y = 0; y < height; ++y) {
//                 for (int x = 0; x < width; ++x) {
//                     double filteredValue = 0.0;
//                     for (int k = -halfSize; k <= halfSize; ++k) {
//                         int xx = std::clamp(x + k, 0, width - 1);
//                         filteredValue += kernel[k + halfSize] * data[z * width * height + y * width + xx];
//                     }
//                     // std::cout << "Filtered value: " << filteredValue << std::endl;
//                     result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
//                 }
//             }
//         }
//     } else if (direction == 'y') {
//         for (int z = 0; z < depth; ++z) {
//             for (int x = 0; x < width; ++x) {
//                 for (int y = 0; y < height; ++y) {
//                     double filteredValue = 0.0;
//                     for (int k = -halfSize; k <= halfSize; ++k) {
//                         int yy = std::clamp(y + k, 0, height - 1);
//                         filteredValue += kernel[k + halfSize] * data[z * width * height + yy * width + x];
//                     }
//                     // std::cout << "Filtered value: " << filteredValue << std::endl;
//                     result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
//                 }
//             }
//         }
//     } else if (direction == 'z') {
//         for (int y = 0; y < height; ++y) {
//             for (int x = 0; x < width; ++x) {
//                 for (int z = 0; z < depth; ++z) {
//                     double filteredValue = 0.0;
//                     for (int k = -halfSize; k <= halfSize; ++k) {
//                         int zz = std::clamp(z + k, 0, depth - 1);
//                         filteredValue += kernel[k + halfSize] * data[zz * width * height + y * width + x];
//                     }
//                     // std::cout << "Filtered value: " << filteredValue << std::endl;
//                     result[z * width * height + y * width + x] = std::clamp(static_cast<int>(filteredValue), 0, 255);
//                 }
//             }
//         }
//     }

//     data = std::move(result);
//     std::cout << "1D filter applied in direction: " << direction << std::endl;
// }



// void Gaussian3DFilter::apply(Volume& volume) {
//     std::cout << "Applying 3D Gaussian Filter with kernel size: " << kernelSize << std::endl;
    
//     // Calculate sigma from kernelSize, for example, sigma = kernelSize / 6.0;
//     double sigma = 30;

//     int width, height, depth;
//     volume.getDimensions(width, height, depth);

//     // Generate the 1D Gaussian kernel using the locally calculated sigma
//     auto kernel = createGaussianKernel(sigma, kernelSize);

//     // Retrieve volume data
//     std::vector<unsigned char> data = volume.getData();

//     // Apply the 1D Gaussian filter along each dimension
//     applyFilter1D(kernel, data, width, height, depth, 'x');
//     applyFilter1D(kernel, data, width, height, depth, 'y');
//     applyFilter1D(kernel, data, width, height, depth, 'z');

//     // Update the volume data
//     volume.setData(data);
    
//     std::cout << "Gaussian filter applied successfully." << std::endl;
// }

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

void applyGaussianFilter3D(const std::vector<std::vector<std::vector<double>>>& kernel, std::vector<unsigned char>& data, int width, int height, int depth) {
    std::vector<unsigned char> result(data.size());
    int kernelSize = kernel.size();
    int range = kernelSize / 2;

    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                double filteredValue = 0.0;

                // Apply the kernel centered at (x, y, z)
                for (int kz = -range; kz <= range; ++kz) {
                    for (int ky = -range; ky <= range; ++ky) {
                        for (int kx = -range; kx <= range; ++kx) {
                            // Compute the source voxel coordinates
                            int sx = std::clamp(x + kx, 0, width - 1);
                            int sy = std::clamp(y + ky, 0, height - 1);
                            int sz = std::clamp(z + kz, 0, depth - 1);

                            filteredValue += kernel[kx + range][ky + range][kz + range] * data[sz * width * height + sy * width + sx];
                        }
                    }
                }

                // Clamp the result and write to the output
                result[z * width * height + y * width + x] = std::clamp(static_cast<int>(std::round(filteredValue)), 0, 255);
            }
        }
    }

    data = std::move(result);
}

void Gaussian3DFilter::apply(Volume& volume) {
    std::cout << "Applying 3D Gaussian Filter with kernel size: " << kernelSize << std::endl;

    int width, height, depth;
    volume.getDimensions(width, height, depth);

    double sigma = 2.0;

    // ask user for sigma value and then set it to that
    std::cout << "Enter the sigma value: ";
    std::cin >> sigma;

    auto kernel = createGaussianKernel(kernelSize, sigma);

    std::vector<unsigned char> data = volume.getData();

    applyGaussianFilter3D(kernel, data, width, height, depth);

    volume.setData(data);

    std::cout << "3D Gaussian filter applied successfully." << std::endl;
}

void Median3DFilter::apply(Volume& volume) {
    std::cout << "Applying 3D Median Filter with kernel size: " << kernelSize << std::endl;

    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> originalData = volume.getData();
    std::vector<unsigned char> resultData = originalData; // Initialize the result data with the original data

    int range = kernelSize / 2;
    std::vector<unsigned char> neighborhood; // This will hold the neighborhood voxels

    for (int z = 0; z < depth; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                neighborhood.clear();

                // Collect the neighborhood voxels
                for (int kz = -range; kz <= range; ++kz) {
                    for (int ky = -range; ky <= range; ++ky) {
                        for (int kx = -range; kx <= range; ++kx) {
                            int nx = std::clamp(x + kx, 0, width - 1);
                            int ny = std::clamp(y + ky, 0, height - 1);
                            int nz = std::clamp(z + kz, 0, depth - 1);

                            neighborhood.push_back(originalData[nz * width * height + ny * width + nx]);
                        }
                    }
                }

                // Use QuickSelect to find the median in the neighborhood
                int medianIndex = neighborhood.size() / 2;
                unsigned char medianValue = quickSelect(neighborhood, 0, neighborhood.size() - 1, medianIndex + 1);

                // Update the voxel value in the result data
                resultData[z * width * height + y * width + x] = medianValue;
            }
        }
    }

    volume.setData(resultData);

    std::cout << "3D Median filter applied successfully." << std::endl;
}
