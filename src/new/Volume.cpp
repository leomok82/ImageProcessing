#include "Volume.h"
#include "Image.h"
#include "Utils.h"
#include "stb_image_write.h"
#include <iostream>
#include <vector>
#include <filesystem>
#include <regex>
#include <map>
#include <set>

Volume::Volume() : width(0), height(0), depth(0) {}

Volume::~Volume() {}

bool Volume::loadFromFolder(const std::string& folderpath) {
    std::vector<std::string> filenames;

    const std::set<std::string> allowedExtensions = {".png", ".jpg", ".jpeg", ".bmp", ".tiff"};

    // Collect valid image filenames
    for (const auto& entry : std::filesystem::directory_iterator(folderpath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            std::transform(extension.begin(), extension.end(), extension.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (allowedExtensions.find(extension) != allowedExtensions.end()) {
                filenames.push_back(entry.path());
            } else {
                std::cerr << "Skipping non-image file: " << entry.path().filename().string() << std::endl;
            }
        }
    }

    quickSortFilenames(filenames, 0, filenames.size() - 1);

    std::map<int, std::string> sortedFiles;
    for (int i = 0; i < filenames.size(); ++i) {
        sortedFiles[i] = filenames[i];
    }

    // Original code follows, using sortedFiles as before
    auto firstEntry = sortedFiles.begin();
    Image firstImg(firstEntry->second);
    int imgWidth, imgHeight, imgChannels;
    firstImg.getDimensions(imgWidth, imgHeight, imgChannels);
    width = imgWidth;
    height = imgHeight;
    int channels = imgChannels; // Assuming there's a channels attribute
    data.reserve(width * height * channels * sortedFiles.size());

    for (const auto& [index, filePath] : sortedFiles) {
        Image img(filePath);
        
        img.getDimensions(imgWidth, imgHeight, imgChannels);
        if (imgWidth != width || imgHeight != height || imgChannels != channels) {
            std::cerr << "Image dimensions or channel count do not match: " << filePath << std::endl;
            return false;
        }
        
        unsigned char* imgData = img.getData();
        data.insert(data.end(), imgData, imgData + (imgWidth * imgHeight * channels));
    }

    depth = sortedFiles.size();
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
