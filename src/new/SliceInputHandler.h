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
