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


/**
 * @class Image
 * @brief Manages the loading, manipulation, and saving of image data.
 * 
 * This class encapsulates functionality for handling images. It supports loading images
 * from files, accessing and modifying image data, and saving images back to disk. The
 * class utilizes the stb_image.h and stb_image_write.h libraries for image operations.
 */

/**
 * @brief Constructs an Image object and loads image data from a specified path.
 * 
 * The constructor checks if the provided path is a directory or an invalid image path.
 * If the path is valid and points to an image file, it attempts to load the image data.
 * On success, the image data, dimensions, and channel count are stored.
 * 
 * @param path The filesystem path to the image file to be loaded.
 */
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
