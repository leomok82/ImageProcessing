#include <iostream>
#include <string>
#include "../src/new/ColourFilterCorrection.h"
#include "test2D.h"
#include "Test3D.h"
#include <cmath>
#include <numeric>

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
    //3D Tests
    globalTestSuite.runAll();

    // testLoadApplyAndSaveImage();
    return 0;
}


