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
void Image::setData(const unsigned char *newData, int newSize)
{
    if (newSize != width * height * channels)
    {
        throw std::invalid_argument("New data size does not match the existing image size.");
    }
    if (!data)
    {
        data = new unsigned char[newSize];
    }
    std::memcpy(data, newData, newSize);
}
void Image::setPixel(int x, int y, int c, unsigned char value)
{
    if (x < 0 || x >= width || y < 0 || y >= height || c < 0 || c >= channels)
    {
        throw std::out_of_range("Pixel coordinates or channel index out of range.");
    }
    data[(y * width + x) * channels + c] = value;
}

// The intention is to simulate two-dimensional matrix access through the `at` function 
//while handling logic for mirroring the boundaries, to be completed.
unsigned char &Image::at(int x, int y, int c)
{
    // Mirror borders if out of bounds.This function  left edge and down edge need to be fixed.
    x = x < 0 ? -x : (x >= width ? 2 * width - x - 2 : x);
    y = y < 0 ? -y : (y >= height ? 2 * height - y - 2 : y);
    return data[(y * width + x) * channels + c];
}