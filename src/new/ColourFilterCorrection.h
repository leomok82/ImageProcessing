/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

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
private:
    int delta;  // Delta for brightness adjustment
public:
    // Constructor that sets the threshold
    BrightnessFilter(int brightnessValue) : delta(brightnessValue) {}
    void setDelta(int newDelta) {
        delta = newDelta;
    }
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Brightness filter class
class HistogramEqualizerFilter : public ColourCorrectionFilter{
public:
    HistogramEqualizerFilter(bool useHSL = false) : useHSL(useHSL) {}
    void setuseHSL(bool newuseHSL) {
        useHSL = newuseHSL;
    }
    virtual ~HistogramEqualizerFilter() {}
    virtual void apply(unsigned char* data, int width, int height, int channels) override;
private:
    bool useHSL;
    void equalizeGrayscale(unsigned char* data, int width, int height);
    void equalizeHSV(unsigned char* data, int width, int height, int channels);
    void equalizeHSL(unsigned char* data, int width, int height, int channels);
};


// Concrete ThresholdingFilter filter class

class ThresholdingFilter : public ColourCorrectionFilter {
private:
    int threshold;
    bool useHSL;
    void thresholdGrayscale(unsigned char* data, int width, int height);
    void thresholdHSV(unsigned char* data, int width, int height, int channels);
    void thresholdHSL(unsigned char* data, int width, int height, int channels);
public:
    // Constructor that sets the threshold
    ThresholdingFilter(int thresholdValue, bool useHSL = false) 
        : threshold(thresholdValue), useHSL(useHSL) {}
    void setThreshold(int newThreshold) {
        threshold = newThreshold;
    }
    void setuseHSL(bool newuseHSL) {
        useHSL = newuseHSL;
    }
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Concrete Salt and Pepper Noise filter class
class SaltAndPepperNoiseFilter : public ColourCorrectionFilter {
private:
    int noisePercentage;
public:
    SaltAndPepperNoiseFilter(int thresholdValue) : noisePercentage(thresholdValue) {}
    void setnoisePercentage(int newnoisePercentage) {
        noisePercentage = newnoisePercentage;
    }
    // SaltAndPepperNoiseFilter(float noisePercentage); // Constructor to set noise percentage
    void apply(unsigned char* data, int width, int height, int channels) override;
};



#endif // COLOURCORRECTIONFILTER_H
