cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

project(dad CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Core Gui Widgets)

set(CMAKE_CXX_STANDARD 14)

add_executable(dad dad.cpp)
target_link_libraries(dad
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
