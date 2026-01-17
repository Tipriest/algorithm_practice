from ultralytics import FastSAM

model = FastSAM(
    '/home/tipriest/Documents/algorithm_practice/pylibs/FastSAM/weights/FastSAM-x.pt'
)

# model1 = YOLO('../model/FastSAM_X.pt')
# model.export(format='onnx' )
results = model.export(format='onnx', opset=12)
