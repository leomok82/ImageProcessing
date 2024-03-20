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
        Image image(path);

        int width, height, channels;
        image.getDimensions(width, height, channels);

        unsigned char* data = image.getData();

        // Ask user for the filter type
        std::cout << "Select the type of filter for 2D image processing:" << std::endl;
        std::cout << "1. Colour Correction" << std::endl;
        std::cout << "2. Image Blur" << std::endl;
        std::cout << "3. Edge Detection" << std::endl;

        int filterType;
        std::cin >> filterType;

        FilterInputHandler::applyFilter(filterType, data, width, height, channels);

        // Save the modified image
        std::string outputPath;
        std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
        std::cin >> outputPath;

        // Assuming Image class has a save method
        image.save(outputPath); // Adjust if your actual method for saving images differs

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

        FilterInputHandler3D::applyFilter(filterType, volume); // Modify applyFilter to accept outputPath

        // Prompt for saving the modified image
        std::string outputPath;
        std::cout << "Enter the output folder path for the slices: ";
        std::cin >> outputPath; // Use this for saving slices

        // Ensure the folder exists, or create it
        std::filesystem::create_directories(outputPath);

        // Apply the filter as before
        // FilterInputHandler3D::applyFilter(filterType, volume); // Modify applyFilter to accept outputPath

        volume.saveSlices(outputPath);

    } else {
        std::cerr << "Invalid operation type selected." << std::endl;
    }

    return 0;
}

// Simple testing: Function to calculate the number of pixels in an image 
// int calculateImagePixels(const char *filename)
// {
//     int width, height, channels;

//     // Use stb_image.h to read the image
//     unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
//     if (img == nullptr)
//     {
//         std::cerr << "Error in loading the image" << std::endl;
//         return -1; // Return -1 if loading fails
//     }

//     int totalPixels = width * height; // Calculate total pixels
//     std::cout << "Image Width x Height: " << width << " x " << height << std::endl;
//     std::cout << "Total Pixels: " << totalPixels << std::endl;
//     std::cout << "Channels: " << channels << std::endl;

//     // Free the memory allocated for the image
//     stbi_image_free(img);

//     return totalPixels;
// }

// int main()
// {
//     const char *filename = "/Users/tz2523/GP3_Yen/now_processiing/advanced-programming-group-yen/src/new/graceNoise_MedianBlur.png";
//     calculateImagePixels(filename);

//     const char *test = "/Users/tz2523/GP3_Yen/now_processiing/advanced-programming-group-yen/output_noise.png";
//     calculateImagePixels(test);
//     return 0;
// }
