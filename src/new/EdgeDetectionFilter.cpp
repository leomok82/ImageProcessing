#include "EdgeDetectionFilter.h"
#include <iostream>

std::unique_ptr<Filter> EdgeDetectionFilter::create(int type) {
    switch (type) {
        case 1:
            return std::make_unique<SobelFilter>();
        case 2:
            return std::make_unique<PrewittFilter>();
        case 3:
            return std::make_unique<ScharrFilter>();
        default:
            std::cerr << "Unknown edge detection filter type." << std::endl;
            return nullptr;
    }
}

void SobelFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Sobel edge detection logic
    std::cout << "Applying Sobel Edge Detection Filter" << std::endl;
    // Actual implementation would go here
}

void PrewittFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Prewitt Edge Detection Filter" << std::endl;
    // Prewitt edge detection logic
    // Actual implementation would go here
}

void ScharrFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Scharr Edge Detection Filter" << std::endl;
    // Scharr edge detection logic
    // Actual implementation would go here
}
