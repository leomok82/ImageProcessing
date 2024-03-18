#include "ImageBlurFilter.h"
#include <iostream>

std::unique_ptr<Filter> ImageBlurFilter::create(int type) {
    switch (type) {
        case 1:
            return std::make_unique<MedianBlurFilter>();
        case 2:
            return std::make_unique<BoxBlurFilter>();
        case 3:
            return std::make_unique<GaussianBlurFilter>();
        default:
            std::cerr << "Unknown image blur filter type." << std::endl;
            return nullptr;
    }
}

void MedianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Median blur logic
    std::cout << "Applying Median Blur Filter" << std::endl;
    // Actual implementation would go here
}

void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Box Blur Filter" << std::endl;
    // Box blur logic
    // Actual implementation would go here
}

void GaussianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Gaussian Blur Filter" << std::endl;
    // Gaussian blur logic
    // Actual implementation would go here
}
