/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#include "ProjectionInputHandler.h"
#include "Projections.h"
#include "Filter3D.h"
#include <iostream>

std::__1::vector<unsigned char> ProjectionInputHandler::applyProjection(Volume& volume) {
    //Projection application
    std::cout << "Select the type of projection to apply:" << std::endl;
    std::cout << "1. Max IP" << std::endl;
    std::cout << "2. Min IP" << std::endl;
    std::cout << "3. Average IP" << std::endl;
    int projectionType;
    std::cin >> projectionType;

    if (projectionType < 1 || projectionType > 3) {
        std::cerr << "Invalid projection type selected." << std::endl;
    }
    // Get the range of slices for the projection
    int endSlice;
    int startSlice;
    
    std:: cout << "Enter the lower limit of slices for the projection: " << std::endl;
    
    std::cin >> startSlice;
    std:: cout << "Enter the upper limit of slices for the projection: " << std::endl;
    
    std::cin >> endSlice;

    // output vector
    std::vector<unsigned char> output;

    // Apply the selected projection
    switch(projectionType) {
        case 1:
            output = Projections::MIP(volume, startSlice, endSlice);
            break;
        case 2:
            output = Projections::MinIP(volume, startSlice, endSlice);
            break;
        case 3:
            output = Projections::AIP(volume, startSlice, endSlice);
            break;
        default:
            std::cerr << "Invalid projection type selected." << std::endl;
            break;
    }  

    return output; 
}
