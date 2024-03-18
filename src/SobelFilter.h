#ifndef SOBELFILTER_H
#define SOBELFILTER_H

#include "Filter.h"

class SobelFilter : public Filter {
public:
    SobelFilter();
    virtual ~SobelFilter();
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // SOBELFILTER_H
