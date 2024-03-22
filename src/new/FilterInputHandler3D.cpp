// FilterInputHandler3D.cpp
#include "FilterInputHandler3D.h"
#include "Filter3D.h"
#include <iostream>

void FilterInputHandler3D::applyFilter(Volume& volume) {
    std::unique_ptr<Filter3D> filter;
    int kernelSize;

    // Filter Application
    std::cout << "Select the type of 3D filter to apply:" << std::endl;
    std::cout << "1. 3D Gaussian Filter" << std::endl;
    std::cout << "2. 3D Median Filter" << std::endl;
    int filterType;
    std::cin >> filterType;

    std::cout << "Enter kernel size for the 3D Filter (3 for 3x3x3, 5 for 5x5x5): ";
    std::cin >> kernelSize;
    if (kernelSize != 3 && kernelSize != 5) {
        std::cerr << "Invalid kernel size. Please enter 3 or 5." << std::endl;
        return; // Early exit if invalid kernel size is entered
    }

    switch (filterType) {
        case 1: { // 3D Gaussian Filter
            filter = std::make_unique<Gaussian3DFilter>(kernelSize);
            break;
        }
        case 2: { // 3D Median Filter - Placeholder
            filter = std::make_unique<Median3DFilter>(kernelSize); 
            break;
        }
        default:
            std::cerr << "Invalid 3D filter type provided." << std::endl;
            return;
    }

    if (!filter) {
        std::cerr << "Failed to create 3D filter." << std::endl;
        return;
    }

    filter->apply(volume);
    std::cout << "3D Filter applied successfully." << std::endl;
}
