#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
public:
    Image(const std::string& path);
    ~Image();
    bool save(const std::string& path);
    void getDimensions(int& width, int& height, int& channels) const;
    unsigned char* getData() const;
    unsigned char& at(int x, int y, int c);
    bool isValidImage() const; // New method to check if the image is valid

private:
    unsigned char* data;
    int width, height, channels;
    bool isValid; // New private member to store the image validity
};

#endif // IMAGE_H
