import os
from PIL import Image
import matplotlib.pyplot as plt

def get_jpg_files(folder):
    """Retrieve all JPG files from the given folder."""
    return sorted([f for f in os.listdir(folder) if f.endswith(".jpg")])

def show_grid(folder, grid_size=8):
    """Display an 8x8 grid of images."""
    files = get_jpg_files(folder)
    images = [Image.open(os.path.join(folder, f)) for f in files[:grid_size * grid_size]]

    fig, axes = plt.subplots(grid_size, grid_size, figsize=(12, 12))
    for i, ax in enumerate(axes.flat):
        ax.imshow(images[i])
        ax.axis('off')
    plt.show()

def show_single_image(image_path):
    """Display a single image."""
    img = Image.open(image_path)
    plt.imshow(img)
    plt.axis('off')
    plt.show()

if __name__ == "__main__":
    # Example: Display 8x8 grid
    show_grid("decompressed_images")

    # Example: Display a single image
    # show_single_image("decompressed_images/img1_decompressed.jpg")
