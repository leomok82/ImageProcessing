#include "SobelFilter.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>


SobelFilter::SobelFilter() {}

SobelFilter::~SobelFilter() {}

void SobelFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Only apply the filter on the grayscale version of the image
    if (channels < 3) {
        std::cerr << "Sobel filter requires an image with at least 3 channels (RGB)." << std::endl;
        return;
    }

    // Create a buffer for the grayscale version of the image
    std::vector<float> grayscale(width * height, 0);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = data + (y * width + x) * channels;
            grayscale[y * width + x] = 0.2126f * pixel[0] + 0.7152f * pixel[1] + 0.0722f * pixel[2];
        }
    }

    // Sobel operator kernels
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Buffer to store the edge image
    std::vector<float> edges(width * height, 0);

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            float sumX = 0.0f;
            float sumY = 0.0f;
            // Apply the Sobel kernels
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    sumX += gx[ky + 1][kx + 1] * grayscale[(y + ky) * width + (x + kx)];
                    sumY += gy[ky + 1][kx + 1] * grayscale[(y + ky) * width + (x + kx)];
                }
            }
            // Calculate gradient magnitude
            edges[y * width + x] = std::sqrt(sumX * sumX + sumY * sumY);
        }
    }

    // Normalize the gradients to the full 8-bit scale
    float maxVal = *std::max_element(edges.begin(), edges.end());
    for (float &val : edges) {
        val = (val / maxVal) * 255.0f;
    }

    // Copy the edge data back into the original image
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Clamp the value and convert to unsigned char
            unsigned char edgeVal = static_cast<unsigned char>(
                std::max(0.0f, std::min(255.0f, edges[y * width + x]))
            );
            std::fill_n(&data[(y * width + x) * channels], channels, edgeVal);
        }
    }
}
