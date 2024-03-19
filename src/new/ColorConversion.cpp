#include "ColorConversion.h"
#include <algorithm>
#include <cmath>

ColorHSV rgbToHsv(const ColorRGB& rgb) {
    double r = rgb.r / 255.0;
    double g = rgb.g / 255.0;
    double b = rgb.b / 255.0;

    double cmax = std::max(r, std::max(g, b));
    double cmin = std::min(r, std::min(g, b));
    double delta = cmax - cmin;

    ColorHSV hsv;
    if (delta == 0) {
        hsv.h = 0;
    } else if (cmax == r) {
        hsv.h = 60 * fmod(((g - b) / delta), 6);
    } else if (cmax == g) {
        hsv.h = 60 * ((b - r) / delta + 2);
    } else {
        hsv.h = 60 * ((r - g) / delta + 4);
    }

    hsv.h = (hsv.h < 0) ? (hsv.h + 360) : hsv.h;
    hsv.s = (cmax == 0) ? 0 : delta / cmax;
    hsv.v = cmax;

    return hsv;
}

ColorRGB hsvToRgb(const ColorHSV& hsv) {
    double c = hsv.v * hsv.s;
    double x = c * (1 - fabs(fmod(hsv.h / 60.0, 2) - 1));
    double m = hsv.v - c;

    double r, g, b;
    if (hsv.h >= 0 && hsv.h < 60) {
        r = c + m;
        g = x + m;
        b = m;
    } else if (hsv.h >= 60 && hsv.h < 120) {
        r = x + m;
        g = c + m;
        b = m;
    } else if (hsv.h >= 120 && hsv.h < 180) {
        r = m;
        g = c + m;
        b = x + m;
    } else if (hsv.h >= 180 && hsv.h < 240) {
        r = m;
        g = x + m;
        b = c + m;
    } else if (hsv.h >= 240 && hsv.h < 300) {
        r = x + m;
        g = m;
        b = c + m;
    } else {
        r = c + m;
        g = m;
        b = x + m;
    }

    ColorRGB rgbColor;
    rgbColor.r = static_cast<unsigned char>(r * 255);
    rgbColor.g = static_cast<unsigned char>(g * 255);
    rgbColor.b = static_cast<unsigned char>(b * 255);

    return rgbColor;
}

ColorHSL rgbToHsl(const ColorRGB& rgb) {
    double r = rgb.r / 255.0;
    double g = rgb.g / 255.0;
    double b = rgb.b / 255.0;

    double cmax = std::max({r, g, b});
    double cmin = std::min({r, g, b});
    double delta = cmax - cmin;

    ColorHSL hsl;

    // Calculate hue
    if (delta == 0) {
        hsl.h = 0;
    } else if (cmax == r) {
        hsl.h = 60 * fmod(((g - b) / delta), 6);
    } else if (cmax == g) {
        hsl.h = 60 * ((b - r) / delta + 2);
    } else {
        hsl.h = 60 * ((r - g) / delta + 4);
    }

    hsl.h = (hsl.h < 0) ? (hsl.h + 360) : hsl.h;

    // Calculate lightness
    hsl.l = (cmax + cmin) / 2;

    // Calculate saturation
    hsl.s = (delta == 0) ? 0 : delta / (1 - fabs(2 * hsl.l - 1));

    return hsl;
}

ColorRGB hslToRgb(const ColorHSL& hsl) {
    double c = (1 - fabs(2 * hsl.l - 1)) * hsl.s;
    double x = c * (1 - fabs(fmod(hsl.h / 60.0, 2) - 1));
    double m = hsl.l - c / 2;

    double r, g, b;
    if (hsl.h >= 0 && hsl.h < 60) {
        r = c, g = x, b = 0;
    } else if (hsl.h >= 60 && hsl.h < 120) {
        r = x, g = c, b = 0;
    } else if (hsl.h >= 120 && hsl.h < 180) {
        r = 0, g = c, b = x;
    } else if (hsl.h >= 180 && hsl.h < 240) {
        r = 0, g = x, b = c;
    } else if (hsl.h >= 240 && hsl.h < 300) {
        r = x, g = 0, b = c;
    } else {
        r = c, g = 0, b = x;
    }

    ColorRGB rgb;
    rgb.r = static_cast<unsigned char>((r + m) * 255);
    rgb.g = static_cast<unsigned char>((g + m) * 255);
    rgb.b = static_cast<unsigned char>((b + m) * 255);

    return rgb;
}