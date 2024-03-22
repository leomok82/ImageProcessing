/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef COLOR_CONVERSION_H
#define COLOR_CONVERSION_H

/**
 * @brief Converts an RGB color value to HSV (Hue, Saturation, Value).
 * 
 * The function converts an RGB color value to its equivalent in HSV color space.
 * RGB values must be in the range [0, 255]. The Hue (H) is calculated on a scale of [0, 360),
 * Saturation (S) and Value (V) are calculated on a scale of [0, 1]. This conversion is useful
 * for color transformations that are more intuitive in the HSV space.
 * 
 * @param rgb The RGB color value to convert. It is an object of ColorRGB, which contains three properties: r, g, and b, 
 *            each representing the red, green, and blue components of the color, respectively.
 * @return ColorHSV The HSV representation of the input color. It is an object of ColorHSV, which contains three properties: h, s, and v.
 *         h (hue) is in degrees [0, 360), s (saturation) and v (value) are in [0, 1].
 */
struct ColorRGB {
    unsigned char r, g, b;
};

/**
 * @struct ColorHSV
 * @brief Represents a color in the HSV (Hue, Saturation, Value) color space.
 * 
 * @var ColorHSV::h
 * Hue component of the color, in degrees [0, 360).
 * 
 * @var ColorHSV::s
 * Saturation component of the color, on a scale from 0 to 1.
 * 
 * @var ColorHSV::v
 * Value (brightness) component of the color, on a scale from 0 to 1.
 */
struct ColorHSV {
    double h, s, v; // Hue [0, 360), Saturation [0, 1], Value [0, 1]
};

/**
 * @struct ColorHSL
 * @brief Represents a color in the HSL (Hue, Saturation, Lightness) color space.
 * 
 * @var ColorHSL::h
 * Hue component of the color, in degrees [0, 360).
 * 
 * @var ColorHSL::s
 * Saturation component of the color, on a scale from 0 to 1.
 * 
 * @var ColorHSL::l
 * Lightness component of the color, on a scale from 0 to 1.
 */
struct ColorHSL {
    double h, s, l;
};

ColorHSV rgbToHsv(const ColorRGB& rgb);
ColorRGB hsvToRgb(const ColorHSV& hsv);
ColorHSL rgbToHsl(const ColorRGB& rgb);
ColorRGB hslToRgb(const ColorHSL& hsl);
#endif // COLOR_CONVERSION_H
