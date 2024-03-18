#define IMAGE_H

#include <iostream>
#include <vector>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Image {
public:
    int width, height, channels;
    std::vector<unsigned char> data;

    Image(const char* filename);

    void printInfo();

    // void save(const char* filename);
};

