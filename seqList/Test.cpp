/*************************************************************************
    > File Name: Test.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 15时56分53秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include "seqList.h"

int main()
{
	SeqList list;
	SeqList* p = &list;
	size_t i = 0;
	InitSeqList(&list);
	for (i = 0; i < 10; i++)
	{
		p->array[i] = i;
		p->size++;
	}
	/*p->array[10] = 3;
	p->array[11] = 10;
	p->size += 2;
	PrintSeqList(&list);*/
//	PushBack(&list, 10);
//	PopBack(&list);
//	PushFront(&list, 10);
//	PopFront(&list);
//	Insert(&list, 5, 10);
//	printf("%d\n", Find(&list, 9));
//	Erase(&list, 5);
//	Remove(&list, 2);
//	RemoveAll(&list, 3);
	BubbleSort(&list);
	PrintSeqList(&list);
//	printf("%d\n", BinarySearch(&list, 1));
	printf("%d\n", _BinarySearch_R(&list, 0, p->size, 7));
	PrintSeqList(&list);

    Insert(&list, 4, 12);
    Insert(&list, 7, 19);
    PrintSeqList(&list);
    SeclectSort(&list);
    PrintSeqList(&list);


	return 0;
}
