/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef PROJECTIONS_H
#define PROJECTIONS_H

#include "Volume.h"
#include "Slice.h"

class Projections {
public:
    // Static methods for creating projections from a volume
    static std::vector<unsigned char> AIP(const Volume& volume, int startSlice, int endSlice);
    static std::vector<unsigned char> MIP(const Volume& volume, int startSlice, int endSlice);
    static std::vector<unsigned char> MinIP(const Volume& volume, int startSlice, int endSlice);
};

#endif // PROJECTIONS_H
