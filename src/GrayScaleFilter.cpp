#include "GrayscaleFilter.h"

GrayscaleFilter::GrayscaleFilter() {}

GrayscaleFilter::~GrayscaleFilter() {}

void GrayscaleFilter::apply(unsigned char* data, int width, int height, int channels) {
    if (channels < 3) return; // Not enough channels for color image

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int i = (y * width + x) * channels;
            unsigned char r = data[i];
            unsigned char g = data[i + 1];
            unsigned char b = data[i + 2];

            // Luminance formula: Y = 0.2126R + 0.7152G + 0.0722B
            unsigned char gray = static_cast<unsigned char>(0.2126f * r + 0.7152f * g + 0.0722f * b);

            // Apply grayscale value to all channels (assuming RGB)
            data[i] = gray;
            data[i + 1] = gray;
            data[i + 2] = gray;
        }
    }
}
