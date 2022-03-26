cmake_minimum_required(VERSION 3.22)
project(datastructure)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(linearlist)
add_library(datastructure library.cpp)
include_directories(linearlist)