#ifndef COLOURCORRECTIONFILTER_H
#define COLOURCORRECTIONFILTER_H

#include "Filter.h"
#include <memory>

/**
 * @brief Creates and returns a unique_ptr to a Filter object based on the specified type.
 * 
 * This factory method supports the creation of various filter types for colour correction
 * including grayscale, brightness adjustment, histogram equalization, thresholding, and
 * salt and pepper noise addition. The method prompts the user for additional parameters
 * required by certain filters, such as the brightness delta or the noise percentage.
 * 
 * @param type The type of filter to create. The supported types are:
 *             1 for Grayscale,
 *             2 for Brightness,
 *             3 for Histogram Equalization,
 *             4 for Thresholding,
 *             5 for Salt and Pepper Noise.
 *             Any other value will result in a nullptr being returned.
 * @return std::unique_ptr<Filter> A unique pointer to the created filter object, or nullptr
 *         if an unknown filter type is specified.
 */
// Abstract class for colour correction filters
class ColourCorrectionFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

/**
 * @brief Applies a grayscale filter to an image data buffer.
 * 
 * This method converts color image data to grayscale using the luminosity method, which
 * takes a weighted sum of the RGB values. It iterates over every pixel in the image data
 * and replaces the RGB values with their grayscale equivalent. The method requires the image
 * data to have at least three channels (RGB).
 * 
 * @param data Pointer to the image data buffer.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of channels in the image data (must be at least 3 for RGB images).
 */
// Concrete Grayscale filter class
class GrayscaleFilter : public ColourCorrectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

/**
 * @brief Applies a brightness adjustment to the image data.
 * 
 * This method iterates through each pixel in the image data and adjusts its brightness.
 * The brightness adjustment is applied equally to all color channels (RGB) by adding a delta
 * value to each channel. The method ensures that the final channel values remain within the 
 * 0 to 255 range. If the image data includes an alpha channel, it is left unchanged.
 * 
 * @param data Pointer to the image data buffer.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of channels in the image data (3 for RGB, 4 for RGBA).
 */
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

/**
 * @brief Applies histogram equalization to the image data.
 * 
 * This method enhances the contrast of the image using histogram equalization. It supports
 * grayscale images directly, and color images in either HSL or HSV color space by working
 * on the lightness or value channel, respectively. The choice between HSL and HSV is based
 * on the `useHSL` member variable. For grayscale images or color images, it computes the 
 * histogram of the relevant channel, calculates the cumulative distribution function, and
 * applies histogram equalization to adjust the pixel values.
 * 
 * @param data Pointer to the image data buffer.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of channels in the image data (1 for grayscale, 3 or more for color).
 */
// Concrete HistogramEqualizer filter class
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

/**
 * @brief Applies a threshold filter to the image data.
 * 
 * This method converts the image to a binary (black and white) image based on a threshold value.
 * It supports grayscale images directly and color images in either HSL or HSV color space. For color
 * images, the method first converts the image to the selected color space (HSL or HSV), applies
 * the threshold to the lightness or value channel, and then converts it back to RGB. Pixels above
 * the threshold are set to white, while those below are set to black.
 * 
 * @param data Pointer to the image data buffer.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of channels in the image data (1 for grayscale, 3 or more for color).
 */
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

/**
 * @brief Applies salt and pepper noise to the image data.
 * 
 * This method introduces a specified percentage of salt and pepper noise to the image. Salt
 * and pepper noise is randomly distributed black (pepper) and white (salt) pixels. The method
 * randomly selects pixels across the image and changes their value to either black or white,
 * based on the specified noise percentage. The noise is applied uniformly across all channels
 * except the alpha channel, if present.
 * 
 * @param data Pointer to the image data buffer.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 * @param channels The number of channels in the image data (3 for RGB, 4 for RGBA).
 */
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
