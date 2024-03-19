#ifndef TEST_H
#define TEST_H

#include <string>
#include "../src/new/ColourFilterCorrection.h"
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

void testGrayscaleFilter();
void testBrightnessFilter();
void testHistogramEqualizerFilter();
void testThresholdingFilter();
void testSaltAndPepperNoiseFilter();


#endif // TEST_H
