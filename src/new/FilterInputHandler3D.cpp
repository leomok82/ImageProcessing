// FilterInputHandler3D.cpp
#include "FilterInputHandler3D.h"
#include "Filter3D.h"
#include <iostream>

void FilterInputHandler3D::applyFilter(int filterType, Volume& volume) {
    std::unique_ptr<Filter3D> filter;

    switch (filterType) {
        case 1: {
            // 3D Gaussian Filter
            int kernelSize;
            std::cout << "Enter kernel size for 3D Gaussian Filter (e.g., 3 for 3x3x3): ";
            std::cin >> kernelSize;

            filter = std::make_unique<Gaussian3DFilter>(kernelSize);
            break;
        }
        case 2: {
            // 3D Median Filter
            int kernelSize;
            std::cout << "Enter kernel size for 3D Median Filter (e.g., 3 for 3x3x3): ";
            std::cin >> kernelSize;

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

    // Apply the selected filter to the volume
    filter->apply(volume);
    std::cout << "3D Filter applied successfully." << std::endl;
}
