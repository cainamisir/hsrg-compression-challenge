#include "image_helper.h"
#include <opencv2/opencv.hpp>
#include <chrono>
#include <iostream>

using namespace std;
using namespace cv;

vector<pair<Pixel, int>> compress(const Mat& image) {
    cout << "Compressing image...\n";
    vector<pair<Pixel, int>> compressed;
    auto start = chrono::high_resolution_clock::now();

    Pixel prev = {image.at<Vec3b>(0, 0)[0], image.at<Vec3b>(0, 0)[1], image.at<Vec3b>(0, 0)[2]};
    int count = 1;

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            Pixel current = {image.at<Vec3b>(i, j)[0], image.at<Vec3b>(i, j)[1], image.at<Vec3b>(i, j)[2]};
            if (current.r == prev.r && current.g == prev.g && current.b == prev.b && count < 255) {
                ++count;
            } else {
                compressed.emplace_back(prev, count);
                prev = current;
                count = 1;
            }
        }
    }
    compressed.emplace_back(prev, count);

    auto end = chrono::high_resolution_clock::now();
    cout << "Compression time: " << chrono::duration<double>(end - start).count() << " seconds\n";
    return compressed;
}

Mat decompress(const vector<pair<Pixel, int>>& compressed, int rows, int cols) {
    Mat decompressed(rows, cols, CV_8UC3);
    auto start = chrono::high_resolution_clock::now();

    int index = 0;
    for (const auto& [pixel, count] : compressed) {
        for (int i = 0; i < count; ++i) {
            int row = index / cols;
            int col = index % cols;
            decompressed.at<Vec3b>(row, col) = Vec3b(pixel.r, pixel.g, pixel.b);
            ++index;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Decompression time: " << chrono::duration<double>(end - start).count() << " seconds\n";
    return decompressed;
}
