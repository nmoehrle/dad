cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(QT5_INSTALL_PATH "/home/nmoehrle/lib/qt-5-6-1/5.6/gcc_64/lib/cmake/Qt5")

project(DaD CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH ${QT5_INSTALL_PATH} ${CMAKE_PREFIX_PATH})
find_package(Qt5 REQUIRED Core Gui Widgets)

set(CMAKE_CXX_STANDARD 14)

add_executable(DaD dad.cpp)
target_link_libraries(DaD
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
