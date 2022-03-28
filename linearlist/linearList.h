//
// Created by admin on 2022/3/24.
//

#ifndef DATASTRUCTURE_LINEARLIST_H
#define DATASTRUCTURE_LINEARLIST_H

#include "ostream"
#include "sstream"
#include <exception>
#include <iterator>
#include <algorithm>
#include "changeLength1D.h"
#include "../MyExceptions.h"
namespace repetition {
    template<class T>
    class linearlist
    {
    private:
        /* data */
    public:
        linearlist(/* args */);
        ~linearlist();
        virtual bool empty() ;
        virtual int size();
        virtual T& get(int theIndex);
        virtual int indexOf(const T& theElement);
        virtual void erase(int theIndex);
        virtual void insert(int theIndex, const T& theElement);
        virtual void output(std::ostream& out);
    };
}
#endif //DATASTRUCTURE_LINEARLIST_H
