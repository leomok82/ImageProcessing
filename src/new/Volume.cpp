// Volume.cpp
#include "Volume.h"
#include <fstream>
#include <iostream>

Volume::Volume() : width(0), height(0), depth(0) {}

Volume::~Volume() {}

bool Volume::loadFromFile(const std::string& filepath) {
    // Example file loading logic (needs to be adapted based on actual file format)
    std::ifstream file(filepath, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return false;
    }

    // Placeholder for file reading logic
    // This example assumes the file contains width, height, and depth at the beginning
    file.read(reinterpret_cast<char*>(&width), sizeof(width));
    file.read(reinterpret_cast<char*>(&height), sizeof(height));
    file.read(reinterpret_cast<char*>(&depth), sizeof(depth));

    data.resize(width * height * depth);
    file.read(reinterpret_cast<char*>(data.data()), data.size());

    file.close();
    return true;
}

unsigned char Volume::getVoxel(int x, int y, int z) const {
    if (x < 0 || x >= width || y < 0 || y >= height || z < 0 || z >= depth) {
        std::cerr << "Voxel coordinates out of bounds" << std::endl;
        return 0;
    }
    return data[x + width * (y + height * z)];
}

void Volume::getDimensions(int& w, int& h, int& d) const {
    w = width;
    h = height;
    d = depth;
}
