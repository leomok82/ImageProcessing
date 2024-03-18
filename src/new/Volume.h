// Volume.h
#ifndef VOLUME_H
#define VOLUME_H

#include <vector>
#include <string>
#include <filesystem>
#include "stb_image.h"

namespace fs = std::filesystem;

class Volume {
public:
    Volume();
    ~Volume();

    bool loadFromFolder(const std::string& folderpath);
    unsigned char getVoxel(int x, int y, int z) const;
    void getDimensions(int& width, int& height, int& depth) const;

private:
    std::vector<unsigned char> data;
    int width, height, depth;
};

#endif // VOLUME_H
