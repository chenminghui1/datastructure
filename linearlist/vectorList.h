// Copyright (c) 2022. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by admin on 2022/3/28.
//

#ifndef DATASTRUCTURE_VECTORLIST_H
#define DATASTRUCTURE_VECTORLIST_H
#include "linearList.h"
#include "vector"
namespace repetition{
template<typename T>
class vectorList : public linearlist<T>
{
public:
    //构造函数，析构函数
    vectorList(int initialCapacity = 0);
    vectorList(const vectorList<T>&);
    ~vectorList(){delete *element;}
    //ADT方法
    bool empty() const {return element->empty();}
    int size() const {return (int) element->size();}
    T& get(int theIndex) const;
    int erase(int theIndex);
    void indexOf(const T& theElement) const;
    void insert(int theIndex,const T& theElement);
    void output(std::ostream & out) const;

    //
    int capacity() const { return (int) element->capacity();}

    //线性表的起始和结束位置的迭代器
    typedef typename std::vector<T>::iterator iterator;
    iterator begin() {return element->begin();}
    iterator end() {return element->end();}
    //练习需要添加的代码
    //x.half(),可以将x的元素隔一个删除一个
    void half() ;

protected:
    void checkIndex(int theIndex) const;
    std::vector<T>* element;
};
template<typename T>
vectorList<T>::vectorList(int initialCapacity) {
    if(initialCapacity<1){
        ostringstream s;
        s<<" Initial capacity = "<<initialCapacity<<" must be >0";
        throw illegalParameterValue(s.str());
    }
    element = new vector<T>;
    element->reserve(initialCapacity);//容量从0增长到initialCapacity
}
template<typename T>
vectorList<T>::vectorList(const vectorList<T> & theList) {
    //复制构造函数
    element = new vector<T>(*theList.element);
}

    template<typename T>
    int vectorList<T>::erase(int theIndex) {
        checkIndex(theIndex);
        element->erase(begin()+theIndex);
    }

    template<typename T>
    void vectorList<T>::insert(int theIndex, const T &theElement) {
        if(theIndex<0 || theIndex>size())
        {
            ostringstream s;
            s<<" index = "<<theIndex<<"  size = "<<size();
            throw illegalIndex(s.str());
        }
        element->insert(begin()+theIndex,theElement);
    }

};
#endif //DATASTRUCTURE_VECTORLIST_H
