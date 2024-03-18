// #include "BrightnessFilter.h"
// #include <algorithm> // For std::max and std::min

// BrightnessFilter::BrightnessFilter(int delta) : brightnessDelta(delta) {}

// BrightnessFilter::~BrightnessFilter() {}

// void BrightnessFilter::apply(unsigned char* data, int width, int height, int channels) {
//     for (int y = 0; y < height; ++y) {
//         for (int x = 0; x < width; ++x) {
//             unsigned char* pixel = data + (y * width + x) * channels;
//             for (int c = 0; c < channels; ++c) {
//                 // Skip the alpha channel if it exists
//                 if (channels == 4 && c == 3) continue;

//                 // Apply brightness delta and clamp
//                 int value = pixel[c] + brightnessDelta;
//                 pixel[c] = static_cast<unsigned char>(std::max(0, std::min(255, value)));
//             }
//         }
//     }
// }

