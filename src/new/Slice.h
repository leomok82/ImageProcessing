/**
 * @file Slice.h
 * @brief This file contains the declaration of the Slice class.
 * 
 * The Slice class represents a 2D slice of a volume. It stores the width, height, and pixel data of the slice.
 * The class provides methods for creating slices from a volume, performing thin slab rendering, and saving the slice to a file.
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 */

#ifndef SLICE_H
#define SLICE_H

#include "Volume.h"
#include <vector>
#include <string>

class Slice {
    std::vector<unsigned char> data; /**< The pixel data of the slice */
    int width; /**< The width of the slice */
    int height; /**< The height of the slice */

public:
    /**
     * @brief Constructs a Slice object with the specified width, height, and pixel data.
     * 
     * @param width The width of the slice
     * @param height The height of the slice
     * @param data The pixel data of the slice
     */
    Slice(int width, int height, const std::vector<unsigned char>& data)
        : width(width), height(height), data(data) {}

    /**
     * @brief Creates a slice from a volume along a specified plane and coordinate.
     * 
     * @param volume The volume to create the slice from
     * @param plane The plane along which to slice the volume (e.g., "xy", "xz", "yz")
     * @param coordinate The coordinate value along the slicing plane
     * @return The created slice
     */
    static Slice fromVolume(const Volume& volume, const std::string& plane, int coordinate);

    /**
     * @brief Performs thin slab rendering using the Average Intensity Projection (AIP) method.
     * 
     * @param volume The volume to perform thin slab rendering on
     * @param startSlice The starting slice index
     * @param endSlice The ending slice index
     * @return The thin slab rendered slice
     */
    static Slice thinSlabAIP(const Volume& volume, int startSlice, int endSlice);

    /**
     * @brief Performs thin slab rendering using the Maximum Intensity Projection (MIP) method.
     * 
     * @param volume The volume to perform thin slab rendering on
     * @param startSlice The starting slice index
     * @param endSlice The ending slice index
     * @return The thin slab rendered slice
     */
    static Slice thinSlabMIP(const Volume& volume, int startSlice, int endSlice);

    /**
     * @brief Saves the slice to a file.
     * 
     * @param filePath The path of the file to save the slice to
     */
    void saveToFile(const std::string& filePath) const;

    /**
     * @brief Gets the width of the slice.
     * 
     * @return The width of the slice
     */
    int getWidth() const { return width; }

    /**
     * @brief Gets the height of the slice.
     * 
     * @return The height of the slice
     */
    int getHeight() const { return height; }

    /**
     * @brief Gets the pixel data of the slice.
     * 
     * @return The pixel data of the slice
     */
    std::vector<unsigned char> getData() const { return data; }
};

#endif // SLICE_H
