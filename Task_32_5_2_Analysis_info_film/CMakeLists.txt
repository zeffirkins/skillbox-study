cmake_minimum_required(VERSION 3.20)
project(Task_32_5_2_Analysis_info_film)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_executable(Task_32_5_2_Analysis_info_film main.cpp)

add_subdirectory(nlohmann_json)

target_link_libraries(Task_32_5_2_Analysis_info_film PRIVATE nlohmann_json::nlohmann_json)