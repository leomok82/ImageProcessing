/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#include "Slice.h"
#include "Volume.h"
#include <algorithm> // For std::clamp
#include <numeric> // For std::accumulate

#include "Slice.h"
#include "Volume.h"
#include <vector>
#include <string>
#include "stb_image_write.h"

Slice Slice::fromVolume(const Volume& volume, const std::string& plane, int coordinate) {
    int width, height, depth;
    volume.getDimensions(width, height, depth);
    std::vector<unsigned char> sliceData;

    // Adjust for 1-based indexing provided by users
    coordinate -= 1;

    if (plane == "xz") {
        sliceData.resize(width * depth);
        for (int z = 0; z < depth; ++z) {
            for (int x = 0; x < width; ++x) {
                sliceData[z * width + x] = volume.getVoxel(x, coordinate, z);
            }
        }
        return Slice(width, depth, sliceData);
    } else if (plane == "yz") {
        sliceData.resize(height * depth);
        for (int z = 0; z < depth; ++z) {
            for (int y = 0; y < height; ++y) {
                sliceData[z * height + y] = volume.getVoxel(coordinate, y, z);
            }
        }
        return Slice(height, depth, sliceData);
    } else if (plane == "xy") {
        // Assuming "xy" slicing is essentially getting a single slice as originally provided in the volume
        sliceData.resize(width * height);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                sliceData[y * width + x] = volume.getVoxel(x, y, coordinate);
            }
        }
        return Slice(width, height, sliceData);
    }

    return Slice(0, 0, {});
}


Slice Slice::thinSlabAIP(const Volume& volume, int startSlice, int endSlice) {
    int width, height, depth;
    volume.getDimensions(width, height, depth);
    std::vector<unsigned char> projectionData(width * height, 0);
    std::vector<float> tempProjectionData(width * height, 0.0f);

    for (int z = startSlice; z <= endSlice; ++z) {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                //projectionData[y * width + x] += volume.getVoxel(x, y, z) / static_cast<float>(endSlice - startSlice + 1);
                tempProjectionData[y * width + x] += static_cast<float>(volume.getVoxel(x, y, z));
            }
        }
    }
    for (size_t i = 0; i < tempProjectionData.size(); ++i){
        projectionData[i] = static_cast<unsigned char>(tempProjectionData[i] / static_cast<float>(endSlice - startSlice + 1));
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

void Slice::saveToFile(const std::string& filePath) const {
    stbi_write_png(filePath.c_str(), width, height, 1, data.data(), width);
}
