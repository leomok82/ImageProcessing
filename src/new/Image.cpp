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
