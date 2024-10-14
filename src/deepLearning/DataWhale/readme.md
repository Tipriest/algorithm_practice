### ReadMe.md

command

```
conda create -n AIdefense python=3.10.14
conda activate AIdefense
```

### timeline

24-10-14-1:30 更改输出格式从numpy.float32到float，分数提高至30+分(使用yolov8n-seg, train_set [10000:], test_set[:,10000], epoch = 10)

24-10-14-2:14 更改使用的模型为yolov8m-seg.pt, epochs=30,imgsz=512, 目前看起来一切都好
