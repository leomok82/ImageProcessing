/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef PROJECTIONINPUTHANDLER3D_H
#define PROJECTIONINPUTHANDLER3D_H

#include "Volume.h"
#include "Projections.h"

class ProjectionInputHandler {
public:
    static std::__1::vector<unsigned char> applyProjection(Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
