    // image_helper.h

#ifndef IMAGE_HELPER_H
#define IMAGE_HELPER_H

#include <opencv2/opencv.hpp>
#include <vector>

struct Pixel {
    uchar r, g, b;
};

std::vector<std::pair<Pixel, int>> compress(const cv::Mat& image);
cv::Mat decompress(const std::vector<std::pair<Pixel, int>>& compressed, int rows, int cols);

#endif // IMAGE_HELPER_H
