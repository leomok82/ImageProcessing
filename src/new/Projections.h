// Projections.h
#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#include "Volume.h"
#include "Slice.h"

class Projections {
public:
    // Static methods for creating projections from a volume
    static Slice AIP(const Volume& volume, int startSlice, int endSlice);
    static Slice MIP(const Volume& volume, int startSlice, int endSlice);
    static Slice MinIP(const Volume& volume, int startSlice, int endSlice);
};

#endif // PROJECTIONS_H
