#include "Image.h"
#include <filesystem>
#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"

Image::Image(const std::string& path) : data(nullptr), width(0), height(0), channels(0), isValid(true) {
    if (std::filesystem::is_directory(path)) {
        std::cerr << "Provided path is a directory, not an image file: " << path << std::endl;
        isValid = false;
        return;
    }

    data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data == nullptr) {
        std::cerr << "Failed to load image: " << path << std::endl;
        isValid = false;
    }
}

Image::~Image() {
    if (data) {
        stbi_image_free(data);
    }
}

bool Image::save(const std::string& path) {
    if (data == nullptr) {
        std::cerr << "No image data to save." << std::endl;
        return false;
    }
    int success = stbi_write_png(path.c_str(), width, height, channels, data, width * channels);
    return success != 0;
}

void Image::getDimensions(int& width, int& height, int& channels) const {
    width = this->width;
    height = this->height;
    channels = this->channels;
}

unsigned char* Image::getData() const {
    return data;
}

unsigned char &Image::at(int x, int y, int c) {
    return data[(y * width + x) * channels + c];
}

bool Image::isValidImage() const {
    return isValid;
}


// void Image::setData(const unsigned char *newData, int newSize)
// {
//     if (newSize != width * height * channels)
//     {
//         throw std::invalid_argument("New data size does not match the existing image size.");
//     }
//     if (!data)
//     {
//         data = new unsigned char[newSize];
//     }
//     std::memcpy(data, newData, newSize);
// }
// void Image::setPixel(int x, int y, int c, unsigned char value)
// {
//     if (x < 0 || x >= width || y < 0 || y >= height || c < 0 || c >= channels)
//     {
//         throw std::out_of_range("Pixel coordinates or channel index out of range.");
//     }
//     data[(y * width + x) * channels + c] = value;
// }

// The intention is to simulate two-dimensional matrix access through the `at` function
// while handling logic for mirroring the boundaries, to be completed.
// unsigned char &Image::at(int x, int y, int c)
// {
//     // Mirror borders if out of bounds.This function  left edge and down edge need to be fixed.
//     x = x < 0 ? -x : (x >= width ? 2 * width - x - 2 : x);
//     y = y < 0 ? -y : (y >= height ? 2 * height - y - 2 : y);
//     return data[(y * width + x) * channels + c];
// }
// The current at function is used only to simulate a two-dimensional matrix
// on a one-dimensional array