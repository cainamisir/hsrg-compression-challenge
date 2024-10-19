
# C++ Compression Challenge

## Overview
This project provides C++ code to compress and decompress images using a custom algorithm. The system supports batch processing, displays decompressed images in a grid, and provides performance metrics.

## Directory Structure
```
compression-challenge/
├── input_images/              # Input images for testing
├── compressed_images/          # Compressed files stored here
├── decompressed_images/       # Decompressed images output
├── image_helper.cpp           # Core compression logic
├── run_test.cpp               # Batch processing and performance testing
├── show_grid.cpp              # Displays images in a grid
├── show_single.cpp            # Displays a single decompressed image
├── Makefile                   # Build and run automation
└── README.md                  # This README
```

## Setup

1. **Install OpenCV**:
   ```bash
   sudo apt-get install libopencv-dev
   ```
   OR
   ```bash
   brew install opencv
   ```

2. Get OpenCV path
    ```bash
    brew info opencv
    ```
    

3. **Prepare Input Images:**
   Place 64 PNG images inside the `input_images/` folder.

## Usage

1. **Build the Project:**
   ```bash
   make
   ```

2. **Run Tests (Batch Compression & Decompression):**
   ```bash
   make run-test
   ```

3. **Show 8x8 Grid of Decompressed Images:**
   ```bash
   make show-grid
   ```

4. **Display a Single Image:**
   ```bash
   ./show-single decompressed_images/img1.png
   ```

5. **Clean Up Output Files:**
   ```bash
   make clean
   ```

## Scripts

### `run_test.cpp`
Batch processes input images, compresses them, and measures performance.

### `show_grid.cpp`
Displays an 8x8 grid of decompressed images.

### `show_single.cpp`
Displays a single decompressed image.
