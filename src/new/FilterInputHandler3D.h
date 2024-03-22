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
