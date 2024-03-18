#include <iostream>
#include <string>
#include "Image.h"
#include "Volume.h"
#include "FilterInputHandler.h"
#include "FilterInputHandler3D.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    std::string path;
    std::cout << "Enter the path to the image or folder containing data volume: ";
    std::cin >> path;

    std::cout << "Select the type of operation:" << std::endl;
    std::cout << "1. 2D image processing" << std::endl;
    std::cout << "2. 3D data volume processing" << std::endl;

    int operationType;
    std::cin >> operationType;

    if (operationType == 1) {
        // Load the 2D image
        Image image(path); // This assumes your Image constructor handles loading

        // Since Image does not expose its data, assume it has methods to get dimensions and pixel data
        int width, height, channels;
        image.getDimensions(width, height, channels); // Adjust if your actual method differs

        unsigned char* data = image.getData(); // Assuming there's a method to get the image data

        // Ask user for the filter type
        std::cout << "Select the type of filter for 2D image processing:" << std::endl;
        std::cout << "1. Colour Correction" << std::endl;
        std::cout << "2. Image Blur" << std::endl;
        std::cout << "3. Edge Detection" << std::endl;

        int filterType;
        std::cin >> filterType;

        // Apply the selected filter
        FilterInputHandler::applyFilter(filterType, data, width, height, channels);

        // Save the modified image
        std::string outputPath;
        std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
        std::cin >> outputPath;

        // Assuming Image class has a save method
        image.save(outputPath); // Adjust if your actual method for saving images differs
        
        // stbi_image_free(data);

    } else if (operationType == 2) {
        Volume volume;
        if (!volume.loadFromFolder(path)) {
            std::cerr << "Failed to load 3D volume data." << std::endl;
            return -1;
        }
        std::cout << "3D data volume loaded successfully!" << std::endl;

        int width, height, depth;
        volume.getDimensions(width, height, depth);
        std::cout << "Volume Dimensions - Width: " << width << ", Height: " << height << ", Depth: " << depth << std::endl;

        // Filter Application
        std::cout << "Select the type of 3D filter to apply:" << std::endl;
        std::cout << "1. 3D Gaussian Filter" << std::endl;
        std::cout << "2. 3D Median Filter" << std::endl;
        int filterType;
        std::cin >> filterType;

        FilterInputHandler3D::applyFilter(filterType, volume);

        // Prompt for saving the modified image
        std::string outputPath;
        std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
        std::cin >> outputPath;

    } else {
        std::cerr << "Invalid operation type selected." << std::endl;
    }

    return 0;
}