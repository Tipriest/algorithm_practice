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
leetcode使用的都是C++和Python的标准库，因此不需要额外的配置，因为已经配置好了`launch.json`文件，因此直接使用`F5`进行debug或者使用`Ctrl`+`F5`进行运行即可，在cpplib中对于一些库的练习可能需要使用者进行额外的安装


### Pinocchio Related
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

---