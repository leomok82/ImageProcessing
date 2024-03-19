#include "ImageBlurFilter.h"
#include <iostream>

// std::unique_ptr<Filter> ImageBlurFilter::create(int type, int kernelSize)
// {
//     switch (type)
//     {
//     case 1:
//         return std::make_unique<MedianBlurFilter>(kernelSize);

//     default:
//         std::cerr << "Unknown image blur filter type." << std::endl;
//         return nullptr;
//     }
// }

std::unique_ptr<Filter> ImageBlurFilter::create(int type) {
    switch (type) {
        case 1:
            return std::make_unique<MedianBlurFilter>();
        case 2:
            return std::make_unique<BoxBlurFilter>();
        case 3:
            return std::make_unique<GaussianBlurFilter>();
        default:
            std::cerr << "Unknown image blur filter type." << std::endl;
            return nullptr;
    }
}

void MedianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Median blur logic

    std::cout << "Applying Median Blur Filter" << std::endl;

    int halfKernel = 5 / 2;

    for (int y = halfKernel; y < height - halfKernel; ++y) {
        for (int x = halfKernel; x < width - halfKernel; ++x) {
            for (int c = 0; c < channels; ++c) {
                std::vector<unsigned char> values;
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                        int nx = x + kx;
                        int ny = y + ky;
                        int i = (ny * width + nx) * channels + c;
                        values.push_back(data[i]); 
                    }
                }

                std::sort(values.begin(), values.end());

                int medianIndex = values.size() / 2;
                int i = (y * width + x) * channels + c;
                data[i] = values[medianIndex];
                }
            }
        }
}

// 这个是最原始的
// void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
//     // Box Blur logic
//     std::cout << "Applying Box Blur Filter" << std::endl;

//     int halfKernel = 11 / 2; 

//     for (int y = halfKernel; y < height - halfKernel; ++y) {
//         for (int x = halfKernel; x < width - halfKernel; ++x) {
//             for (int c = 0; c < channels; ++c) {
//                 int sum = 0;
//                 int count = 0;
//                 for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
//                     for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
//                         int nx = x + kx;
//                         int ny = y + ky;
//                         if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
//                             int i = (ny * width + nx) * channels + c;
//                             sum += data[i];
//                             ++count;
//                         }
//                         else { // 处理边界像素，将其置为黑色
//                             sum += 0; // 将像素置为黑色，可以根据需求修改
//                             ++count;
//                         }
//                     }
//                 }

//                 unsigned char meanValue = static_cast<unsigned char>(sum / count);

//                 int i = (y * width + x) * channels + c;
//                 data[i] = meanValue;
//             }
//         }
//     }
// }

// 这个是滑动窗口的，并且跑那个老头没有问题的
void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    std::cout << "Applying Box Blur Filter" << std::endl;

    int halfKernel = 11 / 2;

    // 滑动窗口并应用模糊滤波器
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                int windowSum = 0;
                int windowCount = 0;

                // 计算窗口内像素的总和和数量
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                        int nx = x + kx;
                        int ny = y + ky;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            int i = (ny * width + nx) * channels + c;
                            windowSum += data[i]; // 将像素的值加入窗口总和中
                            ++windowCount; // 增加窗口中像素的数量
                        }
                    }
                }

                // 计算窗口中像素的平均值，并将当前像素的值设置为平均值
                int i = (y * width + x) * channels + c;
                if (windowCount > 0) {
                    data[i] = static_cast<unsigned char>(windowSum / windowCount);
                } else {
                    data[i] = 0; // 处理位于边界之外的像素
                }
            }
        }
    }
}

//  void BoxBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
//     std::cout << "Applying Box Blur Filter" << std::endl;

//     // 创建积分图像
//     std::vector<int> integralImage(width * height * channels, 0);

//     // 计算积分图像
//     for (int y = 0; y < height; ++y) {
//         for (int x = 0; x < width; ++x) {
//             for (int c = 0; c < channels; ++c) {
//                 int i = (y * width + x) * channels + c;
//                 if (y == 0 || x == 0 || y == height - 1 || x == width - 1) {
//                     // 如果窗口位置超出边界，则将超出部分置为0
//                     integralImage[i] = 0;
//                 } else {
//                     integralImage[i] = data[i] + integralImage[i - width * channels];
//                     if (x > 0) {
//                         integralImage[i] += integralImage[i - channels] - integralImage[i - width * channels - channels];
//                     }
//                 }
//             }
//         }
//     }

//     // 滑动窗口并应用模糊滤波器
//     int halfKernel = 11 / 2; // 因为核大小是3x3，所以半径是1
//     int count = 121;
//     for (int y = 0; y < height; ++y) {
//         for (int x = 0; x < width; ++x) {
//             for (int c = 0; c < channels; ++c) {
//                 // 计算窗口的边界
//                 int x0 = std::max(0, x - halfKernel);
//                 int y0 = std::max(0, y - halfKernel);
//                 int x1 = std::min(width - 1, x + halfKernel);
//                 int y1 = std::min(height - 1, y + halfKernel);

//                 // 计算窗口内像素的总和
//                 int sum = 0;
//                 for (int ky = y0; ky <= y1; ++ky) {
//                     for (int kx = x0; kx <= x1; ++kx) {
//                         // 将超出边界的部分置为0
//                         if (kx < 0 || kx >= width || ky < 0 || ky >= height) {
//                             continue;
//                         }
//                         int index = (ky * width + kx) * channels + c;
//                         sum += data[index];
//                     }
//                 }

//                 // 计算窗口内像素的平均值（固定为9），并将当前像素的值设置为平均值
//                 int i = (y * width + x) * channels + c;
//                 data[i] = static_cast<unsigned char>(sum / count); // 固定除以9
//             }
//         }
//     }
// }






// void GaussianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
//     // Gaussian blur logic
//     std::cout << "Applying Gaussian Blur Filter" << std::endl;

//     int kernelSize = 7;
//     double sigma = 1.0;

//     // Compute Gaussian kernel
//     std::vector<std::vector<double>> kernel(kernelSize, std::vector<double>(kernelSize));
//     double kernelSum = 0.0;
//     int halfKernel = kernelSize / 2;
//     for (int i = -halfKernel; i <= halfKernel; ++i) {
//         for (int j = -halfKernel; j <= halfKernel; ++j) {
//             double weight = std::exp(-(i * i + j * j) / (2 * sigma * sigma));
//             kernel[i + halfKernel][j + halfKernel] = weight;
//             kernelSum += weight;
//         }
//     }

//     // Normalize the kernel
//     for (int i = 0; i < kernelSize; ++i) {
//         for (int j = 0; j < kernelSize; ++j) {
//             kernel[i][j] /= kernelSum;
//         }
//     }

//     // Apply Gaussian blur
//     for (int y = halfKernel; y < height - halfKernel; ++y) {
//         for (int x = halfKernel; x < width - halfKernel; ++x) {
//             for (int c = 0; c < channels; ++c) {
//                 double blurredValue = 0.0;
//                 for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
//                     for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
//                         int nx = x + kx;
//                         int ny = y + ky;
//                         int i = (ny * width + nx) * channels + c;
//                         double weight = kernel[ky + halfKernel][kx + halfKernel];
//                         blurredValue += data[i] * weight;
//                     }
//                 }
//                 int i = (y * width + x) * channels + c;
//                 data[i] = static_cast<unsigned char>(blurredValue);
//             }
//         }
//     }
// }

void GaussianBlurFilter::apply(unsigned char* data, int width, int height, int channels) {
    // Gaussian blur logic
    std::cout << "Applying Gaussian Blur Filter" << std::endl;

    int kernelSize = 3;
    double sigma = 1.0;

    // Compute Gaussian kernel
    std::vector<double> kernel1D(kernelSize);
    double kernelSum = 0.0;
    int halfKernel = kernelSize / 2;
    for (int i = -halfKernel; i <= halfKernel; ++i) {
        double weight = std::exp(-(i * i) / (2 * sigma * sigma));
        kernel1D[i + halfKernel] = weight;
        kernelSum += weight;
    }

    // Normalize the kernel
    for (int i = 0; i < kernelSize; ++i) {
        kernel1D[i] /= kernelSum;
    }

    // Apply horizontal Gaussian blur
    applyHorizontalGaussianBlur(data, width, height, channels, kernel1D);

    // Apply vertical Gaussian blur
    applyVerticalGaussianBlur(data, width, height, channels, kernel1D);
}

void GaussianBlurFilter::applyHorizontalGaussianBlur(unsigned char* data, int width, int height, int channels, const std::vector<double>& kernel) {
    int kernelSize = kernel.size();
    int halfKernel = kernelSize / 2;

    // Apply horizontal Gaussian blur
    for (int y = 0; y < height; ++y) {
        for (int x = halfKernel; x < width - halfKernel; ++x) {
            for (int c = 0; c < channels; ++c) {
                double blurredValue = 0.0;
                for (int kx = -halfKernel; kx <= halfKernel; ++kx) {
                    int nx = x + kx;
                    if (nx >= 0 && nx < width) {  // Check if pixel is within image boundaries
                        int i = (y * width + nx) * channels + c;
                        double weight = kernel[kx + halfKernel];
                        blurredValue += data[i] * weight;
                    }
                    else { // If pixel is outside image boundaries, set blurred value to 0
                        blurredValue = 0.0;
                        break;
                    }
                }
                int i = (y * width + x) * channels + c;
                data[i] = static_cast<unsigned char>(blurredValue);
            }
        }
    }
}

void GaussianBlurFilter::applyVerticalGaussianBlur(unsigned char* data, int width, int height, int channels, const std::vector<double>& kernel) {
    int kernelSize = kernel.size();
    int halfKernel = kernelSize / 2;

    // Apply vertical Gaussian blur
    for (int y = halfKernel; y < height - halfKernel; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < channels; ++c) {
                double blurredValue = 0.0;
                for (int ky = -halfKernel; ky <= halfKernel; ++ky) {
                    int ny = y + ky;
                    if (ny >= 0 && ny < height) {  // Check if pixel is within image boundaries
                        int i = (ny * width + x) * channels + c;
                        double weight = kernel[ky + halfKernel];
                        blurredValue += data[i] * weight;
                    }
                    else { // If pixel is outside image boundaries, set blurred value to 0
                        blurredValue = 0.0;
                        break;
                    }
                }
                int i = (y * width + x) * channels + c;
                data[i] = static_cast<unsigned char>(blurredValue);
            }
        }
    }
}