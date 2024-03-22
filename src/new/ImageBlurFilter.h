/**
 * @file ImageBlurFilter.h
 * @brief This file contains the declaration of the ImageBlurFilter class and its derived classes.
 * 
 * The ImageBlurFilter class is an abstract base class that represents a generic image blur filter.
 * It provides an interface for derived classes to implement the blur filter functionality.
 * 
 * The derived classes, MedianBlurFilter, BoxBlurFilter, and GaussianBlurFilter, implement specific types of blur filters.
 * 
 * @author Group Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef IMAGEBLURFILTER_H
#define IMAGEBLURFILTER_H

#include "Image.h"
#include "Filter.h"
#include <cmath>
#include <memory>
#include <iostream>
#include "Utils.h"

/**
 * @class ImageBlurFilter
 * @brief Abstract base class for image blur filters.
 * 
 * The ImageBlurFilter class provides an interface for derived classes to implement the blur filter functionality.
 * It contains a member variable for the kernel size of the blur filter.
 */
class ImageBlurFilter : public Filter
{
public:
    /**
     * @brief Constructor for ImageBlurFilter.
     * @param kernelSize The size of the kernel used for the blur filter.
     */
    ImageBlurFilter(int kernelSize) : kernelSize(kernelSize) {}

    /**
     * @brief Factory method to create an instance of a blur filter.
     * @param type The type of the blur filter.
     * @param kernelSize The size of the kernel used for the blur filter.
     * @return A unique pointer to the created blur filter.
     */
    static std::unique_ptr<Filter> create(int type, int kernelSize);

    /**
     * @brief Factory method to create an instance of a blur filter with a specified sigma value.
     * @param type The type of the blur filter.
     * @param kernelSize The size of the kernel used for the blur filter.
     * @param sigma The sigma value used for the Gaussian blur filter.
     * @return A unique pointer to the created blur filter.
     */
    static std::unique_ptr<Filter> create(int type, int kernelSize, double sigma);

    /**
     * @brief Applies the blur filter to an Image object.
     * @param img The Image object to apply the blur filter to.
     */
    virtual void apply(Image &img)
    {
        std::cout << "Image processing not supported by this filter." << std::endl;
    }

protected:
    int kernelSize; /**< The size of the kernel used for the blur filter. */
};

/**
 * @class MedianBlurFilter
 * @brief A class that represents a median blur filter.
 * 
 * The MedianBlurFilter class is a derived class of ImageBlurFilter.
 * It implements the apply function to apply the median blur filter to an image.
 */
class MedianBlurFilter : public ImageBlurFilter
{
public:
    /**
     * @brief Constructor for MedianBlurFilter.
     * @param kernelSize The size of the kernel used for the median blur filter.
     */
    MedianBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}

    /**
     * @brief Applies the median blur filter to an image.
     * @param data The pixel data of the image.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char *data, int width, int height, int channels) override;
};

/**
 * @class BoxBlurFilter
 * @brief A class that represents a box blur filter.
 * 
 * The BoxBlurFilter class is a derived class of ImageBlurFilter.
 * It implements the apply function to apply the box blur filter to an image.
 */
class BoxBlurFilter : public ImageBlurFilter
{
public:
    /**
     * @brief Constructor for BoxBlurFilter.
     * @param kernelSize The size of the kernel used for the box blur filter.
     */
    BoxBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}

    /**
     * @brief Applies the box blur filter to an image.
     * @param data The pixel data of the image.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char *data, int width, int height, int channels) override;
};

/**
 * @class GaussianBlurFilter
 * @brief A class that represents a Gaussian blur filter.
 * 
 * The GaussianBlurFilter class is a derived class of ImageBlurFilter.
 * It implements the apply function to apply the Gaussian blur filter to an image.
 */
class GaussianBlurFilter : public ImageBlurFilter
{
public:
    /**
     * @brief Constructor for GaussianBlurFilter.
     * @param kernelSize The size of the kernel used for the Gaussian blur filter.
     * @param sigma The sigma value used for the Gaussian blur filter.
     */
    GaussianBlurFilter(int kernelSize, double sigma) : ImageBlurFilter(kernelSize), sigma(sigma) {}

    /**
     * @brief Applies the Gaussian blur filter to an image.
     * @param data The pixel data of the image.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char *data, int width, int height, int channels) override;

private:
    double sigma; /**< The sigma value used for the Gaussian blur filter. */

    /**
     * @brief Calculates the Gaussian weights for the blur filter.
     * @param sigma The sigma value used for the Gaussian blur filter.
     * @param kernelSize The size of the kernel used for the Gaussian blur filter.
     * @param weights The vector to store the calculated weights.
     */
    void calculateGaussianWeights(double sigma, int kernelSize, std::vector<double> &weights);

    /**
     * @brief Mirrors an index to handle boundary cases.
     * @param index The index to mirror.
     * @param maxIndex The maximum index value.
     * @return The mirrored index.
     */
    int mirrorIndex(int index, int maxIndex);

    /**
     * @brief Applies the Gaussian blur filter on a row of pixels in the image.
     * @param data The pixel data of the image.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     * @param weights The Gaussian weights for the blur filter.
     * @param output The output buffer to store the blurred pixels.
     */
    void applyGaussianBlurOnRow(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output);

    /**
     * @brief Applies the Gaussian blur filter on a column of pixels in the image.
     * @param data The pixel data of the image.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     * @param weights The Gaussian weights for the blur filter.
     * @param output The output buffer to store the blurred pixels.
     */
    void applyGaussianBlurOnColumn(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output);
};

#endif // IMAGEBLURFILTER_H
