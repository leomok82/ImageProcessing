#ifndef COLOR_CONVERSION_H
#define COLOR_CONVERSION_H

struct ColorRGB {
    unsigned char r, g, b;
};

struct ColorHSV {
    double h, s, v; // Hue [0, 360), Saturation [0, 1], Value [0, 1]
};

struct ColorHSL {
    double h, s, l;
};

ColorHSV rgbToHsv(const ColorRGB& rgb);
ColorRGB hsvToRgb(const ColorHSV& hsv);
ColorHSL rgbToHsl(const ColorRGB& rgb);
ColorRGB hslToRgb(const ColorHSL& hsl);
#endif // COLOR_CONVERSION_H
