cmake_minimum_required(VERSION 3.8)
project(rundialog-qt)

set(CMAKE_CXX_STANDARD 11)

include(GNUInstallDirs)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

add_subdirectory(src)
add_subdirectory(res)
