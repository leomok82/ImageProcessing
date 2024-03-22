#ifndef FILTER_H
#define FILTER_H


/**
 * @class Filter
 * @brief Abstract base class for filters.
 *
 * This class serves as a base for various types of filters, defining a common interface for them.
 * Filters that inherit from this class must implement the apply method, which applies the filter's
 * specific effect to a block of data. The class is designed to be flexible, allowing for its use in
 * different contexts, such as image processing, where filters might be applied to manipulate or analyze
 * image data.
 *
 * @note This class is abstract and cannot be instantiated directly. Derived classes must provide an
 *       implementation for the apply method.
 */
class Filter {
public:
    virtual ~Filter() {}
    virtual void apply(unsigned char* data, int width, int height, int channels) = 0;
};

#endif // FILTER_H
