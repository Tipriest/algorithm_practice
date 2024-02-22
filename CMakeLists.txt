cmake_minimum_required(VERSION 3.5)

# 设置项目名称
project(ProjectName)

# 设置C++编译标准（可根据需要修改）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
set(SOURCES
    src/main.cpp
    # src/foo.cpp
    # src/bar.cpp
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 可选：添加头文件路径
# include_directories(include)

# 可选：添加链接的库
# target_link_libraries(${PROJECT_NAME} library_name)

# 可选：设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../devel)

# 可选：定义编译选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# 可选：定义调试选项
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# 可选：定义发布选项
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")