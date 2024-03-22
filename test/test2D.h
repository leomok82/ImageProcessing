#ifndef TEST_2D_H
#define TEST_2D_H

#include <string>
#include "../src/ColourFilterCorrection.h"
#include "../src/EdgeDetectionFilter.h"
#include "../src/ImageBlurFilter.h"
#include "../src/Image.h"
#include "../src/Volume.h"

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
void testSobelFilter();
void testPrewittFilter();
void testScharrFilter();
void testRobertFilter();

#endif // TEST_2D_H
