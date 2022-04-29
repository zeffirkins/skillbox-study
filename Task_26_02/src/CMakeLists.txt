cmake_minimum_required(VERSION 3.20)

add_executable(Operation main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)
target_include_directories(Operation PUBLIC ${MY_INCLUDE_DIR})