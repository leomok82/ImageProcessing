/**
 * @file Image.h
 * @brief This file contains the declaration of the Image class.
 * 
 * The Image class represents an image and provides methods to manipulate and retrieve information about the image.
 * It stores the image data, dimensions, and validity status.
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 * 
 * @date September 2021
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
    /**
     * @brief Constructs an Image object with the specified path.
     * 
     * @param path The path to the image file.
     */
    Image(const std::string& path);

    /**
     * @brief Destroys the Image object and frees the allocated memory.
     */
    ~Image();

    /**
     * @brief Saves the image to the specified path.
     * 
     * @param path The path to save the image.
     * @return true if the image is successfully saved, false otherwise.
     */
    bool save(const std::string& path);

    /**
     * @brief Retrieves the dimensions of the image.
     * 
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of color channels in the image.
     */
    void getDimensions(int& width, int& height, int& channels) const;

    /**
     * @brief Retrieves the raw image data.
     * 
     * @return A pointer to the raw image data.
     */
    unsigned char* getData() const;

    /**
     * @brief Retrieves a reference to the pixel at the specified coordinates and color channel.
     * 
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @param c The color channel index.
     * @return A reference to the pixel value.
     */
    unsigned char& at(int x, int y, int c);

    /**
     * @brief Checks if the image is valid.
     * 
     * @return true if the image is valid, false otherwise.
     */
    bool isValidImage() const;

private:
    unsigned char* data; // The raw image data
    int width; // The width of the image
    int height; // The height of the image
    int channels; // The number of color channels in the image
    bool isValid; // The validity status of the image
};

#endif // IMAGE_H