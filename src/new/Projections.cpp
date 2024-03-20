// Projections.cpp
#include "Projections.h"
#include <vector>
#include <iostream>

Slice Projections::MinIP(const Volume& volume, int startSlice, int endSlice) {
    std::cout << "Dummy MinIP from slices " << startSlice << " to " << endSlice << std::endl;

    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice< 0 || endSlice > depth || startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return;
    }
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int c = 0; c < channels; c++)
            {
                int minVal = 256;
                int val;

                for (int z = startSlice; z < endSlice; z++)
                {
                    // Get the maximum value for each pixel across the z-axis
                    val = volume.getVoxel(x,y,z);
                    
                        if (val < minVal)
                        {
                            minVal = val;
                        }
                
                }
                result[(y*width+x)*channels +c] = minVal;
            }
           
        }
    }
    

    return Slice(width, height, result);

}



Slice Projections::MIP(const Volume& volume, int startSlice, int endSlice) {
    std::cout << "Dummy MIP from slices " << startSlice << " to " << endSlice << std::endl;
    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice< 0 || endSlice > depth|| startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return;
    }
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int c = 0; c < channels; c++)
            {
                int maxVal = 0;
                int val;

                for (int z = startSlice; z < endSlice; z++)
                {
                    // Get the maximum value for each pixel across the z-axis
                    val = volume.getVoxel(x,y,z);
                    
                        if (val > maxVal)
                        {
                            maxVal = val;
                        }
                
                }
                result[(y*width+x)*channels +c] = maxVal;
            }
        }
    }
    return Slice(width, height, result);

}

Slice Projections::MinIP(const Volume& volume, int startSlice, int endSlice) {
    //set the dimensions
    int channels = 3;
    int width, height, depth;
    volume.getDimensions(width, height, depth);

    std::vector<unsigned char> result(width * height*channels, 0);
    // Create an empty image to store the result

    if (startSlice< 0 || endSlice > depth|| startSlice > endSlice){
        std::cerr << "Invalid range provided." << std::endl;
        return;
    }
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int c = 0; c < channels; c++)
            {
                int sum = 0;

                for (int z = startSlice; z < endSlice; z++)
                {
                    // Get the maximum value for each pixel across the z-axis
                    sum += volume.getVoxel(x,y,z);
                    
                }
                result[(y*width+x)*channels +c] = sum/(endSlice - startSlice);
            }
        }
    }
    return Slice(width, height, result);
}
