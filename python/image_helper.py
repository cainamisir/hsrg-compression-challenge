from PIL import Image
import numpy as np
import time

def load_image(image_path):
    """Load the image and return it as an RGB numpy array."""
    img = Image.open(image_path).convert('RGB')
    return np.array(img)

def save_image(image_array, output_path):
    """Save the numpy array as a JPG image."""
    img = Image.fromarray(image_array.astype('uint8'), 'RGB')
    img.save(output_path, format='JPEG')

def compress(image_array):
    """Simple RLE-based compression."""
    start = time.time()
    flat_pixels = image_array.flatten()
    compressed = []
    prev_pixel = flat_pixels[0]
    count = 1

    for pixel in flat_pixels[1:]:
        if pixel == prev_pixel and count < 255:
            count += 1
        else:
            compressed.append((prev_pixel, count))
            prev_pixel = pixel
            count = 1
    compressed.append((prev_pixel, count))
    return compressed, time.time() - start

def decompress(compressed):
    """Decompress RLE data back into an image."""
    start = time.time()
    decompressed = [pixel for pixel, count in compressed for _ in range(count)]
    return np.array(decompressed, dtype='uint8'), time.time() - start
