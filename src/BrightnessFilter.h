#ifndef BRIGHTNESSFILTER_H
#define BRIGHTNESSFILTER_H

#include "Filter.h"

class BrightnessFilter : public Filter {
    int brightnessDelta;

public:
    BrightnessFilter(int delta);
    virtual ~BrightnessFilter();
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // BRIGHTNESSFILTER_H
