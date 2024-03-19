#include "ImageBlurFilter.h"
#include <iostream>

std::unique_ptr<Filter> ImageBlurFilter::create(int type, int kernelSize) {
    
    switch (type) {
        case 1:
            std::cout << "Now you are in the MedianBlurFilter create function" << std::endl;
            return std::make_unique<MedianBlurFilter>(kernelSize);
        case 2:
            std::cout << "Now you are in the BoxBlurFilter create function" << std::endl;
        //     return std::make_unique<BoxBlurFilter>();
        case 3:
            std::cout << "Now you are in the GaussianBlurFilter create function" << std::endl;
            return std::make_unique<GaussianBlurFilter>(kernelSize);
        default:
            std::cerr << "Unknown image blur filter type." << std::endl;
            return nullptr;
    }
}


void MedianBlurFilter::apply(unsigned char *data, int width, int height, int channels) 
{
    std::cout << "Applying MedianBlurFilter to raw data." << std::endl;

    // Prepare vector for output image data
    std::vector<unsigned char> output(width * height * channels);
    int halfKernel = kernelSize / 2;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                std::vector<unsigned char> neighborhood;

                // Build neighborhood, considering mirrored boundary
                for (int dy = -halfKernel; dy <= halfKernel; ++dy)
                {
                    for (int dx = -halfKernel; dx <= halfKernel; ++dx)
                    {
                        int nx = x + dx;
                        int ny = y + dy;

                        // Horizontal boundary mirroring
                        if (nx < 0)
                            nx = -nx - 1;
                        else if (nx >= width)
                            nx = width - (nx - width + 1);

                        // Vertical boundary mirroring
                        if (ny < 0)
                            ny = -ny - 1;
                        else if (ny >= height)
                            ny = height - (ny - height + 1);

                        neighborhood.push_back(data[(ny * width + nx) * channels + c]);
                    }
                }

                // Find median of the neighborhood using quick select algorithm
                unsigned char median = quickSelect(neighborhood, 0, neighborhood.size() - 1, neighborhood.size() / 2);
                output[(y * width + x) * channels + c] = median;
            }
        }
    }

    // Copy the processed data back to the original data array
    std::copy(output.begin(), output.end(), data);
}

void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Box Blur Filter" << std::endl;
    // Box blur logic
    // Actual implementation would go here
}


void GaussianBlurFilter::apply(unsigned char *data, int width, int height, int channels)
{
    std::cout << "Applying Gaussian Blur Filter" << std::endl;
    std::vector<float> weights(kernelSize);
    calculateGaussianWeights(1.0f, kernelSize, weights);

    std::vector<unsigned char> temp(width * height * channels);
    applyGaussianBlurOnRow(data, width, height, channels, weights, temp.data());
    applyGaussianBlurOnColumn(temp.data(), width, height, channels, weights, data);
}

void GaussianBlurFilter::calculateGaussianWeights(float sigma, int kernelSize, std::vector<float> &weights)
{
    float sum = 0.0f;
    int halfSize = kernelSize / 2;
    for (int i = -halfSize; i <= halfSize; ++i)
    {
        weights[i + halfSize] = exp(-(i * i) / (2 * sigma * sigma));
        sum += weights[i + halfSize];
    }
    for (float &weight : weights)
    {
        weight /= sum;
    }
}

int GaussianBlurFilter::mirrorIndex(int index, int maxIndex)
{
    if (index < 0)
        return -index - 1;
    if (index > maxIndex)
        return maxIndex - (index - maxIndex) + 1;
    return index;
}

void GaussianBlurFilter::applyGaussianBlurOnRow(unsigned char *data, int width, int height, int channels, const std::vector<float> &weights, unsigned char *output)
{
    int halfSize = kernelSize / 2;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            for (int c = 0; c < channels; ++c)
            {
                float sum = 0.0f;
                for (int k = -halfSize; k <= halfSize; ++k)
                {
                    int nx = mirrorIndex(x + k, width - 1);
                    sum += data[(y * width + nx) * channels + c] * weights[k + halfSize];
                }
                output[(y * width + x) * channels + c] = static_cast<unsigned char>(std::max(0.0f, std::min(255.0f, sum)));
            }
        }
    }
}

void GaussianBlurFilter::applyGaussianBlurOnColumn(unsigned char *data, int width, int height, int channels, const std::vector<float> &weights, unsigned char *output)
{
    int halfSize = kernelSize / 2;
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            for (int c = 0; c < channels; ++c)
            {
                float sum = 0.0f;
                for (int k = -halfSize; k <= halfSize; ++k)
                {
                    int ny = mirrorIndex(y + k, height - 1);
                    sum += data[(ny * width + x) * channels + c] * weights[k + halfSize];
                }
                output[(y * width + x) * channels + c] = static_cast<unsigned char>(std::max(0.0f, std::min(255.0f, sum)));
            }
        }
    }
}
