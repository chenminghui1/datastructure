cmake_minimum_required(VERSION 3.22)
project(datastructure)

include_directories(../linearlist)
add_executable(chain chainNode.h test_chain.cpp chain.h)