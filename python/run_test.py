from image_helper import load_image, save_image, compress, decompress
import os
import time

def run_tests(input_folder, compressed_folder, decompressed_folder):
    total_compress_time, total_decompress_time = 0, 0

    for filename in os.listdir(input_folder):
        if filename.endswith(".jpg"):
            image_path = os.path.join(input_folder, filename)

            # Load JPG input image
            image = load_image(image_path)
            original_size = os.path.getsize(image_path)

            # Compress the image
            compressed_data, compress_time = compress(image)
            total_compress_time += compress_time

            # Save the compressed data to a .myimg file
            compressed_path = os.path.join(compressed_folder, filename + ".myimg")
            with open(compressed_path, "wb") as f:
                for pixel, count in compressed_data:
                    f.write(bytes([pixel, count]))

            # Decompress the image
            decompressed_data, decompress_time = decompress(compressed_data)
            decompressed_image = decompressed_data.reshape(image.shape)
            total_decompress_time += decompress_time

            # Save the decompressed image as JPG
            output_filename = filename.replace(".jpg", "_decompressed.jpg")
            save_image(decompressed_image, os.path.join(decompressed_folder, output_filename))

    print(f"Total Compression Time: {total_compress_time:.4f} seconds")
    print(f"Total Decompression Time: {total_decompress_time:.4f} seconds")

if __name__ == "__main__":
    run_tests("input_images", "compressed_images", "decompressed_images")
