#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Less
{
    bool operator() (const T& l, const T& r)
    {
        return l < r;
    }
};

template<class T>
struct Greater
{
    bool operator() (const T & l, const T& r)
    {
        return l > r;
    }
};

template< class T, class Compare = Less<T> >
class Heap
{
public:
        Heap()
        {}

        Heap(const T* a, size_t size);

        void Push(const T& x);

        void Pop();

        T& top();

        bool Empty();

        bool Size();

        void AdjustDown(int root);

        void AdjustUp(int child);

        void Print();
public:
        vector<T> _arrays;
};

void Test1();

#endif
