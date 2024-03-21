/*************************************************************************
    > File Name: Test.cpp
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 15时08分16秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;


#include <stdio.h>
#include <stdlib.h>
#include "forwardList.h"

int main()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	int i = 0;
	while (i < 10)
	{
	//	PushBack(&head, i);
	//	PushHead(&head, i);
	//	PushHead(&head, i);
	//	PopBack(&head);
	//	PopFront(&head);
	//	ShowList(head);
		PushBack(&head1, i);
		PushBack(&head2, i+9);
		i++;
	}
//	printf("%u\n", Find(&head, 2));
//	Insert(Find(&head, 2), 10);
//	Erase(&head, Find(&head, 5));
//	DelNonTailNode(Find(&head, 5));
//	Remove(&head, 5);
//	ShowList(Reverse(head));
//	PrintTailtoHead(head);
//	printf("%p\n", FindMid(head));
//	InsertFrontNode(Find(&head, 5), 10);
//	printf("%d\n", Find_TheLast_Knode(head, 0));
//	BubbleSort(&head);
//	ShowList(head);
	ShowList(head1);
	ShowList(head2);
	ListNode* ret = Merge_List(head1, head2);
	ShowList(ret);
	ShowList(head1);
//	ShowList(head2);
//	printf("%d\n", p->data);
//	printf("list Clycle is %d\n", IsLoop(head2));
//	printf("%d\n", GetLength(head1));
//	ListNode* ret = CreatCycle(head1, 6);
//	ListNode* enterNode = GetEnterNode(ret);
	//if (enterNode != NULL)
	//{
	//	printf("enterNode is : %d\n", enterNode->data);
	//}

	return 0;
}