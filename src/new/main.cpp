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
#include "SliceInputHandler.h"
#include "ProjectionInputHandler.h"

// int main() {
//     std::string path;
//     std::cout << "Enter the path to the image or folder containing data volume: ";
//     std::cin >> path;

//     while (true) {
//         std::cout << "Select the type of operation:" << std::endl;
//         std::cout << "1. 2D image processing" << std::endl;
//         std::cout << "2. 3D data volume processing" << std::endl;
//         std::cout << "3. Exit" << std::endl;

//         int operationType;
//         std::cin >> operationType;

//         if (operationType == 1) {
//             Image image(path);
//             if (!image.isValidImage()) {
//                 std::cerr << "Error loading the image. Please ensure the path is correct and refers to an image file." << std::endl;
//                 continue; // Skip the rest of the loop and prompt the user again
//             }
//             while (true) {
//                 int width, height, channels;
//                 image.getDimensions(width, height, channels);
//                 unsigned char* data = image.getData();
                
//                 FilterInputHandler::applyFilter(data, width, height, channels);
                
//                 std::string continueFiltering;
//                 std::cout << "Apply another filter? (y/n): ";
//                 std::cin >> continueFiltering;
//                 if (continueFiltering != "y") {
//                     std::string outputPath;
//                     std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
//                     std::cin >> outputPath;
//                     image.save(outputPath);
//                     break;
//                 }
//             }
//         } else if (operationType == 2) {
//             Volume volume;
//             if (!volume.loadFromFolder(path)) {
//                 std::cerr << "Failed to load 3D volume data." << std::endl;
//                 continue;
//             }
//             std::cout << "3D data volume loaded successfully!" << std::endl;

//             int width, height, depth;
//             volume.getDimensions(width, height, depth);
//             if (!(width > 0 && height > 0 && depth > 0)) {
//                 std::cerr << "Invalid volume dimensions." << std::endl;
//                 return -1;
//             }

//             while (true) {
//                 std::cout << "Select next action:" << std::endl;
//                 std::cout << "1. Apply 3D filter" << std::endl;
//                 std::cout << "2. Slice volume" << std::endl;
//                 std::cout << "3. Apply projection" << std::endl;
//                 std::cout << "4. Finish processing" << std::endl;

//                 int action;
//                 std::cin >> action;

//                 if (action == 1) {
//                     FilterInputHandler3D::applyFilter(volume);
//                 } else if (action == 2 || action == 3) {
//                     if (action == 2) {
//                         SliceInputHandler::applySlice(volume, width, height, depth);
//                     } else {
//                         std::vector<unsigned char> output = ProjectionInputHandler::applyProjection(volume);
//                         std::string outputPath;
//                         std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
//                         std::cin >> outputPath;     
//                         unsigned char* outputData = output.data();
//                         stbi_write_png(outputPath.c_str(), width, height, 3, outputData, width * 3);
//                     }

//                 } else if (action == 4) {
//                     break; // Exit the 3D processing loop
//                 } else {
//                     std::cout << "Invalid action." << std::endl;
//                 }
//             }

//         } else if (operationType == 3) {
//             break; // Exit the main loop
//         } else {
//             std::cout << "Invalid operation type selected." << std::endl;
//         }
//     }

//     return 0;
// }
