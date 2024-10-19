#include "image_helper.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream> 
#include <filesystem>

using namespace std;
using namespace cv;

void run_tests(const string& input_folder, const string& compressed_folder, const string& decompressed_folder) {
    double total_compress_time = 0, total_decompress_time = 0;
    cout << "Running tests...\n";
    for (const auto& entry : filesystem::directory_iterator(input_folder)) {
        string filename = entry.path().filename().string();
        Mat image = imread(entry.path().string(), IMREAD_COLOR);
        cout << "Processing image: " << filename << endl;
        auto compressed = compress(image);
        ofstream out(compressed_folder + "/" + filename + ".myimg", ios::binary);
        for (const auto& [pixel, count] : compressed) {
            out.write(reinterpret_cast<const char*>(&pixel), sizeof(Pixel));
            out.write(reinterpret_cast<const char*>(&count), sizeof(int));
        }
        out.close();

        Mat decompressed = decompress(compressed, image.rows, image.cols);
        imwrite(decompressed_folder + "/" + filename, decompressed);
    
        cout << "Image: " << filename << endl;
        cout << "Compression Time: " << compressed.size() << " pixels, " << total_compress_time << " seconds" << endl;
        cout << "Decompression Time: " << decompressed.rows * decompressed.cols << " pixels, " << total_decompress_time << " seconds" << endl;
        cout << "Compression Ratio: " << (double)compressed.size() / (double)(decompressed.rows * decompressed.cols) << endl;
    }
}

int main() {
    fprintf(stderr, "Running tests...\n");
    run_tests("input_images", "compressed_images", "decompressed_images");
    return 0;
}
