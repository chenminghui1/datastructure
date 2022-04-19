//
// Created by admin on 2022/3/28.
//

#ifndef DATASTRUCTURE_CHAIN_H
#define DATASTRUCTURE_CHAIN_H
#include"chainNode.h"
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
        chainNodePos<T> selectMax(chainNodePos<T> p,int n);//从起始与位置p的n个元素中挑出最大者

        //排序
        void selectionSort(chainNodePos<T> p,int n);//选择排序
        void insertionSort(chainNodePos<T> p,int n)//插入排序
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
        chainNodePos<T> p=this->pred;//从首节点出发
        while(0< theIndex--) p=p->succ;
        return p->data;//目标节点
    }



    template<typename T>
    void chain<T>::selectionSort(chainNodePos <T> p, int n) {
        chainNodePos<T> head = p->pred; chainNodePos<T> tail = p;//待排序区间（head，trial）
        for(int i = 0 ;i< n;i++) tail = tail->succ;
        while(1< n){//反复从待排序区间中找出最大者，并移至有序区间前端
            //insert与remove这两个操作，因为要用到new和delect这两个操作，所以，实际要消耗的
            //的时间是估算出来的100倍，因此，要尽量少使用这两个操作。
            insert(tail,remove(selectMax(head->succ, n)));
            tail = tail->pred; n--;//待排序区间，有序区间的范围，均同步更新
        }
    }

    template<typename T>
    chainNodePos <T> chain<T>::selectMax(chainNodePos <T> p, int n) {
        chainNodePos<T> max = p;
        for (chainNodePos<T> cur = p;1<n;n--)
            if(!lt(cur=cur->succ)->data,max->data))  //data>= max
                max = cur;//则更新最大元素位置记录
        return max;//返回最大节点的位置
    }

    template<typename T>
    void chain<T>::insertionSort(chainNodePos<T> p, int n) {
        //输入敏感的：最终的复杂度与输入的特性是相关的
        for(int r = 0; r<n;r++)//逐一引入各节点，
        {
            insert(search(p->data,r,p),p->data);//查找+插入
            p = p->succ;
            remove(p->pred);//转向下一结点
        }//n次迭代，每次O（r+1），仅使用O（1）辅助空间，属于就地算法
    }
}
#endif //DATASTRUCTURE_CHAIN_H
