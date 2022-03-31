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
        T remove(int theIndex);//删除元素
        int  remove(int lo,int hi);//区间删除
        int disordered() const;//返回非有序元素的个数
        void sort();//调整各元素的位置，使之按照非降序排列
        T* find(const T& theElement) const;//查找元素theEmlent
        /*要支持查找操作，对于
         *无需向量：T为可判等的基本类型，或已重载==或！=操作符
         * 有序向量：T为可比较的基本类型，或已重载操作符<或>
         * */
        int find(const T& theElement,int lo,int hi);//查找元素，返回
        int search(const T& theElement,int lo,int hi) const;//查找元素theElement，适用于有序向量的版本
        void deduplicat();//剔除重复元素，适用于向量
        int uniquify() ;//剔除重复元素，适用于有序向量
        void travers() ;//遍历向量并统一处理所有的元素，处理方法有函数对象指定
        void copyFrom( T const * A,T* begin,T* end);//
        void copyFrom(T*const A,int lo, int hi);
        bool checkIndex(int theIndex);//检查索引是否合规
        void shrink();

        ///动态空间管理
        void expend();//在向量空间不足时时进行扩容


        ///重载操作符
        T& operator[](int r) const;//&可以让其成为左值
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

    template<typename T>
    T &Vector<T>::operator[](int r) const{
        return element[r];
    }

    template<typename T>
    void Vector<T>::insert(int theIndex, const T &theElement) {
        //所有后缀元素全部右移一位
        expend();//
        for(int i = vector_size;i>theIndex;i--)//所有后方元素右移
        {
            element[i]=element[i-1];
        }
        element[theIndex] = theElement;
        vector_size++;

    }

    template<typename T>
    int Vector<T>::remove(int lo, int hi) {
        if(lo==hi) return 0;
        while (hi<vector_size) element[lo++] = element[hi++];
        vector_size=vector_size-hi+lo;
        shrink();
        return hi-lo;//返回被删除元素的数目
    }

    template<typename T>
    void Vector<T>::shrink() {
        if(vector_size>(capacity/2)) return;//装填椅子大于1/2时，不锁容
        capacity=std::max(capacity/2,DEFAULT_CAPACITY);//不小于最小容量
        T* oldElement = element;element= new T[capacity];
        for(int i = 0;i<vector_size;i++)
            element[i]=oldElement[i];
        delete [] oldElement;
    }

    template<typename T>
    T Vector<T>::remove(int theIndex) {
        //复杂度为O（vector_size-theIndex）
        T e = element[theIndex];//备份被删除操作
        remove(theIndex,theIndex+1);//将单个删除视为区间删除的一个特例
        //不能再区间删除中反复调用单个删除，因为复杂度可能会变为O(n^2),而区间删除的原有复杂度为O（n）
        return e;
    }
    template<typename T>
    int Vector<T>::find(const T &theElement, int lo, int hi) {//输入敏感算法
        while((lo<hi--)&&(theElement!=element[hi]))
            return hi;
    }

    template<typename T>
    void Vector<T>::deduplicat() {
        //整体复杂度是O（n^2）,主要来自find（）和remove（）
        int oldsize = vector_size;
        for(int i=0;i,i<vector_size;)
        {
            if(find(element[i],0,i)<0)//在前缀中查找是否存在
                i++;
            else
                remove(i);
        }
    }

    template<typename T>
    int Vector<T>::disordered() const{
        int n;//计数器
        for(int i = 1;i<vector_size;i++)
        n += (element[i-1]>element[i]);//逆序则计数
        return n;//向量有序当且仅当n=0；
    }

    template<typename T>
    int Vector<T>::uniquify() {
        /*自写版本
        T j{0};
        for(int i=1;i<vector_size-1;i++)
        {
            if(element[i]!=element[j] )
            {
                remove(j,i);
                i=j++;
            }
        }
        */
        /*低效算法，不推荐使用
         * 在最坏情况下，while中每次都要调用remove操作，O（n^2）
        int oldsize = vector_size; int i=0;
        while(i<vector_size-1)
        {
            (element[i]==element[i+1]) ? remove(i+1):i++;
            return oldsize-vector_size;
        }
         */
        //老师版本，复杂度为O（n）
        int i=0,j=0;
        while(++j<vector_size)
            if(element[i]!=element[j]) element[++i]=element[j];
        vector_size = ++i; shrink();//直接截除尾部多余元素
        return j-i;
        //通过remove（lo,hi)批量删除仍然不能达到高效率
    }

    template<typename T>
    int Vector<T>::search(const T &theElement ,int lo, int hi) const {
        //为便于有序向量自身的维护，应返回不大于e的最后一个元素
        return (rand()%2) ?  binSearch(theElement,lo,hi) : fibSearch(theElement,lo,hi);
    }
}
#endif //DATASTRUCTURE_VECTOR_H
