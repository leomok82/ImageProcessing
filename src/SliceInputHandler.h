/**
 * @file SliceInputHandler.h
 * @brief This file contains the declaration of the SliceInputHandler class.
 * 
 * The SliceInputHandler class provides a static method to apply a slice to a volume.
 * It takes the volume, width, height, and depth as input parameters.
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 * 
 * @date [date]
 */

#ifndef SLICEINPUTHANDLER_H
#define SLICEINPUTHANDLER_H

#include "Volume.h"
#include "Slice.h"
#include <string>

/**
 * @brief Handles user input to slice a 3D volume along a specified axis and optionally saves the slice.
 * 
 * This method prompts the user to choose an axis along which to slice the volume, creating slices
 * in the Y-Z, X-Z, or X-Y plane accordingly. The user is then asked to specify the slice number to extract.
 * Validation is performed on the user's input to ensure the slice number is valid for the chosen axis.
 * If valid, the slice is extracted from the volume, and the user is given the option to save the slice to a file.
 * 
 * @param volume The Volume object from which the slice is to be extracted.
 * @param width The width of the volume in voxels.
 * @param height The height of the volume in voxels.
 * @param depth The depth of the volume in voxels.
 * 
 * @note The user is prompted for input via standard input (std::cin) and, depending on the responses,
 *       may also be asked for a file path to save the extracted slice. Error messages are outputted
 *       to standard error (std::cerr) in case of invalid inputs.
 */

class SliceInputHandler {
public:
    /**
     * @brief Applies a slice to a volume.
     * 
     * This static method applies a slice to the given volume.
     * The slice is defined by the width, height, and depth parameters.
     * 
     * @param volume The volume to apply the slice to.
     * @param width The width of the slice.
     * @param height The height of the slice.
     * @param depth The depth of the slice.
     */
    static void applySlice(const Volume& volume, int width, int height, int depth);
};

#endif // SLICEINPUTHANDLER_H
