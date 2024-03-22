// Filter3D.h adjustments
#ifndef FILTER3D_H
#define FILTER3D_H

#include "Volume.h"
#include <memory>

/**
 * @brief Creates a 3D Gaussian kernel.
 *
 * This function generates a 3D Gaussian kernel with a specified size and standard deviation (sigma).
 * The kernel values are calculated using the Gaussian function and normalized so that their sum equals 1.
 * This kernel is used for applying Gaussian blur to a 3D volume.
 *
 * @param kernelSize The size of the kernel along each dimension (must be an odd number).
 * @param sigma The standard deviation of the Gaussian function.
 * @return A 3D vector containing the Gaussian kernel values.
 */
class Filter3D {
public:
    virtual ~Filter3D() {}
    virtual void apply(Volume& volume) = 0;
    static std::unique_ptr<Filter3D> create(int type, int kernelSize);
};

/**
 * @brief Applies a 3D Gaussian filter to volumetric data.
 *
 * This function convolves the input volumetric data with a Gaussian kernel to apply a Gaussian blur.
 * It is useful for reducing noise or smoothing a volume. The function handles edges by clamping coordinates,
 * ensuring that the convolution is applied correctly across the entire volume.
 *
 * @param kernel The 3D Gaussian kernel to use for convolution.
 * @param data A reference to a vector of unsigned chars representing the volume's voxel intensities.
 * @param width The width of the volume.
 * @param height The height of the volume.
 * @param depth The depth of the volume.
 */
class Gaussian3DFilter : public Filter3D {
    int kernelSize;
public:
    Gaussian3DFilter(int kernelSize) : kernelSize(kernelSize) {}
    void apply(Volume& volume) override;
};

/**
 * @brief Applies a 3D Median filter to a Volume object.
 *
 * This method applies a Median filter to the volume contained within the Volume object, using a specified
 * kernel size. The Median filter is effective for removing noise while preserving edges by replacing each
 * voxel's value with the median of its neighborhood. The method iterates through each voxel in the volume,
 * calculates the median of the voxels within the kernel's range, and updates the voxel value accordingly.
 *
 * @param volume A reference to the Volume object containing the volumetric data to be filtered.
 */
class Median3DFilter : public Filter3D {
    int kernelSize;
public:
    Median3DFilter(int kernelSize) : kernelSize(kernelSize) {}
    void apply(Volume& volume) override;
};

#endif // FILTER3D_H
