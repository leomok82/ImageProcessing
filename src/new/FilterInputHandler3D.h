/**
 * @file FilterInputHandler3D.h
 * @brief This file contains the declaration of the FilterInputHandler3D class.
 * 
 * The FilterInputHandler3D class provides a static method to apply a filter to a Volume object.
 * 
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef FILTERINPUTHANDLER3D_H
#define FILTERINPUTHANDLER3D_H

#include "Volume.h"

/**
 * @brief Applies a user-selected 3D filter to volumetric data.
 *
 * This function interacts with the user through the console to select a type of 3D filter
 * and its corresponding kernel size. Based on the user's choices, it creates and applies
 * the specified 3D filter to the provided volumetric data. The function currently supports
 * the application of 3D Gaussian and Median filters with predefined kernel sizes.
 *
 * @param volume A reference to a Volume object that encapsulates the volumetric data to
 *               be filtered. This object is expected to provide access to the volume's
 *               data, dimensions, and potentially other relevant metadata.
 *
 * @note The Volume object is modified in place by the applied filter. The function ensures
 *       that only valid filter types and kernel sizes are accepted, with checks in place
 *       to prompt the user again or terminate the operation if invalid inputs are provided.
 */
class FilterInputHandler3D {
public:
    /**
     * @brief Applies a filter to the given Volume object.
     * 
     * This method modifies the given Volume object by applying a filter to it.
     * 
     * @param volume The Volume object to apply the filter to.
     */
    static void applyFilter(Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
