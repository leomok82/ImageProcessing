#include "ColourFilterCorrection.h"
#include "ColorConversion.h"
#include <algorithm> // For std::max and std::min
#include <iostream>
#include <numeric>

std::unique_ptr<Filter> ColourCorrectionFilter::create(int type) {
    switch (type) {
        case 1: // Grayscale
            return std::make_unique<GrayscaleFilter>();
        case 2: // Brightness
            int delta;
            std::cout << "Enter brightness delta (-255 to 255):";
            std::cin >> delta;
            return std::make_unique<BrightnessFilter>(delta); 
        case 3: // Histogram Equalization
            return std::make_unique<HistogramEqualizerFilter>();
        case 4: // Thresholding
            int threshold;
            std::cout << "Enter threshold (0 to 255):";
            std::cin >> threshold;
            return std::make_unique<ThresholdingFilter>(threshold);
        case 5: // Salt and Pepper Noise
            int noisePercentage;
            std::cout << "Enter Noise Percentage (0-100):";
            std::cin >> noisePercentage;
            return std::make_unique<SaltAndPepperNoiseFilter>(noisePercentage);
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

    // std::cout << "Histogram equalization applied." << std::endl;
}

void ThresholdingFilter::apply(unsigned char* data, int width, int height, int channels) {

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
            hsvColor.v = (hsvColor.v > threshold / 255.0 +hsvColor.s * std::min(threshold/255.0, 1-threshold/255.0)) ? 1.0 : 0; // Threshold and set value


            hsvColor.s = 0; // Remove saturation for pure black/white
            
            ColorRGB newColor = hsvToRgb(hsvColor);
            data[index] = newColor.r;
            data[index + 1] = newColor.g;
            data[index + 2] = newColor.b;
        }
    }
}

void SaltAndPepperNoiseFilter::apply(unsigned char* data, int width, int height, int channels) {

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

