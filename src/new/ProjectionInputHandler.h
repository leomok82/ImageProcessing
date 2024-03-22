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
