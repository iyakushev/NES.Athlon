cmake_minimum_required (VERSION 3.8)
project("C.NES")
set(PROJECT C.NES)
set(CMAKE_CXX_STANDART 11)

set (CMAKE_INCLUDE_PATH include)
include_directories(${CMAKE_INCLUDE_PATH})

add_subdirectory(src)