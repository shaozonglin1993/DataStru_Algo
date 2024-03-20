/*************************************************************************
    > File Name: bitmap.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月20日 星期三 16时27分53秒
 ************************************************************************/

#ifndef _BITMAP_H
#define _BITMAP_H

#pragma once
#include <iostream>
using namespace std;
#include <vector>

class BitMap
{
public:
	BitMap();

	BitMap(size_t size);
	
	bool Test(size_t num); //查看次数是否存在

	void Set(size_t num);

	void ReSet(size_t num);

	void Clear();

protected:
	vector<size_t> _array;
	size_t _size;
};

#endif
