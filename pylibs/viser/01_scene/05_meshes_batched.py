from __future__ import annotations

import time
from pathlib import Path

import numpy as np
import trimesh

import viser


def create_grid_transforms(
    num_instances: int,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    grid_size = int(np.ceil(np.sqrt(num_instances)))

    # create grid positions
    x = np.arange(grid_size) - (grid_size - 1) / 2
    y = np.arange(grid_size) - (grid_size - 1) / 2
    xx, yy = np.meshgrid(x, y)
    positions = np.zeros((grid_size, grid_size, 3), dtype=np.float32)
    positions[:, 0] = xx.flatten()
    positions[:, 1] = yy.flatten()
    positions[:, 2] = 1.0
    positions = positions[:num_instances]

    # All instances have identity rotation.
    rotations = np.zeros((num_instances, 4), dtype=np.float32)
    rotations[:, 0] = 1.0  # w component = 1

    # Initial scales
    scales = np.linalg.norm(positions, axis=-1)
    scales = np.sin(scales * 1.5) * 0.5 + 1.0
    return positions, rotations, scales.astype(np.float32)


def generate_per_instance_colors(
    positions: np.ndarray, color_mode: str = "rainbow"
) -> np.ndarray:
    n = positions.shape[0]
    if color_mode == "rainbow":
        # rainbow colors based on instance index
        hues = np.linspace(0, 1, n, endpoint=False)
        colors = np.zeros((n, 3))
        for i, hue in enumerate(hues):
            # Conver HSV to RGB(simplified)
            c = 1.0  # Saturation
            x = c * (1 - abs((hue * 6) % 2 - 1))
            if hue < 1 / 6:
                colors[i] = [c, x, 0]
            elif hue < 2 / 6:
                colors[i] = [x, c, 0]
            elif hue < 3 / 6:
                colors[i] = [0, c, x]
            elif hue < 4 / 6:
                colors[i] = [0, x, c]
            elif hue < 5 / 6:
                colors[i] = [x, 0, c]
            else:
                colors[i] = [c, 0, x]
        return (colors * 255).astype(np.uint8)
    elif color_mode == "position":
        # Colors based on position (cosine of positions for smoooth gradients)
        colors = (np.cos(positions) * 0.5 + 0.5) * 255
        return colors.astype(np.uint8)
    else:
        # Default to white
        return np.full((n, 3), 255, dtype=np.uint8)


def generate_shared_color(color_rgb: tuple[int, int, int]) -> np.ndarray:
    return np.array(color_rgb, dtype=np.uint8)


# def generated_animated_colors(
#     positions: np.ndarray, t:float, animation_mode: str="wave"
# )->np.ndarray:
#     n = position.shape[0]
#     if animation_mode == "wave":
#         # Wave pattern based on distance from center
#         distances = np.linalg.norm(positions[:, :2], axis = 1)
#         wave = np.sin(distances * 2)
#         colors = np.zeros((n, 3))
#         colors[:, 0] = wave


def main():
    # Load and prepare mesh data
    # Add GUI controls
    # Color controls
    # Per Instance color controls
    # Shared color controls
    # Animated color controls
    # Initialize transforms
    # Create batched mesh visualization
    # Create initial colors based on default mode.
    #
    pass
