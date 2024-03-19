#include "ImageBlurFilter.h"
#include <iostream>

std::unique_ptr<Filter> ImageBlurFilter::create(int type, int kernelSize)
{
    switch (type)
    {
    case 1:
        return std::make_unique<MedianBlurFilter>(kernelSize);

    default:
        std::cerr << "Unknown image blur filter type." << std::endl;
        return nullptr;
    }
}

// std::unique_ptr<Filter> ImageBlurFilter::create(int type) {
//     switch (type) {
//         case 1:
//             return std::make_unique<MedianBlurFilter>();
//         case 2:
//             return std::make_unique<BoxBlurFilter>();
//         case 3:
//             return std::make_unique<GaussianBlurFilter>();
//         default:
//             std::cerr << "Unknown image blur filter type." << std::endl;
//             return nullptr;
//     }
// }

void MedianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Median blur logic

    std::cout << "Applying Median Blur Filter" << std::endl;

    int halfKernel = 5 / 2;

    for (int y = halfKernel; y < height - halfKernel; ++y) {
        for (int x = halfKernel; x < width - halfKernel; ++x) {
            for (int c = 0; c < channels; ++c) {
                std::vector<unsigned char> values;
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                        int nx = x + kx;
                        int ny = y + ky;
                        int i = (ny * width + nx) * channels + c;
                        values.push_back(data[i]); 
                    }
                }

                std::sort(values.begin(), values.end());

                int medianIndex = values.size() / 2;
                int i = (y * width + x) * channels + c;
                data[i] = values[medianIndex];
                }
            }
        }
}


void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Box Blur Filter" << std::endl;

    int halfKernel = 5 / 2; // Calculate half of the kernel size

    // Initialize the initial sum and count for the window
    int windowSum = 0;
    int windowCount = 0;

    // Initialize the sum and count for the first row of the window
    for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
        for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
            int nx = kx;
            int ny = ky;
            int i = (ny * width + nx) * channels;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                windowSum += data[i];
                ++windowCount;
            }
        }
    }

    // Slide the window and apply the blur filter
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                // Set the current pixel value to the average value of the window
                int i = (y * width + x) * channels + c;
                data[i] = static_cast<unsigned char>(windowSum / windowCount);

                // Update the window sum and count to adapt to the next window
                if (x < width - 1) {  // If not the rightmost pixel, slide the window to the right
                    for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                        int nx = x + halfKernel + 1;
                        int ny = y + ky;
                        int i = (ny * width + nx) * channels;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            windowSum += data[i];
                        }
                    }
                    for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                        int nx = x - halfKernel;
                        int ny = y + ky;
                        int i = (ny * width + nx) * channels;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            windowSum -= data[i];
                        }
                    }
                } else {  // If the rightmost pixel, reset the window to continue sliding down
                    windowSum = 0;
                    for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                        for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                            int nx = kx;
                            int ny = y + ky + 1;
                            int i = (ny * width + nx) * channels;
                            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                                windowSum += data[i];
                            }
                        }
                    }
                }
            }
        }
    }
}


void GaussianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Gaussian blur logic
    std::cout << "Applying Gaussian Blur Filter" << std::endl;

    int kernelSize = 7;
    double sigma = 1.0;

    // Compute Gaussian kernel
    std::vector<std::vector<double>> kernel(kernelSize, std::vector<double>(kernelSize));
    double kernelSum = 0.0;
    int halfKernel = kernelSize / 2;
    for (int i = -halfKernel; i <= halfKernel; ++i) {
        for (int j = -halfKernel; j <= halfKernel; ++j) {
            double weight = std::exp(-(i * i + j * j) / (2 * sigma * sigma));
            kernel[i + halfKernel][j + halfKernel] = weight;
            kernelSum += weight;
        }
    }

    // Normalize the kernel
    for (int i = 0; i < kernelSize; ++i) {
        for (int j = 0; j < kernelSize; ++j) {
            kernel[i][j] /= kernelSum;
        }
    }

    // Apply Gaussian blur
    for (int y = halfKernel; y < height - halfKernel; ++y) {
        for (int x = halfKernel; x < width - halfKernel; ++x) {
            for (int c = 0; c < channels; ++c) {
                double blurredValue = 0.0;
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                        int nx = x + kx;
                        int ny = y + ky;
                        int i = (ny * width + nx) * channels + c;
                        double weight = kernel[ky + halfKernel][kx + halfKernel];
                        blurredValue += data[i] * weight;
                    }
                }
                int i = (y * width + x) * channels + c;
                data[i] = static_cast<unsigned char>(blurredValue);
            }
        }
    }
}
