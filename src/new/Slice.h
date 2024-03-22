/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef SLICE_H
#define SLICE_H

#include "Volume.h"
#include <vector>
#include <string>

class Slice {
    std::vector<unsigned char> data;
    int width, height;

public:
    Slice(int width, int height, const std::vector<unsigned char>& data)
        : width(width), height(height), data(data) {}

    // Adjusted for flexibility in slicing along different planes
    static Slice fromVolume(const Volume& volume, const std::string& plane, int coordinate);

    static Slice thinSlabAIP(const Volume& volume, int startSlice, int endSlice);
    static Slice thinSlabMIP(const Volume& volume, int startSlice, int endSlice);

    void saveToFile(const std::string& filePath) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::vector<unsigned char> getData() const { return data; }
};

#endif // SLICE_H
