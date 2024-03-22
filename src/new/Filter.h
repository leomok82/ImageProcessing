/**
 * @file Filter.h
 * @brief This file contains the declaration of the Filter class.
 * 
 * The Filter class is an abstract base class that defines the interface for applying filters to image data.
 * It provides a pure virtual function, apply(), which must be implemented by derived classes.
 * 
 * @ingroup Yen
 * 
 * @author Antony Krymski (agk123)
 * @author Leo Mok (edsml-lm1823)
 * @author Bofan Liu (edsml-bl1023)
 * @author Zeyi Ke (edsml-zk23)
 * @author Tianzi Zhang (acse-tz2523)
 * @author Yifan Wu (acse-yw11823)
 */
#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
    /**
     * @brief Destructor for the Filter class.
     */
    virtual ~Filter() {}

    /**
     * @brief Applies the filter to the image data.
     * 
     * This pure virtual function must be implemented by derived classes.
     * It takes in the image data, width, height, and number of channels, and applies the filter to the data in place.
     * 
     * @param data The image data to apply the filter to.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param channels The number of channels in the image.
     */
    virtual void apply(unsigned char* data, int width, int height, int channels) = 0;
};

#endif // FILTER_H
