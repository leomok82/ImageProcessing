// Projections.h
#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#include "Volume.h"
#include "Slice.h"

/**
 * @brief Applies the Minimum Intensity Projection (MinIP) to a volume.
 * 
 * Generates a 2D projection image from a specified range of slices in a 3D volume by taking the minimum intensity value 
 * across the z-axis (depth) for each pixel. This method is particularly useful for visualizing structures with low intensity.
 * 
 * @param volume The Volume object containing the volumetric data.
 * @param startSlice The starting slice index for the projection range.
 * @param endSlice The ending slice index for the projection range.
 * @return std::vector<unsigned char> A vector containing the pixel data of the generated 2D MinIP image.
 * 
 * @note The method returns an empty image (vector) if an invalid range is provided.
 */

/**
 * @brief Applies the Maximum Intensity Projection (MIP) to a volume.
 * 
 * Generates a 2D projection image from a specified range of slices in a 3D volume by taking the maximum intensity value 
 * across the z-axis (depth) for each pixel. MIP is widely used in medical imaging to enhance the visibility of high-intensity structures.
 * 
 * @param volume The Volume object containing the volumetric data.
 * @param startSlice The starting slice index for the projection range.
 * @param endSlice The ending slice index for the projection range.
 * @return std::vector<unsigned char> A vector containing the pixel data of the generated 2D MIP image.
 * 
 * @note The method returns an empty image (vector) if an invalid range is provided.
 */

/**
 * @brief Applies the Average Intensity Projection (AIP) to a volume.
 * 
 * Generates a 2D projection image from a specified range of slices in a 3D volume by averaging the intensity values
 * across the z-axis (depth) for each pixel. AIP can be used to visualize the average properties of the volume across a specific depth range.
 * 
 * @param volume The Volume object containing the volumetric data.
 * @param startSlice The starting slice index for the projection range.
 * @param endSlice The ending slice index for the projection range.
 * @return std::vector<unsigned char> A vector containing the pixel data of the generated 2D AIP image.
 * 
 * @note The method returns an empty image (vector) if an invalid range is provided.
 */

class Projections {
public:
    // Static methods for creating projections from a volume
    static std::vector<unsigned char> AIP(const Volume& volume, int startSlice, int endSlice);
    static std::vector<unsigned char> MIP(const Volume& volume, int startSlice, int endSlice);
    static std::vector<unsigned char> MinIP(const Volume& volume, int startSlice, int endSlice);
};

#endif // PROJECTIONS_H
