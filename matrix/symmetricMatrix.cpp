/*************************************************************************
    > File Name: symmetricMatrix.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 17时14分14秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include <vector>
#include <assert.h>
#include "symmetricMatrix.h"

using namespace std;

//压缩存储

template<class T>
	SymmetricMatrix<T>::SymmetricMatrix(T* a, size_t n)
		:_array(new T[n*(n + 1) / 2])
		, _n(n)
	{
		size_t index = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (i >= j)
				{
					_array[index++] = a[i*n + j];
				}
				else
				{
					break;
				}
			}
		}
	}

template<class T>
	void SymmetricMatrix<T>::Display()
	{
		for (size_t i = 0; i < _n; ++i)
		{
			for (size_t j = 0; j < _n; ++j)
			{
				if (i >= j)
				{
					cout << _array[i*(i + 1) / 2 + j] << " ";
				}
				else
				{
					cout << _array[j*(j + 1) / 2 + i] << " ";
				}
			}

			cout << endl;
		}

		cout << endl;
	}

template<class T>
	T& SymmetricMatrix<T>::AccessNum(size_t i, size_t j)
	{
		assert(i < _n == true);
		assert(j < _n == true);
		if (i < j)
		{
			swap(i, j);
		}
		return _array[i*(i + 1) / 2 + j];
	}

template<class T>
	SymmetricMatrix<T>::~SymmetricMatrix()
	{
		if (_array)
		{
			delete[] _array;
		}
	}

void Test1()
{
	int a[5][5] =
	{
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 },
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 },
	};

	SymmetricMatrix<int>sm((int*)a, 5);
	sm.Display();
}

