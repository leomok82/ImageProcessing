#ifndef VOLUME_H
#define VOLUME_H

#include <vector>
#include <string>
#include <filesystem>
#include "Image.h" // Update to include Image.h instead of stb_image.h

class Volume {
public:
    Volume();
    ~Volume();

    bool loadFromFolder(const std::string& folderpath);
    unsigned char getVoxel(int x, int y, int z) const;
    void getDimensions(int& width, int& height, int& depth) const;
    const std::vector<unsigned char>& getData() const;
    void setData(const std::vector<unsigned char>& newData);

private:
    std::vector<unsigned char> data;
    int width, height, depth;
};

#endif // VOLUME_H
