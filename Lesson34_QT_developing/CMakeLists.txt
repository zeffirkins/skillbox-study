cmake_minimum_required(VERSION 3.20)
project(Lesson34_QT_developing)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5 COMPONENTS

        Core

        Gui

        Widgets

        REQUIRED)

add_executable(Lesson34_QT_developing main.cpp)
target_link_libraries(Qt5::Core INTERFACE

        Qt5::Gui

        Qt5::Widgets
        INTERFACE)