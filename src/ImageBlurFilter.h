#ifndef IMAGEBLURFILTER_H
#define IMAGEBLURFILTER_H

#include "Filter.h"
#include <memory>

// Abstract class for image blur filters
class ImageBlurFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

// Concrete Median Blur filter class
class MedianBlurFilter : public ImageBlurFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Box Blur filter class
class BoxBlurFilter : public ImageBlurFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Gaussian Blur filter class
class GaussianBlurFilter : public ImageBlurFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // IMAGEBLURFILTER_H
