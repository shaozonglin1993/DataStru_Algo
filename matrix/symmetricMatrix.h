/*************************************************************************
    > File Name: symmetricMatrix.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 17时14分11秒
 ************************************************************************/

#ifndef _SYMMETRICMATRIX_H
#define _SYMMETRICMATRIX_H

#include <iostream>
#include <vector>
using namespace std;

//压缩存储

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t n);

	void Display();

	T& AccessNum(size_t i, size_t j);

	~SymmetricMatrix();



private:
	T* _array;		//对称矩阵的压缩存储的一维数据
	size_t _n;		//对称矩阵的行列数
};

void Test1();



#endif
