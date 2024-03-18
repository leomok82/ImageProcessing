#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
    virtual ~Filter() {}
    virtual void apply(unsigned char* data, int width, int height, int channels) = 0;
};

#endif // FILTER_H
