cmake_minimum_required(VERSION 3.20)
project(Lessons32_JSON)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Lessons32_JSON main.cpp)

target_link_libraries(Lessons32_JSON PRIVATE nlohmann_json::nlohmann_json)