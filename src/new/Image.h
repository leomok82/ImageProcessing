#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "stb_image.h"
#include "stb_image_write.h"

class Image {
public:
    Image(const std::string& path);
    ~Image();
    bool save(const std::string& path);
    void getDimensions(int& width, int& height, int& channels) const;
    unsigned char* getData() const; // Method to access the image data
    unsigned char &at(int x, int y, int c);
    void setData(const unsigned char *newData, int newSize);
    void setPixel(int x, int y, int c, unsigned char value);

private:
    unsigned char* data;
    int width, height, channels;
};

#endif // IMAGE_H
