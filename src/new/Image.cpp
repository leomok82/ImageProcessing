#include "Image.h"
#include <iostream>

Image::Image(const std::string& path) : data(nullptr), width(0), height(0), channels(0) {
    data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data == nullptr) {
        std::cerr << "Failed to load image: " << path << std::endl;
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
