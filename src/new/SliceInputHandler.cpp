#include "SliceInputHandler.h"
#include <iostream>
#include <filesystem>

void SliceInputHandler::applySlice(const Volume& volume, int width, int height, int depth) {
    std::cout << "Select the axis to slice along:" << std::endl;
    std::cout << "1. X-axis (creating Y-Z plane slices)" << std::endl; // Clarified for user understanding
    std::cout << "2. Y-axis (creating X-Z plane slices)" << std::endl; // Clarified for user understanding
    std::cout << "3. Z-axis (creating X-Y plane slices)" << std::endl; // Clarified for user understanding
    int axis;
    std::cin >> axis;

    std::string plane;
    switch (axis) {
        case 1: plane = "yz"; break;
        case 2: plane = "xz"; break;
        case 3: plane = "xy"; break;
        default:
            std::cerr << "Invalid axis selected. Please select 1, 2, or 3." << std::endl;
            return;
    }

    int sliceNumber;
    std::cout << "Enter the slice number (coordinate indices start from 1): ";
    std::cin >> sliceNumber;

    // Validate the slice number based on the chosen plane
    bool isValidSlice = true;

    if ((plane == "yz" && (sliceNumber < 1 || sliceNumber > width)) ||
        (plane == "xz" && (sliceNumber < 1 || sliceNumber > height)) ||
        (plane == "xy" && (sliceNumber < 1 || sliceNumber > depth))) {
        std::cerr << "Invalid slice number for the selected axis." << std::endl;
        isValidSlice = false;
    }

    if (isValidSlice) {
        // Create a slice
        Slice slice = Slice::fromVolume(volume, plane, sliceNumber);
        std::string saveOption;
        std::cout << "Do you want to save slices? (y/n): ";
        std::cin >> saveOption;
        if (saveOption == "y" || saveOption == "Y") {
            // Save the slice
            std::string outputPath;
            std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
            std::cin >> outputPath;
            slice.saveToFile(outputPath);
            std::cout << "Slice saved successfully to " << outputPath << std::endl;
        } 
    } else {
    std::cout << "Slice number not valid" << std::endl;
    }
}

// if (isValidSlice) {
//         // Create a slice
//         Slice slice = Slice::fromVolume(volume, plane, sliceNumber);

//         // Save the slice
//         std::string outputPath;
//         std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
//         std::cin >> outputPath;
//         slice.saveToFile(outputPath);
//         std::cout << "Slice saved successfully to " << outputPath << std::endl;
//     } else {
//         std::cout << "Slice number not valid" << std::endl;
//     }
