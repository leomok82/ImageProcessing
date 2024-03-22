#include "FilterInputHandler.h"
#include "ColourFilterCorrection.h"
#include "ImageBlurFilter.h"
#include "EdgeDetectionFilter.h"
#include <memory>
#include <iostream>


void FilterInputHandler::applyFilter(unsigned char* data, int width, int height, int channels) {
    std::unique_ptr<Filter> filter;

    // Ask user for the filter type
    std::cout << "Select the type of filter for 2D image processing:" << std::endl;
    std::cout << "1. Colour Correction" << std::endl;
    std::cout << "2. Image Blur" << std::endl;
    std::cout << "3. Edge Detection" << std::endl;

    int filterType;
    std::cin >> filterType;

    switch (filterType) {
        case 1: {
            // Colour Correction
            int correctionType;
            std::cout << "Select Colour Correction Type:" << std::endl;
            std::cout << "1. Grayscale" << std::endl;
            std::cout << "2. Brightness" << std::endl;
            std::cout << "3. Histogram Equalisation" << std::endl;
            std::cout << "4. Thresholding" << std::endl;
            std::cout << "5. Salt and Pepper Noise" << std::endl;

            std::cin >> correctionType;

            filter = ColourCorrectionFilter::create(correctionType);
            break;
        }
        case 2: {
            // Image Blur
            int blurType;
            int kernelSize;
            double sigma = 2.0;

            std::cout << "Select Blur Type:" << std::endl;
            std::cout << "1. Median" << std::endl;
            std::cout << "2. Box" << std::endl;
            std::cout << "3. Gaussian" << std::endl;

            // Loop until a valid blur type is entered
            while (true) {
                std::cin >> blurType;
                if (std::cin.fail() || blurType < 1 || blurType > 3) {
                    std::cin.clear();                                                   // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore characters after wrong input
                    std::cout << "Invalid blur type. Please enter 1 for Median, 2 for Box, or 3 for Gaussian:" << std::endl;
                }
                else
                {
                    break;
                }
            }

            std::cout << "Select kernel size (odd number, e.g., 3 for 3x3):" << std::endl;
            // Loop until a valid kernel size is entered
            while (true) {
                std::cin >> kernelSize;
                if (std::cin.fail() || kernelSize % 2 == 0) {
                    std::cin.clear();                                                   // Clear error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore characters after wrong input
                    std::cout << "Invalid kernel size. Please enter an odd number:" << std::endl;
                } else {
                    break;
                }
            }

            if (blurType == 3) { // Gaussian
                std::cout << "Enter sigma value (positive number):" << std::endl;
                // Loop until a valid sigma value is entered
                while (true) {
                    std::cin >> sigma;
                    if (std::cin.fail() || sigma <= 0.0) {
                        std::cin.clear();                                                   
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Invalid sigma value. Please enter a positive number:" << std::endl;
                    } else {
                        break;
                    }
                }
                filter = ImageBlurFilter::create(blurType, kernelSize, sigma);
            } else {
                filter = ImageBlurFilter::create(blurType, kernelSize);
            }
            break;
        }

        case 3: {
            // Edge Detection
            bool temp = true;
            while (temp == true) {
                int edgeType;
                std::cout << "Select Edge Detection Type:" << std::endl;
                std::cout << "1. Sobel" << std::endl;
                std::cout << "2. Prewitt" << std::endl;
                std::cout << "3. Scharr" << std::endl;
                std::cout << "4. Robert's Cross" << std::endl;
                std::cout << "5. End" << std::endl;
                std::cin >> edgeType;

                if (edgeType > 0 && edgeType < 5) {
                    filter = EdgeDetectionFilter::create(edgeType);
                } else {
                    break;    
                }
            }
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
