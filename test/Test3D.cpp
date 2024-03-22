#include "Test3D.h"
#include <exception>
#include <cassert>

TestSuite globalTestSuite;

void TestSuite::addTest(Test *test)
{
    tests.push_back(test);
}

void TestSuite::runAll()
{
    int passedTests = 0;
    for (auto &test : tests)
    {
        std::cout << "Running " << test->getName() << "... ";
        try
        {
            test->run();
            std::cout << "Passed" << std::endl;
            ++passedTests;
        }
        catch (const std::exception &e)
        {
            std::cout << "Failed: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "Failed: Unknown exception caught" << std::endl;
        }
    }
    std::cout << "TestsFor3D_Summary: " << passedTests << "/" << tests.size() << " tests passed." << std::endl;
}

TEST_CASE(TestGetVoxel)
{
    Volume volume;
    // Simulate a simple 3x3x3 volume data
    int w = 3, h = 3, d = 3;
    std::vector<unsigned char> simulatedData(w * h * d, 0);
    // Set voxel value to 255 at position (1, 1, 1)
    simulatedData[1 * w * h + 1 * w + 1] = 255;
    volume.setData(simulatedData);
    volume.setDimensions(w, h, d); // Set dimensions

    ASSERT_TRUE(volume.getVoxel(1, 1, 1) == 255, "Voxel value at (1, 1, 1) should be 255");
}

TEST_CASE(TestGetDimensionsAndGetData)
{
    Volume volume;

    int expectedWidth = 5, expectedHeight = 5, expectedDepth = 5;
    std::vector<unsigned char> simulatedData(expectedWidth * expectedHeight * expectedHeight, 75);
    volume.setData(simulatedData); // setData method only sets data, not dimensions
    int w, h, d;
    volume.setDimensions(expectedWidth, expectedHeight, expectedDepth);
    volume.getDimensions(w, h, d); // Get dimensions
    const std::vector<unsigned char> &volumeData = volume.getData();

    ASSERT_TRUE(volumeData == simulatedData, "Volume data should match the expected data");
    ASSERT_TRUE(w == expectedWidth && h == expectedHeight && d == expectedDepth, "Volume dimensions should match the expected values");
}

// Test Slice
TEST_CASE(TestSliceFromVolumeXY)
{
    Volume volume;
    volume.setDimensions(5, 5, 5);
    std::vector<unsigned char> data(5 * 5 * 5);
    // Fill to make each z layer's value incrementally, z=0: xy:1....; z=1: xy:2.......
    for (int z = 0; z < 5; ++z)
    {
        std::fill_n(data.begin() + z * 25, 25, z + 1);
    }
    volume.setData(data);

    // Extract the xy plane slice at z=1
    Slice sliceXY = Slice::fromVolume(volume, "xy", 2); // Using 1-based coordinates, so it's 2 here

    ASSERT_TRUE(sliceXY.getWidth() == 5 && sliceXY.getHeight() == 5, "Slice dimensions for xy plane should be 5x5");
    const auto &sliceDataXY = sliceXY.getData();

    // Further verification can be done on sliceDataXY's specific values
    for (auto value : sliceDataXY)
    {
        ASSERT_TRUE(value == 2, "All voxel values in the xy slice at z=1 should be 2");
    }
}

TEST_CASE(TestSliceFromVolumeYZ)
{
    Volume volume;
    volume.setDimensions(5, 5, 5);
    std::vector<unsigned char> data(5 * 5 * 5);
    // Fill to make each x position's value different
    for (int x = 0; x < 5; ++x)
    {
        for (int z = 0; z < 5; ++z)
        {
            for (int y = 0; y < 5; ++y)
            {
                data[z * 25 + y * 5 + x] = x + 1;
            }
        }
    }
    volume.setData(data);

    // Extract the yz plane slice at x=3
    Slice sliceYZ = Slice::fromVolume(volume, "yz", 4); // Using 1-based coordinates, so it's 4 here

    ASSERT_TRUE(sliceYZ.getWidth() == 5 && sliceYZ.getHeight() == 5, "Slice dimensions for yz plane should be 5x5");
    const auto &sliceDataYZ = sliceYZ.getData();

    // Further verification can be done on sliceDataYZ's specific values
    for (auto value : sliceDataYZ)
    {
        ASSERT_TRUE(value == 4, "All voxel values in the yz slice at x=3 should be 4");
    }
}

TEST_CASE(TestSliceFromVolumeXZ)
{
    Volume volume;
    volume.setDimensions(5, 5, 5);
    std::vector<unsigned char> data(5 * 5 * 5);
    // Fill to make each y position's value different
    for (int y = 0; y < 5; ++y)
    {
        for (int z = 0; z < 5; ++z)
        {
            std::fill_n(data.begin() + z * 25 + y * 5, 5, y + 1);
        }
    }
    volume.setData(data);

    // Extract the xz plane slice at y=5
    Slice sliceXZ = Slice::fromVolume(volume, "xz", 5); // Using 1-based coordinates, so it's 5 here

    ASSERT_TRUE(sliceXZ.getWidth() == 5 && sliceXZ.getHeight() == 5, "Slice dimensions for xz plane should be 5x5");
    const auto &sliceDataXZ = sliceXZ.getData();

    // Further verification can be done on sliceDataXZ's specific values
    for (auto value : sliceDataXZ)
    {
        ASSERT_TRUE(value == 5, "All voxel values in the xz slice at y=5 should be 5");
    }
}

void PrintVolumeData(const Volume &volume)
{
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::cout << "Volume Data:" << std::endl;
    for (int z = 0; z < depth; ++z)
    {
        std::cout << "Layer " << z << ":" << std::endl;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                std::cout << static_cast<int>(volume.getVoxel(x, y, z)) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

TEST_CASE(TestThinSlabAIP)
{
    Volume volume;
    int width = 3, height = 3, depth = 3;
    std::vector<unsigned char> data(width * height * depth);

    // Simulate filling Volume data: the first layer value is 1, the second layer is 2, the third layer is 3
    for (int z = 0; z < depth; ++z){
        std::fill_n(data.begin() + z * width * height, width * height, static_cast<unsigned char>(z + 1));
    }

    volume.setData(data);
    volume.setDimensions(width, height, depth);
    // std::cout << "Volume:" << std::endl;
    // PrintVolumeData(volume);

    // Calculate AIP
    Slice aipSlice = Slice::thinSlabAIP(volume, 0, 2); // Assuming 0-based indexing here

    // Verify AIP results
    const auto &aipData = aipSlice.getData();
    // std::cout << aipData.size() << std::endl;
    // std::cout << "AIP Data:" << std::endl;
    // for (int y = 0; y < height; ++y) {
    //     for (int x = 0; x < width; ++x) {
    //         std::cout << static_cast<int>(aipData[y * width + x]) << " ";
    //     }
    //     std::cout << std::endl; // New line for separating different rows
    // }
    unsigned char expectedValue = 2; // Since we used layers 1,2,3 for averaging, the expected result should be 2
    bool isValid = std::all_of(aipData.begin(), aipData.end(), [expectedValue](unsigned char val)
                               { return val == expectedValue; });

    ASSERT_TRUE(isValid, "AIP calculation is incorrect.");
}

TEST_CASE(TestThinSlabMIP)
{
    Volume volume;
    int width = 3, height = 3, depth = 3;
    std::vector<unsigned char> data(width * height * depth);

    // Simulate filling Volume data: the first layer value is 1, the second layer is 2, the third layer is 3
    for (int z = 0; z < depth; ++z){
        std::fill_n(data.begin() + z * width * height, width * height, static_cast<unsigned char>(z + 1));
    }

    volume.setData(data);
    volume.setDimensions(width, height, depth);
    // Calculate AIP
    Slice aipSlice = Slice::thinSlabMIP(volume, 0, 2);

    // Verify AIP results
    const auto &aipData = aipSlice.getData();
    unsigned char expectedValue = 3; // Since we used layers 1,2,3 for averaging, the expected max result should be 3
    bool isValid = std::all_of(aipData.begin(), aipData.end(), [expectedValue](unsigned char val)
                               { return val == expectedValue; });

    ASSERT_TRUE(isValid, "MIP calculation is incorrect.");
}
TEST_CASE(Test3DMedianFilter){
    Volume volume;
    int width = 4, height = 4, depth = 4;
    std::vector<unsigned char> inputData = {
        // Layer 0
        50, 20, 30, 100, 120, 80, 90, 150, 70, 10, 5, 60, 170, 130, 110, 40,
        // Layer 1
        120, 60, 25, 75, 35, 140, 160, 90, 180, 240, 85, 110, 100, 15, 40, 95,
        // Layer 2
        45, 90, 55, 130, 65, 110, 95, 180, 140, 40, 150, 25, 60, 175, 120, 185,
        // Layer 3
        80, 180, 20, 160, 190, 75, 70, 120, 25, 100, 30, 140, 110, 60, 175, 90};

    std::vector<unsigned char> expectedData = {

        50, 50, 75, 90, 70, 70, 80, 90, 120, 90, 90, 90, 130, 110, 60, 60,
        60, 60, 90, 95, 70, 80, 90, 90, 100, 100, 95, 95, 100, 110, 95, 95,
        80, 75, 90, 95, 90, 85, 95, 110, 100, 100, 100, 110, 100, 100, 95, 95,
        80, 80, 110, 130, 80, 75, 100, 120, 100, 95, 100, 120, 100, 110, 100, 120};

    volume.setData(inputData);
    volume.setDimensions(width, height, depth);
    // Create Median3DFilter instance and apply median filter
    Median3DFilter medianFilter(3); // Using a 3x3x3 kernel
    medianFilter.apply(volume);

    // Get the filtered data
    const auto &filteredData = volume.getData();
    double maxRelativeError = 1e-9; //

    for (size_t i = 0; i < filteredData.size(); ++i){
        // Avoid division by zero
        if (expectedData[i] != 0){
            double diff = std::abs(filteredData[i] - expectedData[i]);
            // Convert expected value to double for calculation to avoid integer division
            double relativeError = diff / static_cast<double>(expectedData[i]);

            // Check if the relative error exceeds the maximum tolerance
            ASSERT_TRUE(relativeError <= maxRelativeError, "result does not match expected values");
        }
        else{
            // If the expected value is 0, compare the filtered value directly with the expected value
            ASSERT_TRUE(filteredData[i] == expectedData[i], "The result does not match expected values");
        }
    }
}
TEST_CASE(Test3DGaussianFilter){
    Volume volume;
    int width = 4, height = 4, depth = 4;
    std::vector<unsigned char> inputData = {
        // Layer 0
        50, 20, 30, 100, 120, 80, 90, 150, 70, 10, 5, 60, 170, 130, 110, 40,
        // Layer 1
        120, 60, 25, 75, 35, 140, 160, 90, 180, 240, 85, 110, 100, 15, 40, 95,
        // Layer 2
        45, 90, 55, 130, 65, 110, 95, 180, 140, 40, 150, 25, 60, 175, 120, 185,
        // Layer 3
        80, 180, 20, 160, 190, 75, 70, 120, 25, 100, 30, 140, 110, 60, 175, 90};

    std::vector<unsigned char> expectedData = {
        // Layer 0
        68, 56, 63, 88, 84, 74, 77, 93, 104, 87, 76, 79, 123, 98, 73, 62,
        // Layer 1
        74, 69, 74, 92, 92, 93, 95, 99, 110, 105, 98, 95, 111, 98, 89, 90,
        // Layer 2
        86, 84, 88, 107, 97, 97, 99, 107, 102, 104, 106, 108, 95, 101, 109, 115,
        // Layer 3
        104, 97, 95, 117, 103, 91, 91, 111, 91, 89, 96, 110, 85, 99, 114, 118};

    volume.setData(inputData);
    volume.setDimensions(width, height, depth);
    // Create Gaussian3DFilter instance and apply Gaussian filter
    Gaussian3DFilter gaussianFilter(3); // Using a 3x3x3 kernel
    gaussianFilter.apply(volume);

    // Get the filtered data
    const auto &filteredData = volume.getData();
    double maxRelativeError = 0.15; //

    for (size_t i = 0; i < filteredData.size(); ++i){
        // Avoid division by zero
        if (expectedData[i] != 0){
            double diff = std::abs(filteredData[i] - expectedData[i]);
            // Convert expected value to double for calculation to avoid integer division
            double relativeError = diff / static_cast<double>(expectedData[i]);

            // Check if the relative error exceeds the maximum tolerance
            ASSERT_TRUE(relativeError <= maxRelativeError, "result does not match expected values");
        }
        else{
            // If the expected value is 0, compare the filtered value directly with the expected value
            ASSERT_TRUE(filteredData[i] == expectedData[i], "The result does not match expected values");
        }
    }
}

// Projection
TEST_CASE(TestProjectionMinIP)
{
    Volume volume;
    int width = 3, height = 3, depth = 3;
    std::vector<unsigned char> data(width * height * depth);

    // Simulate filling Volume data: the first layer value is 1, the second layer is 2, the third layer is 3
    for (int z = 0; z < depth; ++z){
        std::fill_n(data.begin() + z * width * height, width * height, static_cast<unsigned char>(z + 1));
    }

    volume.setData(data);
    volume.setDimensions(width, height, depth);
    // Calculate MinIP
    auto minIPResult = Projections::MinIP(volume, 1, 3);
    //auto minIPResult = Projections::MinIP(volume, 0, 2);

    // Verify  results
    // Expect:1
    for (size_t i = 0; i < minIPResult.size(); i += 3){
        ASSERT_TRUE(minIPResult[i] == 1 && minIPResult[i + 1] == 1 && minIPResult[i + 2] == 1,
                    "MinIP result does not match expected values.");
    }
}

TEST_CASE(TestProjectionMIP)
{
    Volume volume;
    int width = 3, height = 3, depth = 3;
    std::vector<unsigned char> data(width * height * depth);

    // Simulate filling Volume data: the first layer value is 1, the second layer is 2, the third layer is 3
    for (int z = 0; z < depth; ++z){
        std::fill_n(data.begin() + z * width * height, width * height, static_cast<unsigned char>(z + 1));
    }

    volume.setData(data);
    volume.setDimensions(width, height, depth);
    // Calculate MIP
    auto MIPResult = Projections::MIP(volume, 1, 3);
    //auto MIPResult = Projections::MIP(volume, 0, 2);

    // Verify  results
    for (size_t i = 0; i < MIPResult.size(); i += 3){
        ASSERT_TRUE(MIPResult[i] == 3 && MIPResult[i + 1] == 3 && MIPResult[i + 2] == 3,
                    "MIP result does not match expected values.");
    }
}

TEST_CASE(TestProjectionAIP)
{
    Volume volume;
    int width = 3, height = 3, depth = 3;
    std::vector<unsigned char> data(width * height * depth);

    // Simulate filling Volume data: the first layer value is 1, the second layer is 2, the third layer is 3
    for (int z = 0; z < depth; ++z){
        std::fill_n(data.begin() + z * width * height, width * height, static_cast<unsigned char>(z + 1));
    }

    volume.setData(data);
    volume.setDimensions(width, height, depth);
    // Calculate AIP
    auto AIPResult = Projections::AIP(volume, 1, 3);
    //auto AIPResult = Projections::AIP(volume, 0, 2);

    // Verify  results
    for (size_t i = 0; i < AIPResult.size(); i += 3){
        ASSERT_TRUE(AIPResult[i] == 2 && AIPResult[i + 1] == 2 && AIPResult[i + 2] == 2,
                    "AIP result does not match expected values.");
    }
}
