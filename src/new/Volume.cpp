#include "Volume.h"
#include <iostream>

Volume::Volume() : width(0), height(0), depth(0) {}

Volume::~Volume() {}

bool Volume::loadFromFolder(const std::string& folderpath) {
    std::vector<Image> images;
    int w = 0, h = 0, c = 0;
    
    for (const auto& entry : std::filesystem::directory_iterator(folderpath)) {
        if (entry.is_regular_file()) {
            Image img(entry.path().string());
            
            if (!w && !h) { // Initialize dimensions based on the first image
                img.getDimensions(w, h, c);
                width = w;
                height = h;
                depth = 0; // Initialize depth
                data.reserve(width * height * c); // Reserve space based on the estimated size
            }
            
            // Verify that all images have the same dimensions and channels
            int imgWidth, imgHeight, imgChannels;
            img.getDimensions(imgWidth, imgHeight, imgChannels);
            if (imgWidth != w || imgHeight != h || imgChannels != c) {
                std::cerr << "Image dimensions or channel count do not match: " << entry.path() << std::endl;
                return false;
            }
            
            unsigned char* imgData = img.getData();
            data.insert(data.end(), imgData, imgData + (w * h * c)); // Append image data to the volume data
            depth++; // Increment depth with each added image
        }
    }

    if (depth == 0) {
        std::cerr << "No images loaded from folder: " << folderpath << std::endl;
        return false;
    }

    return true;
}

unsigned char Volume::getVoxel(int x, int y, int z) const {
    int index = (z * width * height + y * width + x) * (data.size() / (width * height * depth));
    if (x < 0 || x >= width || y < 0 || y >= height || z < 0 || z >= depth || index >= data.size()) {
        std::cerr << "Voxel coordinates out of bounds" << std::endl;
        return 0;
    }
    return data[index];
}

void Volume::getDimensions(int& w, int& h, int& d) const {
    w = width;
    h = height;
    d = depth;
}

// Method to get a reference to the volume data
const std::vector<unsigned char>& Volume::getData() const {
    return data;
}

// Method to set the volume data
void Volume::setData(const std::vector<unsigned char>& newData) {
    data = newData;
}

