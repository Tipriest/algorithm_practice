# AlgorithmPractice

本仓库用于算法、数据结构、数学建模、深度学习、LeetCode、Python基础等多领域的学习与实践，包含大量 C++/Python 代码、笔记、实验和可视化案例。

---

## 目录结构

- `src/`
  - `leetcode/`：LeetCode 算法题解与每日一题
  - `mathematic/`：数学相关算法与可视化（如罗德里格斯公式动图演示）
  - `deepLearning/`：深度学习相关代码与实验
  - `pythonBasic/`：Python 基础、标准库、文件处理、GUI、数据库等
  - `designPattern/`：设计模式相关代码
  - 其他专题文件夹

- `build/`、`cmake-build-debug/`：C++ 项目构建目录
- `CMakeLists.txt`：C++ 项目构建配置
- `.vscode/`、`.idea/`：IDE 配置文件

---

## 环境配置

建议使用 [Anaconda](https://www.anaconda.com/) 或 Miniconda 管理 Python 环境。

### 创建并激活环境

```bash
conda create -n algorithmPractice python=3.8 -y
conda activate algorithmPractice
```

### 安装常用依赖

```bash
pip install pyQt5 pymysql requests pymongo scikit-learn matplotlib scipy parsel prettytable pyinstaller d2l==0.17.6 torch numpy kaggle
```

如需 C++ 支持，建议使用 g++ 或 clang，推荐 VSCode 作为开发环境。

---

## 运行说明

- **C++ 项目**：可用 VSCode 的任务或 CMake 构建，或直接用 g++ 编译。
- **Python 项目**：直接运行 `.py` 文件或 Jupyter Notebook。
- **可视化/动图**：如 `rodrigues_formula.py`，运行后会弹出 3D 动画窗口并可保存 GIF。

---

## 常用快捷键（VSCode）

- `Ctrl + Alt + N`：编译并运行（需 Code Runner 插件）
- `Ctrl + Shift + B`：调用配置好的 g++ 任务编译 C++ 程序

---

## 参考与致谢

- [知乎：VSCode 配置 C++ 环境](https://zhuanlan.zhihu.com/p/80659895)
- [d2l.ai 动手学深度学习](https://zh.d2l.ai/)

---

## 贡献

欢迎提交 PR 或 issue 交流学习心得与改进建议！

---