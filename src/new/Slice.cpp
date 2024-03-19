// Slice.cpp
#include "Slice.h"
#include "Volume.h"
#include <algorithm> // For std::clamp

// Static factory method implementation
Slice Slice::fromVolume(const Volume& volume, const std::string& plane, int index) {
    int width, height, depth;
    volume.getDimensions(width, height, depth);
    std::vector<unsigned char> sliceData;

    if (plane == "xz") {
        sliceData.resize(width * depth);
        for (int z = 0; z < depth; ++z) {
            for (int x = 0; x < width; ++x) {
                sliceData[z * width + x] = volume.getVoxel(x, index, z);
            }
        }
        return Slice(width, depth, sliceData);
    } else if (plane == "yz") {
        sliceData.resize(height * depth);
        for (int z = 0; z < depth; ++z) {
            for (int y = 0; y < height; ++y) {
                sliceData[z * height + y] = volume.getVoxel(index, y, z);
            }
        }
        return Slice(height, depth, sliceData);
    }
    // Handle other planes if necessary

    // Return an empty slice if plane is unrecognized or in case of an error
    return Slice(0, 0, {});
}

// Add to Slice.cpp
#include <numeric> // For std::accumulate

Slice Slice::thinSlabAIP(const Volume& volume, int startSlice, int endSlice) {
    int width, height, depth;
    volume.getDimensions(width, height, depth);
    std::vector<unsigned char> projectionData(width * height, 0);

    for (int z = startSlice; z <= endSlice; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                projectionData[y * width + x] += volume.getVoxel(x, y, z) / static_cast<float>(endSlice - startSlice + 1);
            }
        }
    }

    return Slice(width, height, projectionData);
}

Slice Slice::thinSlabMIP(const Volume& volume, int startSlice, int endSlice) {
    int width, height, depth;
    volume.getDimensions(width, height, depth);
    std::vector<unsigned char> projectionData(width * height, 0);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char maxIntensity = 0;
            for (int z = startSlice; z <= endSlice; ++z) {
                unsigned char voxelValue = volume.getVoxel(x, y, z);
                if (voxelValue > maxIntensity) {
                    maxIntensity = voxelValue;
                }
            }
            projectionData[y * width + x] = maxIntensity;
        }
    }

    return Slice(width, height, projectionData);
}
