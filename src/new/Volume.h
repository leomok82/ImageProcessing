/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

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
    void saveSlices() const;
    void setDimensions(int w, int h, int d); 

private:
    std::vector<unsigned char> data;
    int width, height, depth;
};

#endif // VOLUME_H
