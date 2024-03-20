#include <iostream>
#include <string>
#include "Image.h"
#include "Volume.h"
#include "Slice.h"
#include "FilterInputHandler.h"
#include "FilterInputHandler3D.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "Projections.h"

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
        if (!(width > 0 && height > 0 && depth > 0)) 
        {
            std::cerr << "Invalid volume dimensions." << std::endl;
            return -1;
        }
        bool status = true;
        while (status ==true) 
        {
            std::cout << "Would you like to filter?" << std::endl;
            std::cout << "1. Yes" << std::endl;
            std::cout << "2. No" << std::endl;
            int boolFilter;
            std::cin >> boolFilter;
            if (boolFilter ==1)
            {
                // Filter Application
                std::cout << "Select the type of 3D filter to apply:" << std::endl;
                std::cout << "1. 3D Gaussian Filter" << std::endl;
                std::cout << "2. 3D Median Filter" << std::endl;
                int filterType;
                std::cin >> filterType;

                FilterInputHandler3D::applyFilter(filterType, volume); // Modify applyFilter to accept outputPath
                std::cout << "3D Filter applied successfully." << std::endl;
                std::cout << "Would you like to save the slices?" << std::endl;
                std::cout << "1. Yes" << std::endl;
                std::cout << "2. No" << std::endl;
                int saveSlices;
                std::cin >> saveSlices;
                if (saveSlices==1)
                {

                // Prompt for saving the modified image
                std::string outputPath;
                std::cout << "Enter the output folder path for the slices: ";
                std::cin >> outputPath; // Use this for saving slices

                
                // Ensure the folder exists, or create it
                std::filesystem::create_directories(outputPath);


                volume.saveSlices(outputPath);
                }
            }
            else
            {
                status = false;
            }
        }
        //Projection application
        std::cout << "Select the type of projection to apply:" << std::endl;
        std::cout << "1. Max IP" << std::endl;
        std::cout << "2. Min IP" << std::endl;
        std::cout << "3. Average IP" << std::endl;
        int projectionType;
        std::cin >> projectionType;
        if (projectionType < 1 || projectionType > 3)
        {
            std::cerr << "Invalid projection type selected." << std::endl;
        }
        // Get the range of slices for the projection
        int endSlice;
        int startSlice;

        
        std:: cout << "Enter the lower limit of slices for the projection: " << std::endl;
        
        std::cin >> startSlice;
        std:: cout << "Enter the upper limit of slices for the projection: " << std::endl;
        
        std::cin >> endSlice;

        // output vector
        std::vector<unsigned char> output;

        // Apply the selected projection
        switch (projectionType)
        {
            case 1:
                output = Projections::MIP(volume, startSlice, endSlice);
                break;
            case 2:
                output = Projections::MinIP(volume, startSlice, endSlice);
                break;
            case 3:
                output = Projections::AIP(volume, startSlice, endSlice);
                break;
            default:
                std::cerr << "Invalid projection type selected." << std::endl;
                break;
        }       
        std::string outputPath;
        std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
        std::cin >> outputPath;     
        unsigned char* outputData = output.data();
        stbi_write_png(outputPath.c_str(), width, height, 3, outputData, width * 3);
    
        

    } else {
        std::cerr << "Invalid operation type selected." << std::endl;
    }

    return 0;
}