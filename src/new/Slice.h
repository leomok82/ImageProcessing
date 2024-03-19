// Slice.h
#ifndef SLICE_H
#define SLICE_H

#include <vector>
#include <string>

class Slice {
    std::vector<unsigned char> data;
    int width, height;

public:
    Slice(int width, int height, const std::vector<unsigned char>& data)
        : width(width), height(height), data(data) {}

    void saveToFile(const std::string& filePath) const;
};

#endif // SLICE_H
