#include "test.h"
#include "../src/new/ColourFilterCorrection.h"
#include "../src/new/ImageBlurFilter.h"
#include "../src/new/EdgeDetectionFilter.h"


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

template <typename T>
void assertArrayEquals(const std::string &testName, const std::vector<T> &expected, const std::vector<T> &actual)
{
    if (expected.size() != actual.size())
    {
        std::cout << testName << ": FAIL - Array sizes do not match. Expected size: "
                  << expected.size() << ", Actual size: " << actual.size() << std::endl;
        return; // Early return if sizes don't match
    }

    bool isEqual = true;
    for (size_t i = 0; i < expected.size(); ++i)
    {
        if (expected[i] != actual[i])
        {
            isEqual = false;
            break;
        }
    }

    std::cout << testName << ": " << (isEqual ? "PASS" : "FAIL") << std::endl;
    if (!isEqual)
    {
        std::cout << "Arrays do not match:" << std::endl;
        for (size_t i = 0; i < expected.size(); ++i)
        {
            std::cout << "At index " << i << " Expected: " << expected[i]
                      << ", Actual: " << actual[i] << std::endl;
        }
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

void testMedianBlur()
{
    unsigned char inputData[] = {
        50, 80, 50,
        80, 120, 80,
        50, 80, 50};

    unsigned char expectedOutput[] = {
        80, 80, 80,
        80, 80, 80,
        80, 80, 80};
    int width = 3, height = 3, channels = 1, kernelSize = 3;
    MedianBlurFilter medianFilter(kernelSize);
    medianFilter.apply(inputData, width, height, channels);

    std::vector<unsigned char> expectedVector(std::begin(expectedOutput), std::end(expectedOutput));
    std::vector<unsigned char> actualVector(std::begin(inputData), std::end(inputData));
    assertArrayEquals("2D MedianBlur Test:", expectedVector, actualVector);
}

void testQuickSelect()
{
    // Test cases
    // std::vector<unsigned char> test1 = {7, 10, 4, 3, 20, 15, 7};
    std::vector<unsigned char> test1 = {6, 5, 4, 3, 7, 1, 2};
    std::vector<unsigned char> test2 = {12, 3, 5, 7, 4, 19, 26};

    // Expected results
    unsigned char expected1 = 1;  // Assuming quickSelect is for finding kth smallest, and k1=1 means the smallest element
    unsigned char expected2 = 4;  // The median of test1
    unsigned char expected3 = 26; // The largest element in test2

    // Perform tests
    unsigned char result1 = quickSelect(test1, 0, test1.size() - 1, 1);
    unsigned char result2 = quickSelect(test1, 0, test1.size() - 1, test1.size() / 2 + 1); // Median is at position (size/2 + 1) for 1-based index
    unsigned char result3 = quickSelect(test2, 0, test2.size() - 1, test2.size());         // Largest element

    // Assert results
    assertEquals("Test QuickSelect: The smallest element", expected1, result1);
    assertEquals("Test QuickSelect: The median element", expected2, result2);
    assertEquals("Test QuickSelect: The largest element", expected3, result3);
}

void printImageData(const unsigned char *data, int width, int height, int channels)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                int index = (y * width + x) * channels + c;
                std::cout << static_cast<int>(data[index]) << " ";
            }
        }
        std::cout << std::endl;
    }
}

void testGaussianBlur()
{
    // Test data for Gaussian Blur
    unsigned char inputData[] = {
        1, 2, 50, 80, 50,
        3, 4, 80, 120, 80,
        5, 6, 50, 80, 50,
        7, 8, 9, 10, 11,
        12, 13, 14, 15, 16};

    // Expected output data after applying Gaussian Blur
    unsigned char expectedOutput[] = {
        1, 20, 51, 70, 69,
        3, 21, 52, 72, 70,
        5, 18, 40, 54, 53,
        7, 13, 22, 27, 27,
        10, 11, 12, 13, 13};

    int width = 5, height = 5, channels = 1, kernelsize = 3;
    // Uncomment to print input data
    // printImageData(inputData, width, height, channels);
    double sigma = 2.0;
    GaussianBlurFilter gaussianFilter(kernelsize, sigma);

    gaussianFilter.apply(inputData, width, height, channels);
    // Uncomment to print output data
    // printImageData(inputData, width, height, channels);

    // Convert the expected output data to a vector for easy comparison
    std::vector<unsigned char> expectedVector(std::begin(expectedOutput), std::end(expectedOutput));

    // Create a vector for the actual output data
    std::vector<unsigned char> actualVector(std::begin(inputData), std::end(inputData));

    // Assert if the actual output matches the expected output
    assertArrayEquals("2D GaussianBlur Test:", expectedVector, actualVector);
}

void testBoxBlur()
{
    // Test data for Box Blur
    unsigned char inputData[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16};

    // Expected output data after applying Box Blur
    unsigned char expectedOutput[] = {
        3, 4, 5, 6,
        6, 6, 7, 8,
        9, 10, 11, 11,
        11, 11, 12, 12};

    int width = 4, height = 4, channels = 1, kernelsize = 3;
    // Uncomment to print input data
    // printImageData(inputData, width, height, channels);
    BoxBlurFilter boxFilter(kernelsize);

    boxFilter.apply(inputData, width, height, channels);
    // Uncomment to print output data
    // printImageData(inputData, width, height, channels);

    // Convert the expected output data to a vector for easy comparison
    std::vector<unsigned char> expectedVector(std::begin(expectedOutput), std::end(expectedOutput));

    // Create a vector for the actual output data
    std::vector<unsigned char> actualVector(std::begin(inputData), std::end(inputData));

    // Assert if the actual output matches the expected output
    assertArrayEquals("2D BoxBlur Test:", expectedVector, actualVector);
}




// Generate a test image with left side black and right side white
void generateTestImage(std::vector<unsigned char>& image, int width, int height) {
    // Initialize the test image, left half black, right half white
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * 3;
            if (x < width / 2) {
                image[index] = image[index + 1] = image[index + 2] = 0; // Left half black
            } else {
                image[index] = image[index + 1] = image[index + 2] = 255; // Right half white
            }
        }
    }
}

void runFiltersTest() {
    const int width = 3, height = 3;
    std::vector<unsigned char> testImage(width * height * 3);
    generateTestImage(testImage, width, height);

    // List of filters
    std::vector<std::pair<std::string, std::unique_ptr<Filter>>> filters;
    filters.emplace_back("Sobel Filter Test ", std::make_unique<SobelFilter>());
    filters.emplace_back("Prewitt Filter Test ", std::make_unique<PrewittFilter>());
    filters.emplace_back("Scharr Filter Test ", std::make_unique<ScharrFilter>());
    filters.emplace_back("Robert Filter Test with the 1st Image", std::make_unique<RobertFilter>());

    // Iterate and test each filter
    for (auto& filterPair : filters) {
        std::vector<unsigned char> imageCopy = testImage; // Create a copy of the image for each filter
        filterPair.second->apply(imageCopy.data(), width, height, 3); // Apply the filter

        // Verify the pixel next to the edge, expecting the first pixel on the right to be white
        int testIndex = (height / 2 * width + width / 2) * 3;
        unsigned char edgeResponse = imageCopy[testIndex];

        // Use assertEquals for verification
        assertEquals<unsigned char>(filterPair.first, 255, edgeResponse);
    }
}



