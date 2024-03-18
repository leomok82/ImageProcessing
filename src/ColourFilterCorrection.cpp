#include "ColourFilterCorrection.h"
#include <algorithm> // For std::max and std::min
#include <iostream>

std::unique_ptr<Filter> ColourCorrectionFilter::create(int type) {
    switch (type) {
        case 1: // Grayscale
            return std::make_unique<GrayscaleFilter>();
        case 2: // Brightness
            // Here you would normally get the delta value from user input
            return std::make_unique<BrightnessFilter>(50); // Example placeholder
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

// BrightnessFilter constructor and apply method
BrightnessFilter::BrightnessFilter(int delta) : brightnessValue(delta) {}

void BrightnessFilter::apply(unsigned char* data, int width, int height, int channels) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char* pixel = data + (y * width + x) * channels;
            for (int c = 0; c < channels; ++c) {
                if (channels == 4 && c == 3) continue; // Skip alpha

                int value = pixel[c] + brightnessValue;
                pixel[c] = static_cast<unsigned char>(std::max(0, std::min(255, value)));
            }
        }
    }
}
