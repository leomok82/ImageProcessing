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

/**
 * @brief Destructor for Volume.
 */

/**
 * @brief Loads volumetric data from a directory of image files.
 * 
 * This method loads images from a specified folder, assuming each image represents a single slice of the volume. 
 * It supports multiple image formats and orders the slices based on filename sorting. Only files with extensions 
 * matching the allowed set (.png, .jpg, .jpeg, .bmp, .tiff) are loaded.
 * 
 * @param folderpath The path to the folder containing the slice images.
 * @return bool True if the volume is loaded successfully, false otherwise.
 */

/**
 * @brief Retrieves the intensity value of a specific voxel in the volume.
 * 
 * This method calculates the voxel's linear index based on its x, y, and z coordinates and returns its intensity value. 
 * It performs bounds checking to ensure the requested coordinates are within the volume. If out of bounds, an error 
 * message is printed, and a default value of 0 is returned.
 * 
 * @param x The x-coordinate of the voxel.
 * @param y The y-coordinate of the voxel.
 * @param z The z-coordinate of the voxel.
 * @return unsigned char The intensity value of the specified voxel.
 */

/**
 * @brief Gets the dimensions of the volume.
 * 
 * Fills the provided references with the width, height, and depth of the volume, respectively.
 * 
 * @param w Reference to where the width will be stored.
 * @param h Reference to where the height will be stored.
 * @param d Reference to where the depth will be stored.
 */

/**
 * @brief Gets a reference to the volume data.
 * 
 * @return const std::vector<unsigned char>& A constant reference to the volume's data vector.
 */

/**
 * @brief Saves each slice of the volume as an image file.
 * 
 * Iterates through each z-level of the volume, saving each slice to a separate image file. The filenames are generated 
 * sequentially with leading zeros to maintain order. The method prompts the user for an output folder path where the 
 * slice images will be saved. The folder is created if it does not exist.
 */

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
