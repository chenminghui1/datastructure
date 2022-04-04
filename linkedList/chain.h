//
// Created by admin on 2022/3/28.
//

#ifndef DATASTRUCTURE_CHAIN_H
#define DATASTRUCTURE_CHAIN_H
#include"chain.h"
namespace repition{
    template<typename T>
    class chain{
        private:
        int size; chainNode<T> header; chainNode<T> trailer; //两个哨兵节点
        protected :
        public :
        //初始化
        chain();
        
        
        //ADT
        chainNode<T> insert( T const& e,chainNode<T> p) {size++; insertAsPred(e);};
        chainNode<T> insertAsPred(T const& e);
        T operator[](int theIndex)  const ;

        //排序
        void selectionSort(chainNodePos<T> p,int n);
    };

    template<typename T>
    chain<T>::chain() {
        header = new chainNode<T>;
        trailer = new chainNode<T>;
        header->succ = trailer; header->pred = nullptr;
        trailer->pred = header; trailer-> succ = nullptr;
        size = 0;
    }

    template<typename T>
    T chain<T>::operator[](int theIndex) const {
        //均匀分布式，期望复杂度为（1+2+3。。。+n）/n = O(n)
        chainNodePos<T> p=first;//从首节点出发
        while(0< r--) p=p->succ;
        return p->data;//目标节点
    }

    template<typename T>
    chainNode <T> chain<T>::insertAsPred(const T &e) {
        chain<T> x = new chainNode(e,pred,this);
        pred->succ=x;pred = x;
        return x;
    }

    template<typename T>
    void chain<T>::selectionSort(chainNodePos <T> p, int n) {
        chainNodePos<T> head = p->pred; chainNodePos<T> tail = p;
    }
}
#endif //DATASTRUCTURE_CHAIN_H
