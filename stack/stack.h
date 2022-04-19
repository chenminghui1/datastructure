//
// Created by admin on 2022/4/5.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H
namespace repetition{
template<typename T>
class stack{
    public:
    //构造与析构函数
    stack(int initialCapacity =3) : capacity(initialCapacity),size(0){}//初始化
    stack(const stack<T> & t);//复制初始化
    ~stack();

    //ADT操作
    bool empty();
    void push(const T& t);
    void expand();//当栈满时，需要将栈空间进行扩充

    private:
    int capacity;//栈的容量
    int size;//站内元素个数
    T* s;
    protected:
};

    template<typename T>
    bool stack<T>::empty() {
        return size? true:false;
    }

    template<typename T>
    void stack<T>::push(const T &t) {
        if (capacity<=size)
            expand();
        s[size++]=t;
    }

    template<typename T>
    void stack<T>::expand() {
        T* newstack = new T[2*capacity];
        for(int i=0;i<size;i++)
            newstack[i]=s[i];//逐步拷贝
        this->capacity=2*capacity;
        s = newstack;delete [] newstack;
    }
}
#endif //DATASTRUCTURE_STACK_H
