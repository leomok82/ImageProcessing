#ifndef PROJECTIONINPUTHANDLER3D_H
#define PROJECTIONINPUTHANDLER3D_H

#include "Volume.h"
#include "Projections.h"

/**
 * @brief Applies a selected projection technique to a volume.
 *
 * This method allows the user to select a type of projection to apply to a given volume. 
 * It supports Maximum Intensity Projection (Max IP), Minimum Intensity Projection (Min IP), 
 * and Average Intensity Projection (Average IP). The user is also prompted to specify the 
 * range of slices (start and end) to which the projection will be applied.
 *
 * @param volume A reference to the Volume object on which the projection will be applied. 
 *               This object encapsulates the volumetric data as well as metadata such as 
 *               dimensions and voxel values.
 * @return std::__1::vector<unsigned char> A vector containing the projected 2D image data 
 *         resulting from the specified projection operation. The vector will be empty if 
 *         an invalid projection type is selected.
 *
 * @note This method uses std::__1::vector, indicating it may be using a specific 
 *       standard library implementation. You might need to adjust this to 
 *       std::vector or another type depending on your development environment.
 */
class ProjectionInputHandler {
public:
    static std::__1::vector<unsigned char> applyProjection(Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
