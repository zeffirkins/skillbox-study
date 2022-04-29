cmake_minimum_required(VERSION 3.20)
project(Lessons_33)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR "C:\\boost_1_78_0")
set(Boost_LIBRARY_DIR "C:\\boost_1_78_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Lessons_33 main.cpp)
target_link_libraries(Lessons_33 ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Lessons_33 ws2_32)
endif()
