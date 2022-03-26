//
// Created by admin on 2022/3/24.
//

#ifndef DATASTRUCTURE_ARRAYLIST_H
#define DATASTRUCTURE_ARRAYLIST_H

#include"linearList.h"
namespace repetition{
template<class T>
class arrayList : public linearlist<T>
{
public:
    ///构造函数，复制构造函数和析构函数
    arrayList(int initialCapactipy =10);
    arrayList(const arrayList<T>&);//拷贝构造函数
    ~arrayList() {delete [] element;}

    ////方法
    bool empty() const  {return listSize==0;}
    int size() const { return listSize;}
    T& get(int theIndex) const;
    void indexof(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(std::ostream & out) const;

    ///其他方法
    int capacity() const {return arrayLength;}
protected:
    int initialCapactipy;
    void checkIndex(int theIndex) const;///若索引无效，则抛出异常
    T* element;   ///存储线性表元素的一维数组
    int arrayLength;     //数组的容量
    int listSize;     //线性表的元素个数

};
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{

}
}
#endif //DATASTRUCTURE_ARRAYLIST_H
