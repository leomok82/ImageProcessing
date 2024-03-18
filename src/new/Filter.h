#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
    virtual ~Filter() {}
    virtual void apply(unsigned char* data, int width, int height, int channels) = 0;

    // Factory Method: Creates and returns an instance of a filter class.
    // static Filter* createFilter(int filterType);
};

#endif // FILTER_H
