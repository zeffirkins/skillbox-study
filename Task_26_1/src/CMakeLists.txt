cmake_minimum_required(VERSION 3.20)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(MySkillboxApp main.cpp ${MY_INCLUDE_DIR}/my-math.h my-math.cpp )
target_include_directories(MySkillboxApp PUBLIC ${MY_INCLUDE_DIR})
