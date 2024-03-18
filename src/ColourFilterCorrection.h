#ifndef COLOURCORRECTIONFILTER_H
#define COLOURCORRECTIONFILTER_H

#include "Filter.h"
#include <memory>

// Abstract class for colour correction filters
class ColourCorrectionFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

// Concrete Grayscale filter class
class GrayscaleFilter : public ColourCorrectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Brightness filter class
class BrightnessFilter : public ColourCorrectionFilter {
public:
    BrightnessFilter(int value); // Constructor to set brightness value
    void apply(unsigned char* data, int width, int height, int channels) override;
private:
    int brightnessValue; // Brightness adjustment value
};

#endif // COLOURCORRECTIONFILTER_H
