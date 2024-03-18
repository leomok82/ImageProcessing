// Volume.h
#ifndef VOLUME_H
#define VOLUME_H

#include <vector>
#include <string>

class Volume {
public:
    Volume();
    ~Volume();

    bool loadFromFile(const std::string& filepath);
    unsigned char getVoxel(int x, int y, int z) const;
    void getDimensions(int& width, int& height, int& depth) const;

private:
    std::vector<unsigned char> data;
    int width, height, depth;
};

#endif // VOLUME_H
