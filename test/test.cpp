#include "test.h"
#include "../src/new/ColourFilterCorrection.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>


void reportTest(const std::string& testName, bool result) {
    std::cout << testName << ": " << (result ? "PASS" : "FAIL") << std::endl;
}

template<typename T, typename U>
void assertEquals(const std::string& testName, const T& expected, const U& actual) {
    bool result = (expected == actual);
    std::cout << testName << " - " << (result ? "PASS" : "FAIL") << std::endl;
    if (!result) {
        std::cout << " Expected: " << expected << ", Actual: " << actual << std::endl;
    }
}

// Apply the filter to a known RGB value and check if the result is the expected grayscale value.
void testGrayscaleFilter() {
    GrayscaleFilter filter;
    unsigned char data[3] = {150, 100, 50}; // Example RGB values
    filter.apply(data, 1, 1, 3); // width, height, channels
    unsigned char expectedGray = static_cast<unsigned char>(0.2126f * 150 + 0.7152f * 100 + 0.0722f * 50);
    assertEquals<unsigned char>("GrayscaleFilter", expectedGray, data[0]);
}

// Change the brightness and verify if the adjustment is correct.
void testBrightnessFilter() {
    int delta = 60; // Brightness increase
    BrightnessFilter filter(delta);
    filter.setDelta(delta); 
    // std::stringstream testInput;
    // testInput << delta << std::endl;
    // std::streambuf* origCin = std::cin.rdbuf(testInput.rdbuf());
    // std::cout << "Delta set in filter." << std::endl;   
    unsigned char data[3] = {100, 100, 100}; // Example RGB values
    filter.apply(data, 1, 1, 3); // Apply brightness filter
    // Calculate expected values, considering the clamping at 255
    unsigned char expectedValue = static_cast<unsigned char>(std::min(100 + delta, 255));

    // std::cout << static_cast<int>(expectedValue) << "\n";
    // std::cout << static_cast<int>(static_cast<unsigned char>(std::min(100 + delta, 255))) << "\n";
    // // Assuming 'data' has 3 elements for RGB
    // for (int i = 0; i < 3; i++) {
    //     std::cout << static_cast<int>(data[i]) << (i < 2 ? ", " : "\n");
    // }

    assertEquals("BrightnessFilter - Red Channel", expectedValue, data[0]);
    assertEquals("BrightnessFilter - Green Channel", expectedValue, data[1]);
    assertEquals("BrightnessFilter - Blue Channel", expectedValue, data[2]);
}

void testHistogramEqualizerFilter() {
    HistogramEqualizerFilter filter;
    const int width = 16;
    const int height = 16;
    unsigned char data[width * height];

    // Fill data with a gradient or test pattern
    for (int i = 0; i < width * height; i++) {
        data[i] = (i * 255) / (width * height);
    }

    filter.apply(data, width, height, 1);  // Apply histogram equalization

    // Compute histogram of the equalized data
    std::vector<int> histogram(256, 0);
    for (int i = 0; i < width * height; i++) {
        histogram[data[i]]++;
    }

    // Analyze the uniformity of the histogram
    double mean = std::accumulate(histogram.begin(), histogram.end(), 0.0) / histogram.size();
    double variance = 0.0;
    for (int count : histogram) {
        variance += (count - mean) * (count - mean);
    }
    variance /= histogram.size();
    double stdDeviation = std::sqrt(variance);

    // Define an acceptable level of uniformity
    double acceptableStdDev = 0.1; 

    // Use assertEquals to verify the uniformity
    assertEquals("Histogram uniformity", true, stdDeviation <= acceptableStdDev);
}

void testThresholdingFilter() {
    int threshold = 127;
    ThresholdingFilter filter(threshold);
    unsigned char data[1] = {128};  
    filter.apply(data, 1, 1, 1);  // Apply the thresholding filter

    // Assuming thresholding logic is such that value equal to threshold also becomes 255
    unsigned char expected = 255;  // Expected result after thresholding
    assertEquals<unsigned char>("ThresholdingFilter", expected, data[0]);

    // // Debug and see the numeric value
    // std::cout << "Expected: " << static_cast<int>(expected) << ", Actual: " << static_cast<int>(data[0]) << std::endl;
}

void testSaltAndPepperNoiseFilter() {
    int noisePercentage = 10;  // Set a test noise level
    SaltAndPepperNoiseFilter filter(noisePercentage);  // Initialize the filter with the noise level
    const int dataSize = 10000;  // Larger data size for statistical relevance
    unsigned char data[dataSize];
    std::fill_n(data, dataSize, 128);  // Fill with a mid-gray value

    filter.apply(data, 100, 100, 1);  // Apply noise filter, assuming a 100x100 image with 1 channel

    // Verify the noise is applied correctly
    int noiseCount = 0;
    for (int i = 0; i < dataSize; i++) {
        if (data[i] == 0 || data[i] == 255) {  // Count pixels that are fully black or white
            noiseCount++;
        }
    }

    double actualNoisePercentage = 100.0 * noiseCount / dataSize;
    // std::cout << "Actual noise percentage: " << actualNoisePercentage << "%" << std::endl;

    // Assert that the actual noise percentage is within an acceptable range of the expected value
    double tolerance = 5.0;  // Allow some variance due to the randomness
    assertEquals("Salt and Pepper Noise Filter ", true, actualNoisePercentage >= noisePercentage - tolerance && actualNoisePercentage <= noisePercentage + tolerance);
}