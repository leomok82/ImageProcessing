/**
 * @file FilterInputHandler.h
 * @brief This file contains the declaration of the FilterInputHandler class.
 * 
 * The FilterInputHandler class provides a static method to apply a filter to an image.
 * It takes the image data, width, height, and number of channels as input parameters.
 * The applyFilter method modifies the image data in place.
 * 
 * @author Group Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */
#ifndef FILTERINPUTHANDLER_H
#define FILTERINPUTHANDLER_H

class FilterInputHandler {
public:
    /**
     * @brief Applies a filter to the image data.
     * 
     * This method applies a filter to the image data in place.
     * The filter is specified by the data, width, height, and number of channels.
     * 
     * @param data The image data.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    static void applyFilter(unsigned char* data, int width, int height, int channels);
};

#endif // FILTERINPUTHANDLER_H
