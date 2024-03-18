#ifndef EDGEDETECTIONFILTER_H
#define EDGEDETECTIONFILTER_H

#include "Filter.h"
#include <memory>

// Abstract base class for edge detection filters
class EdgeDetectionFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

// Sobel Filter
class SobelFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Prewitt Filter
class PrewittFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Custom Edge Detection Filter (Example: Scharr)
class ScharrFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Add more filters as needed...

#endif // EDGEDETECTIONFILTER_H
