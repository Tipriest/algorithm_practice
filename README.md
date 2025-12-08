# AlgorithmPractice

本仓库用于算法、数据结构、数学建模、深度学习、LeetCode、Python基础等多领域的学习与实践，包含大量 C++/Python 代码、笔记、实验和可视化案例。

---

## 目录结构
├── .vscode  
├── cpplibs  
│   ├── eigen  
│   ├── exception  
│   ├── pinocchio  
│   └── time  
├── cpptest  
│   ├── nan  
│   └── nan.cpp  
├── designPattern  
├── leetcode  
│   ├── arrayAndmatrix  
│   ├── backTracking  
│   ├── binaryOperation  
│   ├── binaryTree  
│   ├── design  
│   ├── dynamicPlanning  
│   ├── enum  
│   ├── everyDayLeetcode  
│   ├── geometry  
│   ├── graph  
│   ├── greedy  
│   ├── hashMap  
│   ├── linkedList  
│   ├── math  
│   ├── prefixSum  
│   ├── priorityQueue  
│   ├── recursive  
│   ├── segmentTree  
│   ├── simulation  
│   ├── slidingWindow  
│   ├── sort  
│   ├── stackAndQueue  
│   ├── string  
│   ├── template.cpp  
│   ├── template.py  
│   ├── test  
│   ├── twoPointers  
│   └── weekComp  
├── README.md  


---

## 环境配置与运行说明

### Python环境配置（推荐使用Conda）

本项目提供了conda环境配置文件，适用于Ubuntu 20.04和22.04系统。

#### 1. 安装Miniconda/Anaconda

如果还未安装conda，请先安装：

```bash
# 下载Miniconda（推荐）
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
bash Miniconda3-latest-Linux-x86_64.sh

# 或下载Anaconda
wget https://repo.anaconda.com/archive/Anaconda3-2023.09-0-Linux-x86_64.sh
bash Anaconda3-2023.09-0-Linux-x86_64.sh
```

#### 2. 创建并激活环境

```bash
# 使用environment.yml创建环境
conda env create -f environment.yml

# 激活环境
conda activate algo_practice
```

#### 3. 验证安装

```bash
# 验证Python版本
python --version

# 验证关键库
python -c "import torch; import numpy; import sklearn; print('Environment ready!')"
```

#### 4. 环境管理常用命令

```bash
# 查看所有环境
conda env list

# 更新环境
conda env update -f environment.yml --prune

# 导出当前环境
conda env export > environment_backup.yml

# 删除环境
conda env remove -n algo_practice

# 退出环境
conda deactivate
```

### C++环境配置

leetcode使用的都是C++和Python的标准库，因此不需要额外的配置，因为已经配置好了`launch.json`文件，因此直接使用`F5`进行debug或者使用`Ctrl`+`F5`进行运行即可，在cpplib中对于一些库的练习可能需要使用者进行额外的安装


### Pinocchio Related
  1. install Pinocchio, refer to this [doc](https://stack-of-tasks.github.io/pinocchio/download.html)
  2. install robot model, refer to this [doc](https://github.com/Gepetto/example-robot-data/tree/6ed0cc91241562972190da6e69430834ae2b1158).in fact, just use the command below:
```bash
sudo apt install robotpkg-py3\*-example-robot-data

```
  Pinocchio库的`compile and debug`需要链接很多库，因此单独在`tasks.json`中定义Pinocchio库的编译方法
  练习相关代码的编译方式，如果需要运行该部分代码，请将`launch.json`文件中的`preLaunchTask`一项更改如下所示:
  ```
  "preLaunchTask": "compile_with_pinocchio",
  ```

如需 C++ 支持，建议使用 g++ 或 clang，推荐 VSCode 作为开发环境。

---


## 参考与致谢

- [知乎：VSCode 配置 C++ 环境](https://zhuanlan.zhihu.com/p/80659895)
- [d2l.ai 动手学深度学习](https://zh.d2l.ai/)
- [VScode权威指南](https://weread.qq.com/web/reader/7bc32db071f02f257bc2a8a)

---

## 贡献

欢迎提交 PR 或 issue 交流学习心得与改进建议！