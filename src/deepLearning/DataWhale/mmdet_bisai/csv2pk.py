import os
import csv
import json
import pickle
import imagesize
import numpy as np
import pandas as pd
from tqdm import tqdm

# put this script into the same dir with "release_train_simple.csv" and datas (e.g., 0/ 1/ 2/ ...)
data_path = "home/tipriest/data/seg_risky"
root = os.path.abspath(os.getcwd())

pk_dict = {}
data = pd.read_csv(
    '/home/tipriest/data/seg_risky/training_anno.csv', low_memory=False)
for index, row in tqdm(data.iterrows()):
    row0 = row[0]
    imgnm = row0.split('/')[-1]
    w, h = imagesize.get(os.path.join(data_path, row0))
    # print(json.loads(row[1]))
    bbox = [np.array(x, dtype=np.int64) for x in json.loads(os.path.join(data_path, row[1]))]
    b = np.array([(bb[:, 0].min(), bb[:, 1].min(), bb[:, 0].max(),
                 bb[:, 1].max(), 0) for bb in bbox], dtype=np.int64)
    pk_dict[os.path.join(data_path, row0)] = {'w': w, 'h': h, 'b': b}

with open('/home/tipriest/data/seg_risky/train.pk', 'wb') as f:
    pickle.dump(pk_dict, f)
