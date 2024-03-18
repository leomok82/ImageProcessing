#include "FilterInputHandler.h"
#include "ColourFilterCorrection.h"
#include "ImageBlurFilter.h"
#include "EdgeDetectionFilter.h"
#include <memory>
#include <iostream>

void FilterInputHandler::applyFilter(int filterType, unsigned char* data, int width, int height, int channels) {
    std::unique_ptr<Filter> filter;

    switch (filterType) {
        case 1: {
            // Colour Correction
            int correctionType;
            std::cout << "Select Colour Correction Type:" << std::endl;
            std::cout << "1. Grayscale" << std::endl;
            std::cout << "2. Brightness" << std::endl;
            std::cout << "3. Histogram Equalisation" << std::endl;
            std::cout << "5. Thresholding" << std::endl;
            std::cout << "5. Salt and Pepper Noise" << std::endl;

            std::cin >> correctionType;

            filter = ColourCorrectionFilter::create(correctionType);
            break;
        }
        case 2: {
            // Image Blur
            int blurType;
            std::cout << "Select Blur Type:" << std::endl;
            std::cout << "1. Median" << std::endl;
            std::cout << "2. Box" << std::endl;
            std::cout << "3. Gaussian" << std::endl;
            std::cin >> blurType;

            filter = ImageBlurFilter::create(blurType);
            break;
        }
        case 3: {
            // Edge Detection
            int edgeType;
            std::cout << "Select Edge Detection Type:" << std::endl;
            std::cout << "1. Sobel" << std::endl;
            std::cout << "2. Prewitt" << std::endl;
            std::cout << "3. Scharr" << std::endl;
            std::cin >> edgeType;

            filter = EdgeDetectionFilter::create(edgeType);
            break;
        }
        default:
            std::cerr << "Invalid filter type provided." << std::endl;
            return;
    }

    if (!filter) {
        std::cerr << "Failed to create filter." << std::endl;
        return;
    }

    // Apply the selected filter to the image
    filter->apply(data, width, height, channels);
}
