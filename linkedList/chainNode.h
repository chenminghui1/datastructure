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
        chainNode<T> * next;

        //方法
        chainNode() {}
        chainNode(const T& element)
        {
            this->element = element;
        }
        chainNode(const T& element,chainNode<T> * next)
        {
            this->element=element;
            this->next=next;
        }
    };
}
#endif //DATASTRUCTURE_CHAINNODE_H
