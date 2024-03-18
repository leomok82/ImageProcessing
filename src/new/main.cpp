// #include <iostream>
// #include <string>
// #include "FilterInputHandler.h"
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "stb_image_write.h"

// int main() {
//     std::string filepath;
//     std::cout << "Enter the path to the image or data volume: ";
//     std::cin >> filepath;

//     // Attempt to load the image
//     int width, height, channels;
//     unsigned char* data = stbi_load(filepath.c_str(), &width, &height, &channels, 0);
//     if (data == nullptr) {
//         std::cerr << "Failed to load image. Please ensure the file path is correct." << std::endl;
//         return -1;
//     }

//     std::cout << "Image loaded successfully!" << std::endl;
//     std::cout << "Width: " << width << ", Height: " << height << ", Channels: " << channels << std::endl;

//     std::cout << "Select the type of operation:" << std::endl;
//     std::cout << "1. 2D image processing" << std::endl;
//     std::cout << "2. 3D data volume processing (Not Implemented)" << std::endl;

//     int operationType;
//     std::cin >> operationType;

//     if (operationType == 1) {
//         std::cout << "Select the type of filter for 2D image processing:" << std::endl;
//         std::cout << "1. Colour Correction" << std::endl;
//         std::cout << "2. Image Blur" << std::endl;
//         std::cout << "3. Edge Detection" << std::endl;

//         int filterType;
//         std::cin >> filterType;

//         // Delegate the application of the selected filter to the FilterInputHandler
//         FilterInputHandler::applyFilter(filterType, data, width, height, channels);

//         // Prompt for saving the modified image
//         std::string outputPath;
//         std::cout << "Enter the output file path (including extension, e.g., 'output.png'): ";
//         std::cin >> outputPath;

//         if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
//             std::cerr << "Failed to save the modified image." << std::endl;
//         } else {
//             std::cout << "Modified image saved to " << outputPath << std::endl;
//         }
//     } else if (operationType == 2) {
//         std::cout << "3D data volume processing is not implemented yet." << std::endl;
//     } else {
//         std::cerr << "Invalid operation type selected." << std::endl;
//     }

//     stbi_image_free(data);

//     return 0;
// }


//     switch (option) {
//         case 1: 
//         {
//             GrayscaleFilter grayscaleFilter;
//             grayscaleFilter.apply(data, width, height, channels);
//             std::cout << "Grayscale filter applied." << std::endl;

//             // Save the modified image
//             std::string outputPath = "grayscale_output.png";
//             if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
//                 std::cerr << "Failed to save the grayscale image." << std::endl;
//             } else {
//                 std::cout << "Saved the grayscale image to " << outputPath << std::endl;
//             }
//         }
//             break;

//         case 2:
//             int delta;
//             std::cout << "Enter brightness adjustment value (-255 to 255): ";
//             std::cin >> delta;

//             {
//                 BrightnessFilter brightnessFilter(delta);
//                 brightnessFilter.apply(data, width, height, channels);
//                 std::cout << "Brightness filter applied." << std::endl;

//                 // Save the modified image
//                 std::string outputPath = "brightness_adjusted_output.png";
//                 if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
//                     std::cerr << "Failed to save the brightness adjusted image." << std::endl;
//                 } else {
//                     std::cout << "Saved the brightness adjusted image to " << outputPath << std::endl;
//                 }
//             }
//             break;

//         case 3:
//             // Apply Histogram Equalization

//             break;
//         case 4:
//             // Apply Thresholding
//             break;
//         case 5:
//             // Add Salt and Pepper Noise
//             break;
//         case 6:
//             // Apply Blur
//             break;
//         case 7:
//             {
//                 SobelFilter sobelFilter;
//                 sobelFilter.apply(data, width, height, channels);
//                 std::cout << "Sobel edge detection filter applied." << std::endl;

//                 // Save the modified image
//                 std::string outputPath = "sobel_output.png";
//                 if (!stbi_write_png(outputPath.c_str(), width, height, channels, data, width * channels)) {
//                     std::cerr << "Failed to save the Sobel filtered image." << std::endl;
//                 } else {
//                     std::cout << "Saved the Sobel filtered image to " << outputPath << std::endl;
//                 }
//             }
//             break;
//         case 8:
//             std::cout << "Exiting program." << std::endl;
//             break;
//         default:
//             std::cout << "Invalid option selected." << std::endl;
//             break;
//     }

//     // Free the image data memory
//     stbi_image_free(data);

//     return 0;
// }
