/**
 * Group Name: Yen
 * Antony Krymski (agk123)
 * Leo Mok (edsml-lm1823)
 * Bofan Liu (edsml-bl1023)
 * Zeyi Ke (edsml-zk23)
 * Tianzi Zhang (acse-tz2523)
 * Yifan Wu (acse-yw11823)
 */

#ifndef EDGEDETECTIONFILTER_H
#define EDGEDETECTIONFILTER_H

#include "Filter.h"
#include <memory>

// Abstract base class for edge detection filters
class EdgeDetectionFilter : public Filter {
public:
    static std::unique_ptr<Filter> create(int type);
};

// Sobel Filter
class SobelFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Prewitt Filter
class PrewittFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

// Custom Edge Detection Filter (Example: Scharr)
class ScharrFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

class RobertsCrossFilter : public EdgeDetectionFilter {
public:
    void apply(unsigned char* data, int width, int height, int channels) override;
};

#endif // EDGEDETECTIONFILTER_H