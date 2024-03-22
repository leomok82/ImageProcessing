#ifndef TEST_H
#define TEST_H

#include <string>
#include "../src/new/ColourFilterCorrection.h"
#include "../src/new/ImageBlurFilter.h"
#include "../src/new/Image.h"
#include "../src/new/Volume.h"

// #include "../src/new/Image.h"
// #include "../src/new/EdgeDetectionFilter.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
void reportTest(const std::string& testName, bool result);

template<typename T, typename U>
void assertEquals(const std::string& testName, const T& expected, const U& actual);
template <typename T>
void assertArrayEquals(const std::string &testName, const std::vector<T> &expected, const std::vector<T> &actual);

void testGrayscaleFilter();
void testBrightnessFilter();
void testHistogramEqualizerFilter();
void testThresholdingFilter();
void testSaltAndPepperNoiseFilter();
void testGaussianBlur();
void testMedianBlur();
void testBoxBlur();
void testQuickSelect();
// void runFiltersTest();
void testSobelFilter();
void testPrewittFilter();
void testScharrFilter();
void testRobertFilter();


#endif // TEST_H
