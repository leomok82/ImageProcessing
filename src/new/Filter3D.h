/**
 * @file Filter3D.h
 * @brief This file contains the declaration of the Filter3D class and its derived classes.
 *
 * The Filter3D class is an abstract base class that defines the interface for applying a 3D filter to a Volume object.
 * It provides a pure virtual function `apply()` that must be implemented by derived classes.
 *
 * The Gaussian3DFilter class is a derived class of Filter3D that applies a Gaussian filter to a Volume object.
 * The Median3DFilter class is a derived class of Filter3D that applies a median filter to a Volume object.
 *
 * @author Group Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

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
    /**
     * @brief Applies the 3D filter to the given Volume object.
     * @param volume The Volume object to apply the filter to.
     */
    virtual void apply(Volume& volume) = 0;

    /**
     * @brief Creates a unique_ptr to a Filter3D object based on the given type and kernel size.
     * @param type The type of the filter.
     * @param kernelSize The size of the filter kernel.
     * @return A unique_ptr to a Filter3D object.
     */
    static std::unique_ptr<Filter3D> create(int type, int kernelSize);

    /**
     * @brief Virtual destructor for the Filter3D class.
     */
    virtual ~Filter3D() {}
};

/**
 * @class Gaussian3DFilter
 * @brief Derived class of Filter3D that applies a Gaussian filter to a Volume object.
 *
 * The Gaussian3DFilter class is a derived class of Filter3D that applies a Gaussian filter to a Volume object.
 */
class Gaussian3DFilter : public Filter3D {
    int kernelSize;
public:
    /**
     * @brief Constructs a Gaussian3DFilter object with the specified kernel size.
     * @param kernelSize The size of the filter kernel.
     */
    Gaussian3DFilter(int kernelSize) : kernelSize(kernelSize) {}

    /**
     * @brief Applies the Gaussian filter to the given Volume object.
     * @param volume The Volume object to apply the filter to.
     */
    void apply(Volume& volume) override;
};

/**
 * @class Median3DFilter
 * @brief Derived class of Filter3D that applies a median filter to a Volume object.
 *
 * The Median3DFilter class is a derived class of Filter3D that applies a median filter to a Volume object.
 */
class Median3DFilter : public Filter3D {
    int kernelSize;
public:
    /**
     * @brief Constructs a Median3DFilter object with the specified kernel size.
     * @param kernelSize The size of the filter kernel.
     */
    Median3DFilter(int kernelSize) : kernelSize(kernelSize) {}

    /**
     * @brief Applies the median filter to the given Volume object.
     * @param volume The Volume object to apply the filter to.
     */
    void apply(Volume& volume) override;
};

#endif // FILTER3D_H
