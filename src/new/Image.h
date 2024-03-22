/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

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
