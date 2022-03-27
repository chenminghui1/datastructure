//
// Created by admin on 2022/3/24.
//

#ifndef DATASTRUCTURE_ARRAYLIST_H
#define DATASTRUCTURE_ARRAYLIST_H

#include"linearList.h"
#include "sstream"
#include <exception>
#include <iterator>
#include <algorithm>
#include "changeLength1D.h"
#include "../MyExceptions.h"
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
    int indexof(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(std::ostream & out) const;

    ///其他方法
    int capacity() const {return arrayLength;}
    //返回指定元素最后出现时的索引
    int lastIndex(const T& theElement) const;

    //尾插入
    void push_back(const T& theElement);

    //尾弹出
    void pop_back();

    //设置大小
    void setSize(int theSize);

    //改变数组的容量为当前容量和theCapacity的较大者
    void reserve(int theCapacity);

    //用元素theElement替换索引为theIndex的元素
    void set(int theIndex, const T& theElement);

    //删除指定范围内的所有元素
    void removeRange(int beginIndex, int endIndex);

    //翻转数组
    void reverse();

    //交换两个数组
    void swap(arrayList<T>& theList);

    //清空数组
    void clear();

    // 判断两个数组是否相等
    bool isEqual(const arrayList<T>& theList) const;

    //判断当前数组是否小于theList数组
    bool isLess(const arrayList<T>& theList) const;

    // 判断当前数组是否大于theList数组
    bool isBigger(const arrayList<T>& theList) const;

    //设置表的大小，用在第7章的稀疏矩阵中
    void reSet(int theSize);

    //重载[]运算符
    T& operator[](int theIndex) {
        //返回数组在索引theIndex上的引用

        //检查索引是否有效
        checkIndex(theIndex);
        return element[theIndex];
    }
protected:
    int initialCapactipy;
    void checkIndex(int theIndex) const;///若索引无效，则抛出异常
    T* element;   ///存储线性表元素的一维数组
    int arrayLength;     //数组的容量
    int listSize;     //线性表的元素个数
public:
    //内部类，迭代器，可以随机访问
    class iterator
    {

    };

};
///构造函数的时间复杂度是O(initialCapacity)
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity < 1)
    {
        std::ostringstream s;
        s<<"Initial capacity = " <<initialCapacity<< " must Be >0";
        throw s.str();
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}
template<typename T>
void arrayList<T>::checkIndex(int theIndex) const {
    ///时间复杂度是O（1）
    if(theIndex<0  || theIndex>=listSize) {
        std::ostringstream s;
        s << "index = " << theIndex << "size = " << listSize;
        throw s.str();
    }
}

    template<class T>
    T &arrayList<T>::get(int theIndex) const {
        ///时间复杂度O(1);
        checkIndex(theIndex);
        return element[theIndex];
    }

    template<class T>
    int arrayList<T>::indexof(const T &theElement) const {
        ///返回元素theElement第一次出现的索引，如果不存在，则返回-1.
        ///时间复杂度是O(listSize();
        int theIndex = (int) (std::find(element,element+listSize,theElement)-element);
        if(theIndex==listSize)
            return -1;
        else return theIndex;
    }

    template<class T>
    void arrayList<T>::erase(int theIndex) {
        ///时间复杂度是O(listSize-theIndex).
        checkIndex(theIndex);
        //使用std中的copy算法，实现减少长度时要将theIndex后的元素统一向前移动的要求
        std::copy(element+theIndex+1,element+listSize,element+theIndex);
        element[--listSize].~T();//调用析构函数
        ///当listSize<arraylength/4时，减少数组长度
        if(listSize<(arrayLength/4)){
            int maxsize= std::max(initialCapactipy,arrayLength);
            changeLenth1D(element,arrayLength,maxsize);
            arrayLength=maxsize;
        }
    }

    template<class T>
    void arrayList<T>::insert(int theIndex, const T &theElement) {
        ///插入元素，首先要将从theIndex到listSize的元素全部向后移动一位，
        ///向右移动的操作利用STL函数copy_backward完成
        checkIndex(theIndex);
        ///如果数组已满，首先要将数组扩容。
        if(listSize==arrayLength)
        {
            changeLength1D(element,arrayLength,2*arrayLength);
            arrayLength*=2;
            ///为什么数组扩容不是增加1或2？因为当连续插入时，每次增加数组长度的时间是很长。
            ///如果我们总是安一个乘法因子来增加数组长度，那么实施一系列线性表的操作所需时间与不用改变数组长度相比，之多增加一个常数因子。
        }
        ///移动元素
        std::copy_backward(element+theIndex,element+listSize,element+theIndex+1);
        element[theIndex]=theElement;
        listSize++;

        //
    }

    template<class T>
    void arrayList<T>::output(std::ostream &out) const {
        //把线性表插入输出流
        std::copy(element,element+listSize,std::ostream_iterator<T>(out," "));
    }
    //
}
#endif //DATASTRUCTURE_ARRAYLIST_H
