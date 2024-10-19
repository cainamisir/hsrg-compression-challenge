
# Python Compression Challenge

## Overview
This project contains Python scripts for compressing and decompressing images. It supports batch processing of images, displays them in an 8x8 grid, and allows for individual image inspection. The primary goal is to benchmark and visualize the compression process.

## Directory Structure
```
compression-challenge/
├── input_images/              # Input images for testing
├── compressed_images/          # Compressed files stored here
├── decompressed_images/       # Decompressed images output
├── image_helper.py            # Core compression logic
├── run_test.py                # Batch processing and performance testing
├── show_grid.py               # Displays images in a grid
├── requirements.txt           # Python dependencies
└── README.md                  # This README
```

## Setup

1. **Install Dependencies:**
   ```bash
   pip install -r requirements.txt
   ```

2. **Prepare Input Images:**
   Place 64 PNG images inside the `input_images/` folder.

## Usage

1. **Run Tests (Batch Compression & Decompression):**
   ```bash
   make run-test
   ```

2. **Show 8x8 Grid of Decompressed Images:**
   ```bash
   make show-grid
   ```

3. **Display a Single Image:**
   Modify `show_grid.py`:
   ```python
   show_single_image("decompressed_images/img1.png")
   ```

4. **Clean Up Output Files:**
   ```bash
   make clean
   ```

## Scripts

### `run_test.py`
Performs batch compression and decompression, stores compressed files, and measures performance.

### `show_grid.py`
Displays an 8x8 grid of decompressed images and supports individual image inspection.
