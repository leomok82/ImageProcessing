#include "ColourFilterCorrection.h"
#include <algorithm> // For std::max and std::min
#include <iostream>
#include <numeric>

std::unique_ptr<Filter> ColourCorrectionFilter::create(int type) {
    switch (type) {
        case 1: // Grayscale
            return std::make_unique<GrayscaleFilter>();
        case 2: // Brightness
            return std::make_unique<BrightnessFilter>(); // Example placeholder
        case 3: // Histogram Equalization
            return std::make_unique<HistogramEqualizerFilter>();
        case 4: // Thresholding
            return std::make_unique<ThresholdingFilter>();
        case 5: // Histogram Equalization
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

void HistogramEqualizerFilter::apply(unsigned char* data, int width, int height, int channels) {

    std::cout << "Not implemented yet." << std::endl;
    
}

void ThresholdingFilter::apply(unsigned char* data, int width, int height, int channels) {
    
    std::cout << "Not implemented yet." << std::endl;

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

