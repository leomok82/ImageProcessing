#include <iostream>
#include <vector>

#include "Image.h"

Image::Image(const char* filename) {
    int w, h, c;
    unsigned char* imgData = stbi_load(filename, &w, &h, &c, 0);
    if (!imgData) {
        std::cerr << "Error loading image." << std::endl;
        exit(1);
    };
    width = w;
    height = h;
    channels = c;
    data = std::vector<unsigned char>(imgData, imgData + w * h * c);
    stbi_image_free(imgData);
}

void Image::printInfo() {
    std::cout << "Image loaded with size " << width << " x " << height << " with " << channels << " channel(s)." << std::endl;
}

// void Image::save(const char* filename) {
//     int success = stbi_write_png(filename, width, height, channels, data.data(), 0);
//     if (!success) {
//         std::cerr << "Error saving image." << std::endl;
//         exit(1);
//     }
// }

// int main() {
//     Image image("dimorphos.png");
//     image.printInfo();
//     return 0;
// }
