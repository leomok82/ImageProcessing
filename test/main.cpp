#include <iostream>
#include <string>
#include "../src/ColourFilterCorrection.h"
#include "test2D.h"
#include "Test3D.h"
#include <cmath>
#include <numeric>

// complie using "g++ -o test test2D.cpp ../src/ColourFilterCorrection.cpp ../src/ColorConversion.cpp ../src/ImageBlurFilter.cpp
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
    testSobelFilter();
    testPrewittFilter();
    testScharrFilter();
    testRobertFilter();
    //3D Tests
    globalTestSuite.runAll();
    return 0;
}


