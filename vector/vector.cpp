/*************************************************************************
  > File Name: vector.cpp
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月20日 星期三 16时15分44秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include "vector.h"

    template<class T>
Vector<T>::Vector()
    :_start(NULL)
    , _finish(NULL)
     , _endOfStorage(NULL)
{}

    template<class T>
void Vector<T>::PushBack(const ValueType& x)
{
    _CheckCapacity();

    *_finish = x;
    _finish++;
}

    template<class T>
void Vector<T>::PopBack()
{
    _finish--;
}

template<class T>
//插入x，在pos前面
void Vector<T>::Insert(Iterator pos, const ValueType& x)
{
    _CheckCapacity();
    assert(pos <= _finish + 1);

    if (pos == _finish + 1 || pos == _finish)
    {
        PushBack(x);
        return;
    }

    Iterator cur = _finish;
    Iterator prev = _finish - 1;
    while (cur != pos)
    {
        *cur-- = *prev--;
    }

    *cur = x;
    _finish++;

}

    template<class T>
void Vector<T>::Erase(Iterator pos)
{
    assert(pos < _finish);

    if (pos == _finish - 1)
    {
        PopBack();
    }

    Iterator cur = _start;
    while (cur != pos)
    {
        cur++;
    }
    Iterator next = cur + 1;
    while (next != _finish)
    {
        *cur++ = *next++;
    }
    --_finish;
}

    template<class T>
typename Vector<T>::Iterator Vector<T>::Begin()
{
    return _start;
}

    template<class T>
typename Vector<T>::Iterator Vector<T>::End()
{
    return _finish;
}

    template<class T>
size_t Vector<T>::Size()
{
    return _finish - _start;
}

    template<class T>
typename Vector<T>::ValueType& Vector<T>::operator[](size_t index)
{
    assert(_start + index < _finish);
    return _start[index];
}

    template<class T>
void Vector<T>::_CheckCapacity()
{
    if (_finish == _endOfStorage)
    {
        size_t oldStorage = _finish - _start;
        size_t newStorage = oldStorage * 2 + 3;

        ValueType* tmp = new ValueType[newStorage];
        for (int i = 0; i < oldStorage; i++)
        {
            tmp[i] = _start[i];
        }
        delete[] _start;
        _start = tmp;
        _finish = _start + oldStorage;
        _endOfStorage = _start + newStorage;
    }
}



void TestVector()
{
    Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);
    //v.PopBack();

    Vector<int>::Iterator it = v.Begin();
    while (it != v.End())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    v.Insert(it, 5);

    it = v.Begin();
    while (it != v.End())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    v.Erase(v.Begin()+2);
    it = v.Begin();
    while (it != v.End())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}
