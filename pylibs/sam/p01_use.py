import cv2
import matplotlib.pyplot as plt
import numpy as np
from segment_anything import sam_model_registry, SamPredictor
import torch
import time


def show_mask(mask, ax, random_color=False):
    if random_color:
        color = np.concatenate([np.random.random(3), np.array([0.6])], axis=0)
    else:
        color = np.array([30 / 255, 144 / 255, 255 / 255, 0.6])
    h, w = mask.shape[-2:]
    mask_image = mask.reshape(h, w, 1) * color.reshape(1, 1, -1)
    ax.imshow(mask_image)
    return mask_image


def show_points(coords, labels, ax, marker_size=375):
    pos_points = coords[labels == 1]
    neg_points = coords[labels == 0]
    ax.scatter(
        pos_points[:, 0],
        pos_points[:, 1],
        color='green',
        marker='*',
        s=marker_size,
        edgecolor='white',
        linewidth=1.25,
    )
    ax.scatter(
        neg_points[:, 0],
        neg_points[:, 1],
        color='red',
        marker='*',
        s=marker_size,
        edgecolor='white',
        linewidth=1.25,
    )


sam_checkpoint = "./sam_vit_b_01ec64.pth"
device = "cuda" if torch.cuda.is_available() else "cpu"
print(f"device is {device}")
model_type = "vit_b"

sam = sam_model_registry[model_type](checkpoint=sam_checkpoint)
sam.to(device=device)
predictor = SamPredictor(sam)

image = cv2.imread("./dog.jpeg")
image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

predictor.set_image(image)

input_point = np.array([[1300, 800]])
input_label = np.array([1])

plt.figure(figsize=(10, 10))
plt.imshow(image)
show_points(input_point, input_label, plt.gca())
plt.axis('off')
plt.show()
print(f"{time.time()}: start to predict")
masks, scores, logits = predictor.predict(
    point_coords=input_point,
    point_labels=input_label,
    multimask_output=True,
)
print(f"{time.time()}: finish predict")
print(scores)
index = np.argmax(scores)

plt.figure(figsize=(10, 10))
plt.imshow(image)
show_mask(masks[index], plt.gca())
show_points(input_point, input_label, plt.gca())
plt.title(f"Mask {index + 1}, Score: {scores[index]:.3f}", fontsize=18)
plt.axis('off')
plt.show()
