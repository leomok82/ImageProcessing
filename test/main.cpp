#include <iostream>
#include <string>
#include "../src/new/ColourFilterCorrection.h"
#include "test2D.h"
#include "Test3D.h"
#include <cmath>
#include <numeric>

// complie using "g++ -o test test2D.cpp ../src/new/ColourFilterCorrection.cpp ../src/new/ColorConversion.cpp ../src/new/ImageBlurFilter.cpp
// ../src/new/EdgeDetectionFilter.cpp main.cpp -std=c++17 "
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

    // testLoadApplyAndSaveImage();
    return 0;
}


