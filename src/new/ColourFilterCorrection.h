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
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Brightness filter class
class HistogramEqualizerFilter : public ColourCorrectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Brightness filter class
class ThresholdingFilter : public ColourCorrectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Salt and Pepper Noise filter class
class SaltAndPepperNoiseFilter : public ColourCorrectionFilter {
public:
    // SaltAndPepperNoiseFilter(float noisePercentage); // Constructor to set noise percentage
    void apply(unsigned char* data, int width, int height, int channels) override;
};


#endif // COLOURCORRECTIONFILTER_H
