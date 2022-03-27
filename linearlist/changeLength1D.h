//
// Created by admin on 2022/3/27.
//

#ifndef DATASTRUCTURE_CHANGELENGTH1D_H
#define DATASTRUCTURE_CHANGELENGTH1D_H


template <class T>
void changeLength1D(T*& a, int oldLength, int newLength){
    if(newLength < 0)
        throw "new length must be >= 0";
    T* temp = new T[newLength];  // 新数组
    int number = std::min(oldLength, newLength);  // 需要复制的元素个数
    copy(a, a + number, temp);
    delete [] a;  // 释放老数组的内存空间
    a = temp;
}

#endif //DATASTRUCTURE_CHANGELENGTH1D_H
