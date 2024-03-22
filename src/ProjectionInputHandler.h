/**
 * @file ProjectionInputHandler.h
 * @brief This file contains the declaration of the ProjectionInputHandler class.
 * 
 * The ProjectionInputHandler class provides a static method to apply projection on a Volume object.
 * It includes the necessary header files and defines the applyProjection method.
 * 
 * @ingroup Yen
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 */

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
    /**
     * @brief Applies projection on a Volume object.
     * 
     * This method takes a Volume object as input and applies projection on it.
     * It returns a vector of unsigned char representing the projected image.
     * 
     * @param volume The Volume object to apply projection on.
     * @return A vector of unsigned char representing the projected image.
     */
    static std::__1::vector<unsigned char> applyProjection(Volume& volume);
};

#endif // FILTERINPUTHANDLER3D_H
