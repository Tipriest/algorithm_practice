import torch
# import torch_npu
from PIL import Image
import open_clip as clip

# 下载模型至指定缓存路径
model = clip.openai.load_openai_model(
    'ViT-B-32',
    cache_dir="/home/tipriest/Documents/algorithm_practice/pylibs/openclip/weights",
)

model, _, preprocess = clip.create_model_and_transforms(
    'ViT-B-32',
    pretrained='/home/tipriest/Documents/algorithm_practice/pylibs/openclip/weights/ViT-B-32.pt',
)
tokenizer = clip.get_tokenizer('ViT-B-32')

# put inputs and model to npu
image = (
    preprocess(
        Image.open(
            "/home/tipriest/Documents/algorithm_practice/pylibs/openclip/open_clip/docs/CLIP.png"
        )
    )
    .unsqueeze(0)
    .to("cuda")
)
text = tokenizer(["a diagram", "a dog", "a cat"]).to("cuda")
model = model.to("cuda")

with torch.no_grad(), torch.amp.autocast("cuda"):
    image_features = model.encode_image(image)
    text_features = model.encode_text(text)
    image_features /= image_features.norm(dim=-1, keepdim=True)
    text_features /= text_features.norm(dim=-1, keepdim=True)

    text_probs = (100.0 * image_features @ text_features.T).softmax(dim=-1)

print("Label probs:", text_probs)  # prints: [[1., 0., 0.]]
