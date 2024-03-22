#ifndef SLICE_H
#define SLICE_H

#include "Volume.h"
#include <vector>
#include <string>

/**
 * @brief Generates a slice from a 3D volume based on the specified plane and coordinate.
 * 
 * Extracts a 2D slice from a given 3D volume along one of three orthogonal planes (XY, XZ, or YZ)
 * at a specified coordinate. The plane is defined by the user, and the coordinate specifies the 
 * depth along the axis perpendicular to the chosen plane.
 * 
 * @param volume The source Volume object from which the slice is extracted.
 * @param plane A string indicating the plane of the slice: "xy", "xz", or "yz".
 * @param coordinate The coordinate along the axis perpendicular to the slice plane.
 *                  Note: Assumes 1-based indexing as provided by users, but adjusts to 0-based indexing internally.
 * @return Slice An instance of the Slice class containing the extracted slice data.
 */

/**
 * @brief Generates a thin slab using Average Intensity Projection (AIP) from a volume.
 * 
 * Calculates the AIP within a specified range of slices in the volume. This method averages the 
 * intensity values across the specified z-axis range for each pixel, effectively compressing a 
 * 3D volume into a 2D representation.
 * 
 * @param volume The Volume object from which the slab is generated.
 * @param startSlice The first slice in the range to include in the projection.
 * @param endSlice The last slice in the range to include in the projection.
 * @return Slice An instance of the Slice class containing the AIP data.
 */

/**
 * @brief Generates a thin slab using Maximum Intensity Projection (MIP) from a volume.
 * 
 * Identifies the maximum intensity value for each pixel across a specified range of slices and 
 * creates a 2D representation based on these maximum values. MIP is particularly useful for 
 * visualizing high-intensity structures within the volume.
 * 
 * @param volume The Volume object from which the slab is generated.
 * @param startSlice The first slice in the range to include in the projection.
 * @param endSlice The last slice in the range to include in the projection.
 * @return Slice An instance of the Slice class containing the MIP data.
 */

/**
 * @brief Saves the slice data to a file in PNG format.
 * 
 * Writes the slice's pixel data to the specified file path as a grayscale PNG image. This method 
 * uses the STB Image Write library for image saving functionalities.
 * 
 * @param filePath The file path where the slice image will be saved.
 */

class Slice {
    std::vector<unsigned char> data;
    int width, height;

public:
    Slice(int width, int height, const std::vector<unsigned char>& data)
        : width(width), height(height), data(data) {}

    // Adjusted for flexibility in slicing along different planes
    static Slice fromVolume(const Volume& volume, const std::string& plane, int coordinate);

    static Slice thinSlabAIP(const Volume& volume, int startSlice, int endSlice);
    static Slice thinSlabMIP(const Volume& volume, int startSlice, int endSlice);

    void saveToFile(const std::string& filePath) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::vector<unsigned char> getData() const { return data; }
};

#endif // SLICE_H
