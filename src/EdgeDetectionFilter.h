/**
 * @file EdgeDetectionFilter.h
 * @brief This file contains the declaration of the EdgeDetectionFilter class and its derived classes.
 * 
 * The EdgeDetectionFilter class is an abstract base class for edge detection filters. It provides a static
 * factory method to create instances of derived classes based on the specified type. The derived classes
 * implement the apply() method to perform edge detection on the input image data.
 * 
 * The derived classes include:
 * - SobelFilter: Implements the Sobel edge detection algorithm.
 * - PrewittFilter: Implements the Prewitt edge detection algorithm.
 * - ScharrFilter: Implements a custom edge detection algorithm using the Scharr operator.
 * - RobertsCrossFilter: Implements the Roberts Cross edge detection algorithm.
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 */

#ifndef EDGEDETECTIONFILTER_H
#define EDGEDETECTIONFILTER_H

#include "Filter.h"
#include <memory>

/*
 * @brief Creates an edge detection filter based on the specified type.
 * 
 * This static method serves as a factory for creating different types of edge detection
 * filters. Each filter type applies a specific algorithm for edge detection in images.
 * 
 * @param type An integer specifying the filter type to be created.
 *        1 - Sobel filter,
 *        2 - Prewitt filter,
 *        3 - Scharr filter,
 *        4 - Roberts Cross filter.
 * @return A unique_ptr to a Filter object corresponding to the requested type. Returns
 *         nullptr if an unknown type is specified.
 */
// Abstract base class for edge detection filters
class EdgeDetectionFilter : public Filter {
public:
    /**
     * @brief Creates an instance of a derived edge detection filter based on the specified type.
     * 
     * @param type The type of the edge detection filter.
     * @return std::unique_ptr<Filter> A unique pointer to the created filter instance.
     */
    static std::unique_ptr<Filter> create(int type);
};

/**
 * @brief Applies the Sobel edge detection filter to an image.
 * 
 * This method is specific to the Sobel filter. It sets up the Sobel convolution kernels
 * and calls the common apply function with these kernels to detect edges in the image.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image.
 */
// Sobel Filter
class SobelFilter : public EdgeDetectionFilter {
public:
    /**
     * @brief Applies the Sobel edge detection algorithm to the input image data.
     * 
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @brief Applies the Prewitt edge detection filter to an image.
 * 
 * This method is specific to the Sobel filter. It sets up the Sobel convolution kernels
 * and calls the common apply function with these kernels to detect edges in the image.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image.
 */
// Prewitt Filter
class PrewittFilter : public EdgeDetectionFilter {
public:
    /**
     * @brief Applies the Prewitt edge detection algorithm to the input image data.
     * 
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @brief Applies the Scharr edge detection filter to an image.
 * 
 * This method is specific to the Sobel filter. It sets up the Sobel convolution kernels
 * and calls the common apply function with these kernels to detect edges in the image.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image.
 */
// Custom Edge Detection Filter (Example: Scharr)
class ScharrFilter : public EdgeDetectionFilter {
public:
    /**
     * @brief Applies a custom edge detection algorithm using the Scharr operator to the input image data.
     * 
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @class Applies the RobertsCross edge detection filter to an image.
 * 
 * @brief This method is specific to the Sobel filter. It sets up the Sobel convolution kernels
 * and calls the common apply function with these kernels to detect edges in the image.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image.
 */
class RobertsCrossFilter : public EdgeDetectionFilter {
public:
    /**
     * @brief Applies the Roberts Cross edge detection algorithm to the input image data.
     * 
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // EDGEDETECTIONFILTER_H