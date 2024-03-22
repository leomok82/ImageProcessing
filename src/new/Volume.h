/**
 * @file Volume.h
 * @brief This file contains the declaration of the Volume class.
 * 
 * The Volume class represents a 3D volume and provides methods to load, access, and manipulate the volume data.
 * It also provides methods to save slices of the volume as images.
 * 
 * @ingroup Yen
 * 
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef VOLUME_H
#define VOLUME_H

#include <vector>
#include <string>
#include <filesystem>
#include "Image.h" // Update to include Image.h instead of stb_image.h

class Volume {
public:
    /**
     * @brief Default constructor for the Volume class.
     */
    Volume();

    /**
     * @brief Destructor for the Volume class.
     */
    ~Volume();

    /**
     * @brief Loads the volume data from the specified folder.
     * 
     * @param folderpath The path to the folder containing the volume data files.
     * @return True if the volume data is loaded successfully, false otherwise.
     */
    bool loadFromFolder(const std::string& folderpath);

    /**
     * @brief Gets the voxel value at the specified coordinates.
     * 
     * @param x The x-coordinate of the voxel.
     * @param y The y-coordinate of the voxel.
     * @param z The z-coordinate of the voxel.
     * @return The voxel value at the specified coordinates.
     */
    unsigned char getVoxel(int x, int y, int z) const;

    /**
     * @brief Gets the dimensions of the volume.
     * 
     * @param width The width of the volume.
     * @param height The height of the volume.
     * @param depth The depth of the volume.
     */
    void getDimensions(int& width, int& height, int& depth) const;

    /**
     * @brief Gets the raw data of the volume.
     * 
     * @return A const reference to the raw data of the volume.
     */
    const std::vector<unsigned char>& getData() const;

    /**
     * @brief Sets the raw data of the volume.
     * 
     * @param newData The new raw data of the volume.
     */
    void setData(const std::vector<unsigned char>& newData);

    /**
     * @brief Saves slices of the volume as images.
     */
    void saveSlices() const;

    /**
     * @brief Sets the dimensions of the volume.
     * 
     * @param w The new width of the volume.
     * @param h The new height of the volume.
     * @param d The new depth of the volume.
     */
    void setDimensions(int w, int h, int d); 

private:
    std::vector<unsigned char> data; /**< The raw data of the volume. */
    int width; /**< The width of the volume. */
    int height; /**< The height of the volume. */
    int depth; /**< The depth of the volume. */
};

#endif // VOLUME_H
