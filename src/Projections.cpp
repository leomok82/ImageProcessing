/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#include "Projections.h"
#include <vector>
#include <iostream>

std::vector<unsigned char> Projections::MinIP(const Volume& volume, int startSlice, int endSlice) {
    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice<= 0 || endSlice > depth || startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return result;
    }
    startSlice -= 1;
    endSlice -= 1;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            for (int c = 0; c < channels; c++) {
                int minVal = 256;
                int val;

                for (int z = startSlice; z <= endSlice; z++) {
                    // Get the maximum value for each pixel across the z-axis
                    val = volume.getVoxel(x,y,z);
                    minVal = (val < minVal) ? val : minVal;
                }
                result[(y*width+x)*channels +c] = minVal;
            }
           
        }
    }
    
    return result;

}



std::vector<unsigned char> Projections::MIP(const Volume& volume, int startSlice, int endSlice) {
    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice<= 0 || endSlice > depth|| startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return result;
    }
    startSlice -= 1;
    endSlice -= 1;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            for (int c = 0; c < channels; c++) {
                int maxVal = 0;
                int val;

                for (int z = startSlice; z <= endSlice; z++) {
                    // Get the maximum value for each pixel across the z-axis
                    val = volume.getVoxel(x,y,z);
                    if (val > maxVal) {
                        maxVal = val;
                    }
                
                }
                result[(y*width+x)*channels +c] = maxVal;
            }
        }
    }
    return result;

}

std::vector<unsigned char> Projections::AIP(const Volume& volume, int startSlice, int endSlice) {
    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice<= 0 || endSlice > depth|| startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return result;
    }
    startSlice -= 1;
    endSlice -= 1;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            for (int c = 0; c < channels; c++) {
                int sum = 0;

                for (int z = startSlice; z <= endSlice; z++) {
                    sum += volume.getVoxel(x,y,z);   
                }
                int layerCount = endSlice - startSlice + 1;
                result[(y * width + x) * channels + c] = static_cast<unsigned char>(sum / static_cast<float>(layerCount));
                //result[(y*width+x)*channels +c] = sum/(endSlice - startSlice);
            }
        }
    }
    return result;
}
