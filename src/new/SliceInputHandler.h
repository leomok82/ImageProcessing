/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef SLICEINPUTHANDLER_H
#define SLICEINPUTHANDLER_H

#include "Volume.h"
#include "Slice.h"
#include <string>

class SliceInputHandler {
public:
    static void applySlice(const Volume& volume, int width, int height, int depth);
};

#endif // SLICEINPUTHANDLER_H
