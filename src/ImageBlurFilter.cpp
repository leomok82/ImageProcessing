/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#include "ImageBlurFilter.h"
#include <iostream>

std::unique_ptr<Filter> ImageBlurFilter::create(int type, int kernelSize) {

    switch (type) {
    case 1:
        return std::make_unique<MedianBlurFilter>(kernelSize);
    case 2:
        return std::make_unique<BoxBlurFilter>(kernelSize);
    // case 3:
    //     std::cout << "Now you are in the GaussianBlurFilter create function" << std::endl;
    //     return std::make_unique<GaussianBlurFilter>(kernelSize);
    default:
        std::cerr << "Unknown image blur filter type." << std::endl;
        return nullptr;
    }
}

std::unique_ptr<Filter> ImageBlurFilter::create(int type, int kernelSize, double sigma) {
    if (type == 3)
    { // Gaussian
        std::cout << "Now you are in the GaussianBlurFilter create function with sigma" << std::endl;
        return std::make_unique<GaussianBlurFilter>(kernelSize, sigma);
    }
    else
    {
        std::cerr << "Sigma parameter is only applicable for GaussianBlurFilter." << std::endl;
        return nullptr;
    }
}

void MedianBlurFilter::apply(unsigned char *data, int width, int height, int channels)
{
    std::cout << "Applying Median Blur Filter." << std::endl;

    // Prepare vector for output image data
    std::vector<unsigned char> output(width * height * channels);
    int halfKernel = kernelSize / 2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                std::vector<unsigned char> neighborhood;

                // Build neighborhood, considering mirrored boundary
                for (int dy = -halfKernel; dy <= halfKernel; ++dy) {
                    for (int dx = -halfKernel; dx <= halfKernel; ++dx)
                    {
                        int nx = x + dx;
                        int ny = y + dy;

                        if (nx < 0)
                            nx = -nx - 1;
                        else if (nx >= width)
                            nx = width - (nx - width + 1);

                        if (ny < 0)
                            ny = -ny - 1;
                        else if (ny >= height)
                            ny = height - (ny - height + 1);

                        neighborhood.push_back(data[(ny * width + nx) * channels + c]);
                    }
                }

                unsigned char median = quickSelect(neighborhood, 0, neighborhood.size() - 1, neighborhood.size() / 2 + 1);
                output[(y * width + x) * channels + c] = median;
            }
        }
    }

    // Copy the processed data back to the original data array
    std::copy(output.begin(), output.end(), data);
}

void BoxBlurFilter::apply(unsigned char *data, int width, int height, int channels) {
    std::cout << "Applying Box Blur Filter" << std::endl;

    int halfKernel = kernelSize / 2;

    // Slide window and apply blur filter
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                int windowSum = 0;
                int windowCount = 0;

                // Calculate the sum and count of pixels within the window
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                        int nx = x + kx;
                        int ny = y + ky;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            int i = (ny * width + nx) * channels + c;
                            windowSum += data[i]; // Add the pixel value to the window sum
                            ++windowCount;        // Increase the count of pixels in the window
                        }
                    }
                }

                // Calculate the average pixel value in the window and set the current pixel to this average
                int i = (y * width + x) * channels + c;
                if (windowCount > 0) {
                    data[i] = static_cast<unsigned char>(windowSum / windowCount);
                } else {
                    data[i] = 0; // Handle pixels outside the boundary
                }
            }
        }
    }
}

void GaussianBlurFilter::apply(unsigned char *data, int width, int height, int channels) {
    std::cout << "Applying Gaussian Blur Filter" << std::endl;
    std::vector<double> weights(kernelSize);
    calculateGaussianWeights(sigma, kernelSize, weights);

    std::vector<unsigned char> temp(width * height * channels);
    applyGaussianBlurOnRow(data, width, height, channels, weights, temp.data());
    applyGaussianBlurOnColumn(temp.data(), width, height, channels, weights, data);
}

void GaussianBlurFilter::calculateGaussianWeights(double sigma, int kernelSize, std::vector<double> &weights) {
    double sum = 0.0;
    int halfSize = kernelSize / 2;
    for (int i = -halfSize; i <= halfSize; ++i) {
        weights[i + halfSize] = exp(-(i * i) / (2 * sigma * sigma));
        sum += weights[i + halfSize];
    }
    for (double &weight : weights) {
        weight /= sum;
    }
}

int GaussianBlurFilter::mirrorIndex(int index, int maxIndex) {
    if (index < 0)
        return -index - 1;
    if (index > maxIndex)
        return maxIndex - (index - maxIndex) + 1;
    return index;
}

void GaussianBlurFilter::applyGaussianBlurOnRow(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output) {
    int halfSize = kernelSize / 2;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                double sum = 0.0;
                for (int k = -halfSize; k <= halfSize; ++k) {
                    int nx = mirrorIndex(x + k, width - 1);
                    sum += data[(y * width + nx) * channels + c] * weights[k + halfSize];
                }
                output[(y * width + x) * channels + c] = static_cast<unsigned char>(std::max(0.0, std::min(255.0, sum)));
            }
        }
    }
}

void GaussianBlurFilter::applyGaussianBlurOnColumn(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output){
    int halfSize = kernelSize / 2;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int c = 0; c < channels; ++c) {
                double sum = 0.0;
                for (int k = -halfSize; k <= halfSize; ++k) {
                    int ny = mirrorIndex(y + k, height - 1);
                    sum += data[(ny * width + x) * channels + c] * weights[k + halfSize];
                }
                output[(y * width + x) * channels + c] = static_cast<unsigned char>(std::max(0.0, std::min(255.0, sum)));
            }
        }
    }
}
