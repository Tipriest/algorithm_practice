### 使用说明

1、修改训练脚本的训练数据路径。如bisai.py中第343行data_root改成数据集与标注的根目录，并且修改344行ann_file为标注pk相对data_root的路径。修改bisai.py最后一行work_dir为本地保存路径。
2、利用csv2pk.py生成ann_file。ann_file为一个dict的pickle保存结果，每个key是每个输入图片的绝对路径，对应的value也是一个dict: {'h': 图像高度, 'w': 图像宽度, 'b': 篡改框标注的numpy array且type为int64}。其中篡改框的标注形状为(n, 5)，其中n为篡改文本的数量，第2维度5的前4个是篡改框坐标最后一个固定为0，形式是(x_min, y_min, x_max, ymax, 0)。
3、训练命令是bash tools/dist_train.sh [配置文件] [显卡数量]
