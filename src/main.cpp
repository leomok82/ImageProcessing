#include <iostream>
#include <string>
#include <vector>
#include "Filter.h"
#include "BrightnessFilter.h"
#include "Options.h"
#include "SobelFilter.h"
// #include "Projection.h"
#include "GrayscaleFilter.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    std::string filepath;
    std::cout << "Enter the path to the image or data volume: ";
    std::cin >> filepath;

    // Attempt to load the image or data volume
    int width, height, channels;
    unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
    if (data == nullptr) {
        std::cerr << "Failed to load image. Please ensure the file path is correct." << std::endl;
        return -1;
    }

    std::cout << "Image loaded successfully!" << std::endl;
    std::cout << "Width: " << width << ", Height: " << height << ", Channels: " << channels << std::endl;

    // Display options for filters and projections
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Apply Grayscale Filter" << std::endl;
    std::cout << "2. Apply Brightness Filter" << std::endl;
    std::cout << "3. Apply Histogram Equalization" << std::endl;
    std::cout << "4. Apply Thresholding" << std::endl;
    std::cout << "5. Add Salt and Pepper Noise" << std::endl;
    std::cout << "6. Apply Blur" << std::endl;
    std::cout << "7. Apply Edge Detection" << std::endl;
    std::cout << "8. Exit" << std::endl;

    int option;
    std::cin >> option;

    switch (option) {
        case 1: 
        {
            GrayscaleFilter grayscaleFilter;
            grayscaleFilter.apply(data, width, height, channels);
            std::cout << "Grayscale filter applied." << std::endl;

            // Save the modified image
            std::string outputPath = "grayscale_output.png";
            if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
                std::cerr << "Failed to save the grayscale image." << std::endl;
            } else {
                std::cout << "Saved the grayscale image to " << outputPath << std::endl;
            }
        }
            break;

        case 2:
            int delta;
            std::cout << "Enter brightness adjustment value (-255 to 255): ";
            std::cin >> delta;

            {
                BrightnessFilter brightnessFilter(delta);
                brightnessFilter.apply(data, width, height, channels);
                std::cout << "Brightness filter applied." << std::endl;

                // Save the modified image
                std::string outputPath = "brightness_adjusted_output.png";
                if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
                    std::cerr << "Failed to save the brightness adjusted image." << std::endl;
                } else {
                    std::cout << "Saved the brightness adjusted image to " << outputPath << std::endl;
                }
            }
            break;

        case 3:
            // Apply Histogram Equalization
            
            break;
        case 4:
            // Apply Thresholding
            break;
        case 5:
            // Add Salt and Pepper Noise
            break;
        case 6:
            // Apply Blur
            break;
        case 7:
            {
                SobelFilter sobelFilter;
                sobelFilter.apply(data, width, height, channels);
                std::cout << "Sobel edge detection filter applied." << std::endl;

                // Save the modified image
                std::string outputPath = "sobel_output.png";
                if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
                    std::cerr << "Failed to save the Sobel filtered image." << std::endl;
                } else {
                    std::cout << "Saved the Sobel filtered image to " << outputPath << std::endl;
                }
            }
            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid option selected." << std::endl;
            break;
    }

    // Free the image data memory
    stbi_image_free(data);

    return 0;
}
