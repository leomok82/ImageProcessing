/**
 * @file Projections.h
 * @brief This file contains the declaration of the Projections class and its static methods for creating projections from a volume.
 * 
 * @ingroup Yen
 * 
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

/**
 * @class Projections
 * @brief The Projections class provides static methods for creating projections from a volume.
 */
class Projections {
public:
    /**
     * @brief Create an Average Intensity Projection (AIP) from a volume.
     * 
     * @param volume The volume from which to create the projection.
     * @param startSlice The index of the starting slice.
     * @param endSlice The index of the ending slice.
     * @return A vector of unsigned characters representing the AIP.
     */
    static std::vector<unsigned char> AIP(const Volume& volume, int startSlice, int endSlice);

    /**
     * @brief Create a Maximum Intensity Projection (MIP) from a volume.
     * 
     * @param volume The volume from which to create the projection.
     * @param startSlice The index of the starting slice.
     * @param endSlice The index of the ending slice.
     * @return A vector of unsigned characters representing the MIP.
     */
    static std::vector<unsigned char> MIP(const Volume& volume, int startSlice, int endSlice);

    /**
     * @brief Create a Minimum Intensity Projection (MinIP) from a volume.
     * 
     * @param volume The volume from which to create the projection.
     * @param startSlice The index of the starting slice.
     * @param endSlice The index of the ending slice.
     * @return A vector of unsigned characters representing the MinIP.
     */
    static std::vector<unsigned char> MinIP(const Volume& volume, int startSlice, int endSlice);
};

#endif // PROJECTIONS_H
