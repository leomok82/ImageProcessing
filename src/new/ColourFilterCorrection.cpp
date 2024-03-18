#include "ColourFilterCorrection.h"
#include <algorithm> // For std::max and std::min
#include <iostream>
#include <numeric>

std::unique_ptr<Filter> ColourCorrectionFilter::create(int type) {
    switch (type) {
        case 1: // Grayscale
            return std::make_unique<GrayscaleFilter>();
        case 2: // Brightness
            return std::make_unique<BrightnessFilter>(); 
        case 3: // Histogram Equalization
            return std::make_unique<HistogramEqualizerFilter>();
        case 4: // Thresholding
            return std::make_unique<ThresholdingFilter>();
        case 5: // Salt and Pepper Noise
            return std::make_unique<SaltAndPepperNoiseFilter>();
        default:
            std::cerr << "Unknown colour correction filter type." << std::endl;
            return nullptr;
    }
}

// GrayscaleFilter apply method
void GrayscaleFilter::apply(unsigned char* data, int width, int height, int channels) {
    if (channels < 3) return; // Not enough channels for color image

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int i = (y * width + x) * channels;
            unsigned char r = data[i];
            unsigned char g = data[i + 1];
            unsigned char b = data[i + 2];

            unsigned char gray = static_cast<unsigned char>(0.2126f * r + 0.7152f * g + 0.0722f * b);
            data[i] = gray; data[i + 1] = gray; data[i + 2] = gray; // Apply grayscale
        }
    }
}

void BrightnessFilter::apply(unsigned char* data, int width, int height, int channels) {
    int delta;
    std::cout << "Enter brightness delta (-255 to 255):";
    std::cin >> delta;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = data + (y * width + x) * channels;
            for (int c = 0; c < channels; ++c) {
                if (channels == 4 && c == 3) continue; // Skip alpha

                int value = pixel[c] + delta;
                pixel[c] = static_cast<unsigned char>(std::max(0, std::min(255, value)));
            }
        }
    }
}

struct ColorRGB {
    unsigned char r, g, b;
};

struct ColorHSV {
    double h, s, v; // Hue [0, 360), Saturation [0, 1], Value [0, 1]
};
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

void HistogramEqualizerFilter::apply(unsigned char* data, int width, int height, int channels) {
    if (channels == 1) {
        // Grayscale image histogram equalization
        std::vector<int> histogram(256, 0);
        for (int i = 0; i < width * height; i++) {
            histogram[data[i]]++;
        }

        // Compute the CDF (Cumulative Distribution Function)
        std::vector<int> cdf(histogram.size(), 0);
        cdf[0] = histogram[0];
        for (size_t i = 1; i < histogram.size(); i++) {
            cdf[i] = cdf[i - 1] + histogram[i];
        }

        // Histogram equalization
        for (int i = 0; i < width * height; i++) {
            data[i] = (unsigned char)(255.0 * (cdf[data[i]] - cdf[0]) / (width * height - cdf[0]));
        }
    } else if (channels >= 3) {
        // RGB image histogram equalization, working on V channel in HSV color space
        std::vector<int> histogram(256, 0);  // Histogram for the V channel
        for (int i = 0; i < width * height; i++) {
            int index = i * channels;
            ColorRGB rgbColor = {data[index], data[index + 1], data[index + 2]};
            ColorHSV hsvColor = rgbToHsv(rgbColor);
            int vIndex = static_cast<int>(hsvColor.v * 255.0);
            histogram[vIndex]++;
        }

        // Compute the CDF for V channel
        std::vector<float> cdf(256, 0);
        cdf[0] = static_cast<float>(histogram[0]) / (width * height);
        for (int i = 1; i < 256; i++) {
            cdf[i] = cdf[i - 1] + static_cast<float>(histogram[i]) / (width * height);
        }

        // Apply histogram equalization
        for (int i = 0; i < width * height; i++) {
            int index = i * channels;
            ColorRGB rgbColor = {data[index], data[index + 1], data[index + 2]};
            ColorHSV hsvColor = rgbToHsv(rgbColor);
            int vIndex = static_cast<int>(hsvColor.v * 255.0);
            float equalizedV = cdf[vIndex] * 255.0f;
            hsvColor.v = equalizedV / 255.0f;

            ColorRGB newColor = hsvToRgb(hsvColor);
            data[index] = newColor.r;
            data[index + 1] = newColor.g;
            data[index + 2] = newColor.b;
        }
    }

    std::cout << "Histogram equalization applied." << std::endl;
}

void ThresholdingFilter::apply(unsigned char* data, int width, int height, int channels) {
        int threshold;
        std::cout << "Enter threshold (0 to 255):";
        std::cin >> threshold;
    if (channels == 1) { // For grayscale images
        for (int i = 0; i < width * height; i++) {
            data[i] = (data[i] > threshold) ? 255 : 0;
        }
    } else if (channels >= 3) { // For RGB images
        for (int i = 0; i < width * height; i++) {
            int index = i * channels;
            ColorRGB rgbColor = {data[index], data[index + 1], data[index + 2]};
            ColorHSV hsvColor = rgbToHsv(rgbColor);
            
            // Apply threshold on the Value channel
            hsvColor.v = (hsvColor.v > threshold / 255.0) ? 1.0 : 0; // Threshold and set value
            hsvColor.s = 0; // Remove saturation for pure black/white
            
            ColorRGB newColor = hsvToRgb(hsvColor);
            data[index] = newColor.r;
            data[index + 1] = newColor.g;
            data[index + 2] = newColor.b;
        }
    }

    std::cout << "Thresholding applied." << std::endl;
}

void SaltAndPepperNoiseFilter::apply(unsigned char* data, int width, int height, int channels) {
    int noisePercentage;
    std::cout << "Enter Noise Percentage (0-100):";
    std::cin >> noisePercentage;
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

    int totalPixels = width * height;
    int affectedPixels = static_cast<int>(totalPixels * (noisePercentage / 100.0f));

    for (int i = 0; i < affectedPixels; ++i) {
        int randPixelIndex = rand() % totalPixels; // Select a random pixel
        int pixelPos = randPixelIndex * channels; // Calculate its position in the array

        unsigned char noiseValue = (rand() % 2) == 0 ? 0 : 255; // Randomly choose black or white

        for (int j = 0; j < channels; ++j) { // Apply the noise to all channels (except alpha)
            if (channels == 4 && j == 3) continue; // Skip the alpha channel
            data[pixelPos + j] = noiseValue;
        }
    }
}

