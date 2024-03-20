/*************************************************************************
    > File Name: bitmap.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月20日 星期三 16时27分56秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include <vector>
#include "bitmap.h"


	BitMap::BitMap()
		:_size(0)
	{}

	BitMap::BitMap(size_t size)
		:_size(0)
	{
		_array.resize((size >> 5) + 1); // size/32 + 1 
	}
	
	bool BitMap::Test(size_t num) //查看次数是否存在
	{
		size_t index = num >> 5;
		size_t n = num % 32;

		return _array[index] & (1 << n);
	}

	void BitMap::Set(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		if (_array[index] & (1 << n)) //该数已经存在
		{
			return;
		}
		_array[index] |= (1 << n);
		_size++;
	}

	void BitMap::ReSet(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		if (!_array[index] & (1 << n))
		{
			return;
		}
		_array[index] &= ~(1 << n);
		++_size;
		return;
	}

	void BitMap::Clear()
	{
		_array.assign(_array.size(), 0);
	}
