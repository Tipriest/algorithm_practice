import os
import cv2
from PIL import Image

def get_image_info(image_path):
    try:
        with Image.open(image_path) as img:
            info = {
                "类型": "图片",
                "文件名": os.path.basename(image_path),
                "格式": img.format,
                "模式": img.mode,
                "分辨率": img.size,  # (宽, 高)
                "色深": img.bits if hasattr(img, 'bits') else "未知",
                "通道数": len(img.getbands()),
                "文件大小(字节)": os.path.getsize(image_path)
            }
            return info
    except Exception as e:
        return {"错误": f"无法读取图片信息: {e}"}

def get_video_info(video_path):
    try:
        cap = cv2.VideoCapture(video_path)
        if not cap.isOpened():
            return {"错误": "无法打开视频文件"}
        info = {
            "类型": "视频",
            "文件名": os.path.basename(video_path),
            "分辨率": (int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)), int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))),
            "帧率(FPS)": cap.get(cv2.CAP_PROP_FPS),
            "总帧数": int(cap.get(cv2.CAP_PROP_FRAME_COUNT)),
            "时长(秒)": cap.get(cv2.CAP_PROP_FRAME_COUNT) / cap.get(cv2.CAP_PROP_FPS) if cap.get(cv2.CAP_PROP_FPS) > 0 else "未知",
            "编码格式": cap.get(cv2.CAP_PROP_FOURCC),
            "文件大小(字节)": os.path.getsize(video_path)
        }
        cap.release()
        return info
    except Exception as e:
        return {"错误": f"无法读取视频信息: {e}"}

def print_info(info):
    for k, v in info.items():
        print(f"{k}: {v}")

def main(file_path):
    if not os.path.isfile(file_path):
        print("文件不存在！")
        return
    ext = os.path.splitext(file_path)[1].lower()
    image_exts = ['.jpg', '.jpeg', '.png', '.bmp', '.tiff', '.gif', '.webp']
    video_exts = ['.mp4', '.avi', '.mov', '.mkv', '.flv', '.wmv', '.webm', '.mpeg', '.mpg']
    if ext in image_exts:
        info = get_image_info(file_path)
    elif ext in video_exts:
        info = get_video_info(file_path)
    else:
        # 尝试用PIL打开，失败再尝试用cv2.VideoCapture
        try:
            with Image.open(file_path) as img:
                info = get_image_info(file_path)
        except Exception:
            info = get_video_info(file_path)
    print_info(info)

if __name__ == "__main__":
    # path = input("请输入图片或视频文件路径：").strip()
    path = "/home/tipriest/output.mkv"
    main(path)
    