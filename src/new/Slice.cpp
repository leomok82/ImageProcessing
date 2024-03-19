// Slice.cpp
#include "Slice.h"
#include "stb_image_write.h"

void Slice::saveToFile(const std::string& filePath) const {
    stbi_write_png(filePath.c_str(), width, height, 1 /* or 3 for RGB */, data.data(), width * 1 /* or 3 for RGB */);
}
