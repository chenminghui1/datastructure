//
// Created by admin on 2022/3/28.
//

#ifndef DATASTRUCTURE_CHAINNODE_H
#define DATASTRUCTURE_CHAINNODE_H
namespace repition{
    template<typename T>
    struct chainNode{
        //数据成员
        T element;
        //单向链表
        //chainNode<T> * next;
        //双向链表
        chainNode<T> * pred;//前驱结点
        chainNode<T> * succ;//后驱结点
        //构造和析构
        chainNode() {}
        chainNode(const T& element,chainNode<T> * pred = nullptr,chainNode<T> succ=nullptr)
        : element(element), pred(pred),succ(succ)
        {
        }
        //方法
        T data();//返回当前节点储存数据对象
        chainNode insertAsPred(T const& e);//插入前驱结点
        chainNode insertAsSucc(T const& e);//插入后驱结点
    };
    template<typename T>
    using chainNodepos = chainNode<T>*;
}
#endif //DATASTRUCTURE_CHAINNODE_H
