# README.md
多机之间进行联系:
## 1 可视化的订阅端Client
```shell
# 可视化的主机的显示端:
sudo snap install rerun

# 查看snap安装的rerun版本
rerun-cli 0.27.2 (map_view nasm native_viewer) [rustc 1.88.0 (6b00bc388 2025-06-23), LLVM 20.1.5] x86_64-unknown-linux-gnu
Video features: av1 default ffmpeg nasm serde
```
## 2 发送数据的服务端Server
```shell
# 首先注意需要安装与前面显示的相同版本的sdk
pip install rerun-sdk==0.27.2
```
## 3 然后使用 p04_connect_grpc.py 可以使用grpc进行通讯
