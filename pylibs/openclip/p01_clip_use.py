import torch
from PIL import Image
import open_clip
import time

model, _, preprocess = open_clip.create_model_and_transforms(
    'ViT-B-32', pretrained='laion2b_s34b_b79k'
)
model.eval()  # model in train mode by default, impacts some models with BatchNorm or stochastic depth active
tokenizer = open_clip.get_tokenizer('ViT-B-32')

for i in range(1000):
    time0 = time.time()
    image = preprocess(Image.open("open_clip/docs/CLIP.png")).unsqueeze(0)
    text = tokenizer(["a diagram", "a dog", "a cat"])

    with torch.no_grad(), torch.autocast("cuda"):
        time1 = time.time()
        image_features = model.encode_image(image)
        time2 = time.time()
        text_features = model.encode_text(text)
        time3 = time.time()
        image_features /= image_features.norm(dim=-1, keepdim=True)
        text_features /= text_features.norm(dim=-1, keepdim=True)
        text_probs = (100.0 * image_features @ text_features.T).softmax(dim=-1)
        time4 = time.time()
        print(f"preprocess   time: {time1 - time0:.3f}")
        print(f"encode_image time: {time2 - time1:.3f}")
        print(f"encode_text  time: {time3 - time2:.3f}")
        print(f"postrocess   time: {time4 - time3:.3f}")
# print("Label probs:", text_probs)  # prints: [[1., 0., 0.]]
