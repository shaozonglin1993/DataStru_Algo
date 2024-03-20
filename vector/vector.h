/*************************************************************************
  > File Name: vector.h
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月20日 星期三 16时15分40秒
 ************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include<assert.h>

template<class T>
class Vector
{
    typedef T ValueType;			
public:
    typedef ValueType* Iterator;
    typedef const ValueType* ConstIterator;

    Vector();

    void PushBack(const ValueType& x);

    void PopBack();

    //插入x，在pos前面
    void Insert(Iterator pos, const ValueType& x);

    void Erase(Iterator pos);

    Iterator Begin();

    Iterator End();

    size_t Size();

    ValueType& operator[](size_t index);

protected:
    void _CheckCapacity();
    Iterator _start;			//目前使用空间的头
    Iterator _finish;			//目前使用空间的尾
    Iterator _endOfStorage;	//目前可用空间的尾
};


void TestVector();

#endif
