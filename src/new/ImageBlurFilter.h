#ifndef IMAGEBLURFILTER_H
#define IMAGEBLURFILTER_H
#include "Image.h"
#include "Filter.h"
#include <cmath>
#include <memory>
#include <iostream>
#include "Utils.h"

/**
 * @brief Factory method to create image blur filters.
 * 
 * Creates and returns a unique pointer to a Filter object based on the specified blur type and kernel size. 
 * For Gaussian blur filters, an overloaded version of this method also accepts a sigma value.
 * 
 * @param type The type of blur filter to create. 
 *        1 = Median Blur, 
 *        2 = Box Blur, 
 *        3 = Gaussian Blur (requires sigma parameter in the overloaded function).
 * @param kernelSize The size of the kernel to be used by the blur filter. For Gaussian blur, it also determines the spread of the blur.
 * @param sigma (Optional) The standard deviation of the Gaussian distribution used for the Gaussian blur. 
 *        Only applicable when type is 3 for Gaussian Blur.
 * @return std::unique_ptr<Filter> A unique pointer to the created blur filter, or nullptr if an invalid type is specified.
 */
class ImageBlurFilter : public Filter
{
    // int kernelSize;
public:
    ImageBlurFilter(int kernelSize) : kernelSize(kernelSize) {}

    static std::unique_ptr<Filter> create(int type, int kernelSize);
    static std::unique_ptr<Filter> create(int type, int kernelSize, double sigma);

    // Provide interface for derived classes that need to process Image objects
    virtual void apply(Image &img)
    {
        // // Default implementation or left for subclass to override
        std::cout << "Image processing not supported by this filter." << std::endl;
    }

protected:
    int kernelSize;
};

/**
 * @brief Applies a median blur filter to an image.
 * 
 * Iterates over each pixel in the image, replacing it with the median value from its neighborhood defined by the kernel size.
 * This method effectively reduces noise while preserving edges by utilizing the median filtering technique.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image data (e.g., 3 for RGB, 4 for RGBA).
 */
class MedianBlurFilter : public ImageBlurFilter
{
public:
    MedianBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}

    void apply(unsigned char *data, int width, int height, int channels) override;
};

/**
 * @brief Applies a box blur filter to an image.
 * 
 * Averages pixels within a kernel-sized box around each target pixel. The box blur is a simple form of blurring,
 * resulting in each pixel being set to the average value of the pixels in its neighborhood.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image data.
 */
// Concrete Box Blur filter class
class BoxBlurFilter : public ImageBlurFilter
{
public:
    BoxBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}
    void apply(unsigned char *data, int width, int height, int channels) override;
};

/**
 * @brief Applies a Gaussian blur filter to an image.
 * 
 * Utilizes a Gaussian kernel to apply a blur effect, smoothing the image while preserving edge integrity better than a simple average.
 * This method calculates Gaussian weights based on the provided sigma and applies the blur both horizontally and vertically.
 * 
 * @param data Pointer to the image data array.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of color channels in the image data.
 */
class GaussianBlurFilter : public ImageBlurFilter
{
public:
    // GaussianBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize){};
    GaussianBlurFilter(int kernelSize, double sigma) : ImageBlurFilter(kernelSize), sigma(sigma) {}

    void apply(unsigned char *data, int width, int height, int channels) override;

private:
    double sigma;
    void calculateGaussianWeights(double sigma, int kernelSize, std::vector<double> &weights);
    int mirrorIndex(int index, int maxIndex);
    void applyGaussianBlurOnRow(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output);
    void applyGaussianBlurOnColumn(unsigned char *data, int width, int height, int channels, const std::vector<double> &weights, unsigned char *output);
};

#endif // IMAGEBLURFILTER_H
