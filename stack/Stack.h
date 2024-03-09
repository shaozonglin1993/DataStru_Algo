/*************************************************************************
    > File Name: Stack.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: Sat 09 Mar 2024 08:44:40 AM EST
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>

template<class T>
class Stack
{
public:
	Stack()
		:_array(NULL)
		, _capacity(0)
		, _size(0)
	{}

	~Stack()
	{
		if (_array)
		{
			delete[]_array;
		}
	}

	Stack(const Stack<T>& s){};
	Stack<T>& operator= (const Stack<T>& s){};
public:

public:
	void Push(const T& x);

	void Pop();

	size_t Size();

	bool Empty();


	const T& Top();

protected:
	void _CheckCapacity();

	T* _array;
	size_t _size;
	size_t _capacity;

};
void Test1();
#endif
