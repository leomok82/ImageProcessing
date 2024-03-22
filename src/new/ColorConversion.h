/**
 * @file ColorConversion.h
 * @brief Header file containing color conversion functions.
 *
 * This file defines the structures for representing colors in RGB, HSV, and HSL formats,
 * as well as functions for converting between these formats.
 *
 * @ingroup Yen
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 */

#ifndef COLOR_CONVERSION_H
#define COLOR_CONVERSION_H

/**
 * @struct ColorRGB
 * @brief Structure representing a color in RGB format.
 *
 * The color is represented by three unsigned char values for red, green, and blue channels.
 */
struct ColorRGB {
    unsigned char r, g, b;
};

/**
 * @struct ColorHSV
 * @brief Structure representing a color in HSV format.
 *
 * The color is represented by three double values for hue, saturation, and value.
 */
struct ColorHSV {
    double h, s, v;
};

/**
 * @struct ColorHSL
 * @brief Structure representing a color in HSL format.
 *
 * The color is represented by three double values for hue, saturation, and lightness.
 */
struct ColorHSL {
    double h, s, l;
};

/**
 * @brief Convert a color from RGB to HSV format.
 *
 * @param rgb The color in RGB format.
 * @return The color converted to HSV format.
 */
ColorHSV rgbToHsv(const ColorRGB& rgb);

/**
 * @brief Convert a color from HSV to RGB format.
 *
 * @param hsv The color in HSV format.
 * @return The color converted to RGB format.
 */
ColorRGB hsvToRgb(const ColorHSV& hsv);

/**
 * @brief Convert a color from RGB to HSL format.
 *
 * @param rgb The color in RGB format.
 * @return The color converted to HSL format.
 */
ColorHSL rgbToHsl(const ColorRGB& rgb);

/**
 * @brief Convert a color from HSL to RGB format.
 *
 * @param hsl The color in HSL format.
 * @return The color converted to RGB format.
 */
ColorRGB hslToRgb(const ColorHSL& hsl);

#endif // COLOR_CONVERSION_H
