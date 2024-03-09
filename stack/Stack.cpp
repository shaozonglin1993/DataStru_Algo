/*************************************************************************
    > File Name: Stack.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: Sat 09 Mar 2024 08:44:40 AM EST
 ************************************************************************/

#include <iostream>
#include <assert.h>
#include <string.h>
#include "Stack.h"
#include "TypeTraits.h"

using namespace std;

template<class T>
void Stack<T>::Push(const T& x)
{
	_CheckCapacity();

	_array[_size++] = x;
}

template<class T>
void Stack<T>::Pop()
{
	assert(_size > 0);
	--_size;
}

template<class T>
size_t Stack<T>::Size()
{
	return _size;
}

template<class T>
bool Stack<T>::Empty()
{
	return _size == 0;
}

template<class T>
const T& Stack<T>::Top()
{
	assert(_size > 0);
	return _array[_size - 1];
}

template<class T>
void Stack<T>::_CheckCapacity()
{
	if (_size >= _capacity)
	{
		_capacity = _capacity * 2 + 3;
		T* tmp = new T[_capacity];
		//Ê¶±ðTÊÇÊ²Ã´ÀàÐÍ -->ÀàÐÍÝÍÈ¡ -->ÌØ»¯
		if (typename TypeTraits<T>::__IsPODType().Get())
		{
			cout << "POD" << endl;
			memcpy(tmp, _array, sizeof(T)*_size);
		}
		else
		{
			cout << "NON_POD" << endl;
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = _array[i];
			}
		}

		delete[] _array;
		_array = tmp;

	}
}

void Test1()
{
	Stack<char> s1;
	s1.Push('a');
	s1.Push('b');
	s1.Push('c');
	s1.Push('d');

	while (!s1.Empty())
	{
		cout << s1.Top() << " ";
		s1.Pop();
	}
	cout << endl;

	Stack<string> s2;
	s2.Push("ssssss");
	s2.Push("ssssss");
	s2.Push("ssssss");
	s2.Push("ssssss");
	s2.Push("ssssss");
	s2.Push("ssssss");

	while (!s1.Empty())
	{
		cout << s1.Top() << " ";
		s1.Pop();
	}

	cout << endl;

}

