#ifndef EDGEDETECTIONFILTER_H
#define EDGEDETECTIONFILTER_H

#include "Filter.h"
#include <memory>

// Abstract class for edge detection filters
class EdgeDetectionFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

// Concrete Sobel filter class
class SobelFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Prewitt filter class
class PrewittFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Scharr filter class
class ScharrFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // EDGEDETECTIONFILTER_H
