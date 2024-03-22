#include <iostream>
#include <string>
#include "../src/new/ColourFilterCorrection.h"
#include "test2D.h"
#include <cmath>
#include <numeric>
x
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


