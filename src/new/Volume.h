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
    Volume();
    ~Volume();

    bool loadFromFolder(const std::string& folderpath);
    unsigned char getVoxel(int x, int y, int z) const;
    void getDimensions(int& width, int& height, int& depth) const;
    const std::vector<unsigned char>& getData() const;
    void setData(const std::vector<unsigned char>& newData);
    void saveSlices() const;
    void setDimensions(int w, int h, int d); 

private:
    std::vector<unsigned char> data;
    int width, height, depth;
};

#endif // VOLUME_H
