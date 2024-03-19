// Filter3D.h adjustments
#ifndef FILTER3D_H
#define FILTER3D_H

#include "Volume.h"
#include <memory>

class Filter3D {
public:
    virtual ~Filter3D() {}
    virtual void apply(Volume& volume) = 0;
    static std::unique_ptr<Filter3D> create(int type, int kernelSize);
};

class Gaussian3DFilter : public Filter3D {
    int kernelSize;
public:
    Gaussian3DFilter(int kernelSize) : kernelSize(kernelSize) {}
    void apply(Volume& volume) override;
};

class Median3DFilter : public Filter3D {
    int kernelSize;
public:
    Median3DFilter(int kernelSize) : kernelSize(kernelSize) {}
    void apply(Volume& volume) override;
};

#endif // FILTER3D_H
