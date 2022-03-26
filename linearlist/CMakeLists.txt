cmake_minimum_required(VERSION 3.22)
project(datastructure)


file(GLOB SRC_LIST "*.cpp") #找到所有的cpp文件
add_library(demo  arraylist.h ${SRC_LIST})  # 明确指定包含哪些源文件