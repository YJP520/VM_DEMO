cmake_minimum_required(VERSION 3.23)
project(MY_VM C)

set(CMAKE_C_STANDARD 99)

link_directories(lib)
add_executable(MY_VM main.c interface.h)
target_link_libraries(${PROJECT_NAME} libVM_Library.a)