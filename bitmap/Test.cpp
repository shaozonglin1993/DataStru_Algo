/*************************************************************************
    > File Name: Test.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月20日 星期三 16时28分00秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include "bitmap.h"

void test()
{
	BitMap bm1(100);
	bm1.Set(1);
	bm1.Set(33);
	bm1.Set(69);
	bm1.Set(100);

	bm1.ReSet(33);

    cout<<"100 is in bitmap ?"<<(bm1.Test(100) == 1 ? "true" : "false")<<endl;
}
int main()
{
	test();

	return 0;
}
