/**
 * @file ColourFilterCorrection.h
 * @brief This file contains the declaration of various colour correction filters.
 * 
 * The filters included in this file are:
 * - GrayscaleFilter: Applies the grayscale filter to an image.
 * - BrightnessFilter: Adjusts the brightness of an image.
 * - HistogramEqualizerFilter: Performs histogram equalization on an image.
 * - ThresholdingFilter: Applies thresholding to an image.
 * - SaltAndPepperNoiseFilter: Adds salt and pepper noise to an image.
 * 
 * The filters are implemented as concrete classes derived from the abstract base class ColourCorrectionFilter.
 * Each filter provides a method to apply the filter to the image data.
 * 
 * @note This file is part of the Yen group's project for the Advanced Programming course at Imperial College London.
 * The group members are Antony Krymski, Leo Mok, Bofan Liu, Zeyi Ke, Tianzi Zhang, and Yifan Wu.
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 * @date October 2021
 */

#ifndef COLOURCORRECTIONFILTER_H
#define COLOURCORRECTIONFILTER_H

#include "Filter.h"
#include <memory>

/**
 * @class ColourCorrectionFilter
 * @brief Abstract class for colour correction filters.
 * 
 * This class serves as the base class for all colour correction filters.
 * It provides a static factory method to create instances of specific filters.
 * Each derived filter class must implement the apply() method to apply the filter to the image data.
 */
class ColourCorrectionFilter : public Filter {
public:
    /**
     * @brief Creates a new instance of a colour correction filter based on the given type.
     * @param type The type of the filter.
     * @return A unique pointer to the created filter.
     */
    static std::unique_ptr<Filter> create(int type);
};

/**
 * @class GrayscaleFilter
 * @brief Concrete Grayscale filter class.
 * 
 * This class implements the grayscale filter, which converts an image to grayscale.
 * It inherits from the ColourCorrectionFilter base class and provides an implementation of the apply() method.
 */
class GrayscaleFilter : public ColourCorrectionFilter {
public:
    /**
     * @brief Applies the grayscale filter to the given image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @class BrightnessFilter
 * @brief Concrete Brightness filter class.
 * 
 * This class implements the brightness filter, which adjusts the brightness of an image.
 * It inherits from the ColourCorrectionFilter base class and provides an implementation of the apply() method.
 */
class BrightnessFilter : public ColourCorrectionFilter {
private:
    int delta;  // Delta for brightness adjustment
public:
    /**
     * @brief Constructor that sets the threshold.
     * @param brightnessValue The value to adjust the brightness.
     */
    BrightnessFilter(int brightnessValue) : delta(brightnessValue) {}

    /**
     * @brief Sets the delta value for brightness adjustment.
     * @param newDelta The new delta value.
     */
    void setDelta(int newDelta) {
        delta = newDelta;
    }

    /**
     * @brief Applies the brightness filter to the given image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @class HistogramEqualizerFilter
 * @brief Concrete HistogramEqualizer filter class.
 * 
 * This class implements the histogram equalizer filter, which performs histogram equalization on an image.
 * It inherits from the ColourCorrectionFilter base class and provides an implementation of the apply() method.
 */
class HistogramEqualizerFilter : public ColourCorrectionFilter{
public:
    /**
     * @brief Constructor that sets whether to use HSL.
     * @param useHSL Whether to use HSL for equalization.
     */
    HistogramEqualizerFilter(bool useHSL = false) : useHSL(useHSL) {}

    /**
     * @brief Sets whether to use HSL for equalization.
     * @param newuseHSL The new value for useHSL.
     */
    void setuseHSL(bool newuseHSL) {
        useHSL = newuseHSL;
    }

    /**
     * @brief Destructor.
     */
    virtual ~HistogramEqualizerFilter() {}

    /**
     * @brief Applies the histogram equalizer filter to the given image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    virtual void apply(unsigned char* data, int width, int height, int channels) override;
private:
    bool useHSL;

    /**
     * @brief Applies histogram equalization to grayscale image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     */
    void equalizeGrayscale(unsigned char* data, int width, int height);

    /**
     * @brief Applies histogram equalization to HSV image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void equalizeHSV(unsigned char* data, int width, int height, int channels);

    /**
     * @brief Applies histogram equalization to HSL image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void equalizeHSL(unsigned char* data, int width, int height, int channels);
};

/**
 * @class ThresholdingFilter
 * @brief Concrete ThresholdingFilter filter class.
 * 
 * This class implements the thresholding filter, which applies thresholding to an image.
 * It inherits from the ColourCorrectionFilter base class and provides an implementation of the apply() method.
 */
class ThresholdingFilter : public ColourCorrectionFilter {
private:
    int threshold;
    bool useHSL;

    /**
     * @brief Applies thresholding to grayscale image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     */
    void thresholdGrayscale(unsigned char* data, int width, int height);

    /**
     * @brief Applies thresholding to HSV image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void thresholdHSV(unsigned char* data, int width, int height, int channels);

    /**
     * @brief Applies thresholding to HSL image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void thresholdHSL(unsigned char* data, int width, int height, int channels);
public:
    /**
     * @brief Constructor that sets the threshold.
     * @param thresholdValue The threshold value.
     * @param useHSL Whether to use HSL for thresholding.
     */
    ThresholdingFilter(int thresholdValue, bool useHSL = false) 
        : threshold(thresholdValue), useHSL(useHSL) {}

    /**
     * @brief Sets the threshold value.
     * @param newThreshold The new threshold value.
     */
    void setThreshold(int newThreshold) {
        threshold = newThreshold;
    }

    /**
     * @brief Sets whether to use HSL for thresholding.
     * @param newuseHSL The new value for useHSL.
     */
    void setuseHSL(bool newuseHSL) {
        useHSL = newuseHSL;
    }

    /**
     * @brief Applies the thresholding filter to the given image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @class SaltAndPepperNoiseFilter
 * @brief Concrete SaltAndPepperNoise filter class.
 * 
 * This class implements the salt and pepper noise filter, which adds salt and pepper noise to an image.
 * It inherits from the ColourCorrectionFilter base class and provides an implementation of the apply() method.
 */
class SaltAndPepperNoiseFilter : public ColourCorrectionFilter {
private:
    int noisePercentage;
public:
    /**
     * @brief Constructor that sets the noise percentage.
     * @param thresholdValue The noise percentage value.
     */
    SaltAndPepperNoiseFilter(int thresholdValue) : noisePercentage(thresholdValue) {}

    /**
     * @brief Sets the noise percentage value.
     * @param newnoisePercentage The new noise percentage value.
     */
    void setnoisePercentage(int newnoisePercentage) {
        noisePercentage = newnoisePercentage;
    }

    /**
     * @brief Applies the salt and pepper noise filter to the given image data.
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // COLOURCORRECTIONFILTER_H
