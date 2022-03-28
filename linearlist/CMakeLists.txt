cmake_minimum_required(VERSION 3.22)
project(datastructure)


file(GLOB SRC_LIST "*.cpp") #找到所有的cpp文件
add_executable(arraylist  arraylist.h  changeLength1D.h vectorList.h test_arrayList.cpp)  # 明确指定包含哪些源文件
add_executable(vectorList linearList.h vectorList.h ../MyExceptions.h test_vectorList.cpp)