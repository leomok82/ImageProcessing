#include "Volume.h"
#include "stb_image_write.h"
#include <iostream>
#include <algorithm> // Include this for std::sort
#include <vector>
#include <filesystem>
#include <iostream>

Volume::Volume() : width(0), height(0), depth(0) {}

Volume::~Volume() {}

bool Volume::loadFromFolder(const std::string& folderpath) {
    std::vector<std::string> filePaths;
    int w = 0, h = 0, c = 0;
    
    // Collect all file paths
    for (const auto& entry : std::filesystem::directory_iterator(folderpath)) {
        if (entry.is_regular_file()) {
            filePaths.push_back(entry.path().string());
        }
    }

    // Sort the file paths to ensure order
    std::sort(filePaths.begin(), filePaths.end());

    // Load images in sorted order
    for (const auto& filePath : filePaths) {
        Image img(filePath);
        
        if (!w && !h) { // Initialize dimensions based on the first image
            img.getDimensions(w, h, c);
            width = w;
            height = h;
            depth = 0; // Initialize depth
            data.reserve(width * height * c); // Reserve space
        }
        
        // Verify image dimensions and channels
        int imgWidth, imgHeight, imgChannels;
        img.getDimensions(imgWidth, imgHeight, imgChannels);
        if (imgWidth != w || imgHeight != h || imgChannels != c) {
            std::cerr << "Image dimensions or channel count do not match: " << filePath << std::endl;
            return false;
        }
        
        unsigned char* imgData = img.getData();
        data.insert(data.end(), imgData, imgData + (w * h * c)); // Append data
        depth++; // Increment depth
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

void Volume::saveSlices(const std::string& directoryPath) const {
    int numDigits = std::to_string(depth).length();
    for (int z = 0; z < depth; ++z) {
        std::string sliceNum = std::to_string(z + 1);
        std::string leadingZeros(numDigits - sliceNum.length(), '0');
        std::string filePath = directoryPath + "/slice_" + leadingZeros + sliceNum + ".png";
        std::vector<unsigned char> sliceData(width * height);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                sliceData[y * width + x] = getVoxel(x, y, z);
            }
        }
        stbi_write_png(filePath.c_str(), width, height, 1, sliceData.data(), width);
    }
}
