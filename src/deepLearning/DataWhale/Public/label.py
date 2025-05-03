import os, shutil
import glob
import json
import cv2
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

"""
Format Train and Test Set
"""
BASE_DATA_PATH = "/home/tipriest/data/seg_risky"
YOLO_SEG_LABEL_BASE_PATH = os.path.join(BASE_DATA_PATH, "datasetLabel")
YOLO_SEG_LABEL_TRAIN_PATH = os.path.join(YOLO_SEG_LABEL_BASE_PATH, "train/")
YOLO_SEG_LABEL_VALID_PATH = os.path.join(YOLO_SEG_LABEL_BASE_PATH, "valid/")


training_anno = pd.read_csv(os.path.join(
    BASE_DATA_PATH, "seg_risky_training_anno.csv"))
train_jpgs = []
for i in range(0, 2, 1):
    train_jpgs += [x.replace('/home/tipriest/data/seg_risky/', '')
                   for x in glob.glob(os.path.join(BASE_DATA_PATH, f'{i}/*.jpg'))]
training_anno = training_anno[training_anno['Path'].isin(train_jpgs)]
training_anno['Polygons'] = training_anno['Polygons'].apply(json.loads)


if os.path.exists(YOLO_SEG_LABEL_BASE_PATH):
    shutil.rmtree(YOLO_SEG_LABEL_BASE_PATH)
os.makedirs(YOLO_SEG_LABEL_TRAIN_PATH)
os.makedirs(YOLO_SEG_LABEL_VALID_PATH)

for row in training_anno.iloc[:100].iterrows():
    shutil.copy(os.path.join(BASE_DATA_PATH,
                row[1].Path), YOLO_SEG_LABEL_TRAIN_PATH)
    img = cv2.imread(os.path.join(BASE_DATA_PATH, row[1].Path))
    if img is None:
        print("Error: 无法读取图像 ", row[1].Path)
    img_height, img_width = img.shape[:2]
    # 在图像上绘制标注
    for polygon in row[1].Polygons:
        pts = np.array(polygon, np.int32)
        pts = pts.reshape((-1, 1, 2))
        # pts = np.array([[25, 70], [25, 160],
        #                 [110, 200], [200, 160],
        #                 [200, 70], [110, 20]],
        #                 np.int32)
        print(pts)
        print("////////////")
        pts = pts.reshape((-1, 1, 2))
        print(pts)
        img = cv2.polylines(img, [pts], isClosed=True, color=(
            0, 255, 0), thickness=3)  # 绘制绿色多边形
        print(os.path.join(YOLO_SEG_LABEL_VALID_PATH, row[1].Path))
        # cv2.waitKey(500)
        result = cv2.imwrite(os.path.join(YOLO_SEG_LABEL_VALID_PATH, "1a2e85.jpg"), img)
        # result = cv2.imwrite("/home/tipriest/data/seg_risky/datasetLabel/valid/test.jpg", img)
        cv2.imshow("Name", img)

        # cv2.waitKey(10)
        # if result:
        #     print("保存成功")
        # else:
        #     print("保存失败")