#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <dirent.h>  // POSIX directory traversal

using namespace std;
using namespace cv;

vector<string> get_files(const string& folder) {
    vector<string> files;
    DIR* dir = opendir(folder.c_str());
    if (dir == nullptr) {
        cerr << "Could not open directory: " << folder << endl;
        return files;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        string filename = entry->d_name;
        if (filename != "." && filename != "..") {
            files.push_back(folder + "/" + filename);
        }
    }
    closedir(dir);
    return files;
}

void show_grid(const string& folder) {
    vector<string> files = get_files(folder);
    vector<Mat> images;

    for (const auto& file : files) {
        Mat img = imread(file, IMREAD_COLOR);
        if (!img.empty()) {
            images.push_back(img);
        }
    }

    int grid_size = 8;
    Mat grid(64 * grid_size, 64 * grid_size, CV_8UC3);

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            int index = i * grid_size + j;
            if (index < images.size()) {
                Mat roi = grid(Rect(j * 64, i * 64, 64, 64));
                resize(images[index], roi, roi.size());
            }
        }
    }

    namedWindow("Image Grid", WINDOW_AUTOSIZE);
    imshow("Image Grid", grid);
    waitKey(0);
}

int main() {
    show_grid("decompressed_images");
    return 0;
}
