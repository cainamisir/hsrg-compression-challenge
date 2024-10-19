#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <image_path>" << endl;
        return -1;
    }

    string image_path = argv[1];
    Mat image = imread(image_path, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Could not open or find the image." << endl;
        return -1;
    }

    namedWindow("Single Image", WINDOW_AUTOSIZE);
    imshow("Single Image", image);
    waitKey(0);  // Wait for a key press to close the window

    return 0;
}
