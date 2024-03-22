#ifndef PROJECTIONINPUTHANDLER3D_H
#define PROJECTIONINPUTHANDLER3D_H

#include "Volume.h"
#include "Projections.h"

class ProjectionInputHandler {
public:
    static std::__1::vector<unsigned char> applyProjection(Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
