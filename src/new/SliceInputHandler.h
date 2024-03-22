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
