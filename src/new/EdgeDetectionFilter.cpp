#include "EdgeDetectionFilter.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

#include "EdgeDetectionFilter.h"

// Definition of the static create method
std::unique_ptr<Filter> EdgeDetectionFilter::create(int type) {
    switch (type) {
        case 1:
            return std::make_unique<SobelFilter>();
        case 2:
            return std::make_unique<PrewittFilter>();
        case 3:
            return std::make_unique<ScharrFilter>();
        // Add cases for additional filters as needed
        default:
            std::cerr << "Unknown edge detection filter type." << std::endl;
            return nullptr;
    }
}


// Helper function to set the kernel for a given filter type
void setKernel(int type, int (&gx)[3][3], int (&gy)[3][3], int& kernel_size) {
    switch (type) {
        case 1: // Sobel
            gx[0][0] = -1; gx[0][1] = 0; gx[0][2] = 1;
            gx[1][0] = -2; gx[1][1] = 0; gx[1][2] = 2;
            gx[2][0] = -1; gx[2][1] = 0; gx[2][2] = 1;

            gy[0][0] = -1; gy[0][1] = -2; gy[0][2] = -1;
            gy[1][0] = 0;  gy[1][1] = 0;  gy[1][2] = 0;
            gy[2][0] = 1;  gy[2][1] = 2;  gy[2][2] = 1;
            kernel_size = 3;
            break;
        case 2: // Prewitt
            std::fill_n(&gx[0][0], 9, 1); // Set all elements to 1
            std::fill_n(&gy[0][0], 9, 1); // Set all elements to 1
            gx[1][0] = gx[1][2] = gy[0][1] = gy[2][1] = 0;
            gx[0][0] = gx[2][2] = gy[0][0] = gy[2][2] = -1;
            gx[0][2] = gx[2][0] = gy[0][2] = gy[2][0] = 1;
            kernel_size = 3;
            break;
        case 3: // Scharr
            gx[0][0] = -3; gx[0][1] = 0; gx[0][2] = 3;
            gx[1][0] = -10;gx[1][1] = 0; gx[1][2] = 10;
            gx[2][0] = -3; gx[2][1] = 0; gx[2][2] = 3;

            gy[0][0] = -3; gy[0][1] = -10;gy[0][2] = -3;
            gy[1][0] = 0;  gy[1][1] = 0;  gy[1][2] = 0;
            gy[2][0] = 3;  gy[2][1] = 10; gy[2][2] = 3;
            kernel_size = 3;
            break;
        // Add more cases for additional filters...
        default:
            std::cerr << "Invalid edge detection type provided." << std::endl;
            return;
    }
}

// Common apply function for edge detection
void applyEdgeDetectionFilter(unsigned char* data, int width, int height, int channels, int gx[3][3], int gy[3][3], int kernel_size) {
    if (channels < 3) {
        std::cerr << "Edge detection requires an image with at least 3 channels (RGB)." << std::endl;
        return;
    }

    // Convert image to grayscale
    std::vector<float> grayscale(width * height, 0.0f);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = data + (y * width + x) * channels;
            grayscale[y * width + x] = 0.2126f * pixel[0] + 0.7152f * pixel[1] + 0.0722f * pixel[2];
        }
    }

    // Buffer for edge image
    std::vector<float> edges(width * height, 0.0f);

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            float sumX = 0.0f, sumY = 0.0f;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    sumX += gx[ky + 1][kx + 1] * grayscale[(y + ky) * width + (x + kx)];
                    sumY += gy[ky + 1][kx + 1] * grayscale[(y + ky) * width + (x + kx)];
                }
            }
            edges[y * width + x] = std::sqrt(sumX * sumX + sumY * sumY);
        }
    }

    // Normalize and copy back
    float maxVal = *std::max_element(edges.begin(), edges.end());
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char edgeVal = static_cast<unsigned char>((edges[y * width + x] / maxVal) * 255);
            std::fill_n(&data[(y * width + x) * channels], channels, edgeVal);
        }
    }
}

// SobelFilter apply method
void SobelFilter::apply(unsigned char* data, int width, int height, int channels) {
    int gx[3][3], gy[3][3], kernel_size;
    setKernel(1, gx, gy, kernel_size); // Sobel
    applyEdgeDetectionFilter(data, width, height, channels, gx, gy, kernel_size);
}

// PrewittFilter apply method
void PrewittFilter::apply(unsigned char* data, int width, int height, int channels) {
    int gx[3][3], gy[3][3], kernel_size;
    setKernel(2, gx, gy, kernel_size); // Prewitt
    applyEdgeDetectionFilter(data, width, height, channels, gx, gy, kernel_size);
}

// ScharrFilter apply method
void ScharrFilter::apply(unsigned char* data, int width, int height, int channels) {
    int gx[3][3], gy[3][3], kernel_size;
    setKernel(3, gx, gy, kernel_size); // Scharr
    applyEdgeDetectionFilter(data, width, height, channels, gx, gy, kernel_size);
}
