#ifndef FILTERINPUTHANDLER3D_H
#define FILTERINPUTHANDLER3D_H

#include "Volume.h"

class FilterInputHandler3D {
public:
    static void applyFilter(int filterType, Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
