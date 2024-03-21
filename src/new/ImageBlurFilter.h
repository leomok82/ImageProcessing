#ifndef IMAGEBLURFILTER_H
#define IMAGEBLURFILTER_H
#include "Image.h"
#include "Filter.h"
#include <cmath>
#include <memory>
#include <iostream>
#include "Utils.h"

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

class MedianBlurFilter : public ImageBlurFilter
{
public:
    MedianBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}

    void apply(unsigned char *data, int width, int height, int channels) override;
};

// Concrete Box Blur filter class
class BoxBlurFilter : public ImageBlurFilter
{
public:
    BoxBlurFilter(int kernelSize) : ImageBlurFilter(kernelSize) {}
    void apply(unsigned char *data, int width, int height, int channels) override;
};

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
