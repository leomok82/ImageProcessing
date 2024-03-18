// Volume.cpp
#include "Volume.h"
#include <fstream>
#include <iostream>

Volume::Volume() : width(0), height(0), depth(0) {}

Volume::~Volume() {}

bool Volume::loadFromFolder(const std::string& folderpath) {
    int w, h, c;
    std::vector<unsigned char*> slices;
    for (const auto& entry : fs::directory_iterator(folderpath)) {
        if (entry.is_regular_file()) {
            std::string filepath = entry.path().string();
            unsigned char* img = stbi_load(filepath.c_str(), &w, &h, &c, 0);
            if (img == nullptr) {
                std::cerr << "Failed to load image: " << filepath << std::endl;
                // Free already loaded slices to prevent memory leaks
                for (auto& slice : slices) stbi_image_free(slice);
                return false;
            }
            if (!width) {
                width = w;
                height = h;
                depth = 0; // Will increment with each slice
            } else if (width != w || height != h) {
                std::cerr << "Image dimensions do not match: " << filepath << std::endl;
                stbi_image_free(img);
                // Free already loaded slices to prevent memory leaks
                for (auto& slice : slices) stbi_image_free(slice);
                return false;
            }
            slices.push_back(img);
            depth++;
        }
    }

    // Combine slices into single data vector
    data.resize(width * height * depth * c);
    for (int z = 0; z < depth; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                for (int chan = 0; chan < c; chan++) {
                    data[chan + c * (x + width * (y + height * z))] = slices[z][chan + c * (x + y * width)];
                }
            }
        }
        stbi_image_free(slices[z]);
    }

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
