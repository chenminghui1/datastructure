//
// Created by admin on 2022/3/29.
//

#ifndef DATASTRUCTURE_VECTOR_H
#define DATASTRUCTURE_VECTOR_H
#define DEFAULT_CAPACITY 3//默认初始容量
#include"algorithm"
namespace repition{
    template<typename T>
    class Vector{
        public:
        //构造和析构函数
        Vector(int initialCapacity=DEFAULT_CAPACITY);
        Vector(const Vector<T> & theVector);
        Vector(const Vector<T> &theVector, const int lo,const int hi);
        ~Vector();

        //ADT接口
        int size() const ;//返回当前元素总数
        T get(int theIndex) const;//获取秩为r的元素
        void put(int theIndex,const T& theElement) ;//修改theIndex上的元素置为theElement
        void insert(int theIndex,const T& theElement);
        void remove(int theIndex);
        int disordered();//返回非有序元素的个数
        void sort();//调整各元素的位置，使之按照非降序排列
        T* find(const T& theElement) const;//查找元素theEmlent
        T search(const T& theElement) const;//查找元素theElement，返回不大于theElement且最后的元素
        void deduplicat();//剔除重复元素，适用于向量
        void uniquify() ;//剔除重复元素，适用于有序向量
        void travers() ;//遍历向量并统一处理所有的元素，处理方法有函数对象指定
        void copyFrom( T const * A,T* begin,T* end);//
        void copyFrom(T*const A,int lo, int hi);

        ///动态空间管理
        void expend();//在向量空间不足时时进行扩容

    protected:
    private:
        int vector_size;//规模
        int capacity;//容量
        T * element;//数据区
    };

    template<typename T>
    Vector<T>::Vector(int initialCapacity) {
        element= new T[initialCapacity];
        vector_size=0;
    }

    template<typename T>
    Vector<T>::Vector(const Vector<T> &theVector,int lo,int hi) {
        copyFrom(theVector,lo,hi);
    }

    template<typename T>
    Vector<T>::~Vector() {
        delete [] element;
    }

    template<typename T>
    void Vector<T>::copyFrom(T *const A, int lo, int hi) {
        //复杂度取决于循环，即hi-lo的大小
        element= new T[capacity=2*(hi-lo)];//*2避免发生扩容操作
        vector_size =0;
        while(lo < hi)//左闭右开
            element[vector_size++]=A[lo++];//尽量简洁是一种好习惯。
    }
    template<typename T>
    void Vector<T>::expend() {
        if(vector_size<capacity) return;//尚未满员时不进行扩容
        capacity=std::max(capacity,DEFAULT_CAPACITY);//不小于最小容量
        T* oldElement = element; element = new T[capacity <<= 1];//将容量扩充为2倍
        for(int i = 0;i<vector_size;i++)
        element[i]=oldElement[i];
        delete []oldElement;//释放原空间
    }
}
#endif //DATASTRUCTURE_VECTOR_H
