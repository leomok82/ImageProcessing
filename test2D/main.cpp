#include <iostream>
#include <string>
#include "../src/new/ColourFilterCorrection.h"
#include "test.h"
#include <cmath>
#include <numeric>

// "g++ -o test test.cpp ../src/new/ColourFilterCorrection.cpp ../src/new/ColorConversion.cpp ../src/new/ImageBlurFilter.cpp main.cpp -std=c++17" to use this test.
int main() {
    testGrayscaleFilter();
    testBrightnessFilter();
    testHistogramEqualizerFilter();
    testThresholdingFilter();
    testSaltAndPepperNoiseFilter();
    testMedianBlur();
    testQuickSelect();
    testGaussianBlur();
    testBoxBlur();
    // runFiltersTest();
    testSobelFilter();
    testPrewittFilter();
    testScharrFilter();
    testRobertFilter();

    // testLoadApplyAndSaveImage();
    return 0;
}


