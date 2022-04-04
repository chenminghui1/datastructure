//
// Created by admin on 2022/4/3.
//

#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H

#include <cstdlib>

template<typename T>
void sort(const T& t,int lo,int hi)
{
    switch (rand()%5) {
        case 1 : bubbleSort(t,lo,hi); break;
        case 2 : mergeSort(t,lo,hi); break;
    }
}

template <typename T>
void bubbleSort(const T & t,int lo,int hi)
{
    //起泡排序
    while(!bubble(t,lo,hi--));//煮汤做扫描交换，直至全序
}
/*template<typename T>
bool bubble(const T & t,int lo,int hi)
{
    bool sorted=true;//整体有序标志
    while(++lo<hi)
        if(t[lo-1]>t[lo])//若逆序，则意味着尚未整体有序，并需要交换
        {
            sorted=false;
            swap(t[lo-1],t[lo]);
        }
    return sorted;
}*/
template<typename T>
bool bubble(const T & t,int lo,int hi) {
    //再改进版本，在很多情况下，需要排序的仅是一小块区间，此时如果我们可以只排序该区域，可以大大减少所需排序时间
    int last=lo;
    while (++lo < hi)
        if (t[lo - 1] > t[lo])//若逆序，则意味着尚未整体有序，并需要交换
        {
            last=lo;//若逆序，则更新最右侧逆序对位置记录，并交换
            swap(t[lo - 1], t[lo]);
        }
    return last;
}
template<typename T>
void mergeSort(const T & t,int lo,int hi)
{
    if(hi-lo < 2) return;//单元素区间自然有序，否则
    int mid = (lo+hi)>>1; //以中点为界
    mergeSort(t,lo,mid);//对前半段排序
    mergeSort(t,mid,hi);//对后半段排序
    merge(t,lo,mid,hi);//归并
}
template<typename T>
void merge(const T& t,int lo,int mid,int hi)
{
    //归并
    T * A = t+lo;
    int lb = mid-lo; T* B = new T[lb];//前自向量
    for(int i=0;i<lb;B[i]=A[i++]);//复制前子向量
    int lc = hi-mid; T* C = t+mid;
    for(int i = 0, j=0,k=0;(j<lb)||(k<lc); )
    {
        if((j<lb) && (lc <= k||(B[j] < C[k]))) A[i++]=B[j++];
        if((k<lc) && (lb <= j||(C[k] < B[j]))) A[i++]=C[k++];
    }
    delete [] B;
}
#endif //DATASTRUCTURE_SORT_H
