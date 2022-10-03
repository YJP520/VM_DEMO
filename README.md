# VM_DEMO
## 一、使用指南
- 1、新建工程（clion）
- 2、将以下文件移动并替换
    - lib：虚拟迷宫的静态链接库
    - interface.h：接口声明
    - main.c：demo主程序
- 3、修改CMakeLists.txt
```c
cmake_minimum_required(VERSION 3.17)
project(你的项目名 C)

set(CMAKE_C_STANDARD 99)

link_directories(lib)
add_executable(${PROJECT_NAME} main.c interface.h)
target_link_libraries(${PROJECT_NAME} libVM_Library.a)
```
- 4、运行
