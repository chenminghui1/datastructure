//
// Created by admin on 2022/3/24.
//

#ifndef DATASTRUCTURE_LINEARLIST_H
#define DATASTRUCTURE_LINEARLIST_H

#include "ostream"
namespace repetition {
    template<class T>
    class linearlist
    {
    private:
        /* data */
    public:
        linearlist(/* args */);
        ~linearlist();
        bool empty() ;
        int size();
        T& get(int theIndex);
        int indexOf(const T& theElement);
        void erase(int theIndex);
        void insert(int theIndex, const T& theElement);
        void output(std::ostream& out);
    };
}
#endif //DATASTRUCTURE_LINEARLIST_H
