/*************************************************************************
    > File Name: forwardList.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 15时08分07秒
 ************************************************************************/

#ifndef _FORWARDLIST_H
#define _FORWARDLIST_H


#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;			//数据类型重命名

typedef struct _node			//定义节点结构体
{
	DataType data;			//数据
	struct _node* next;		//指向下一个节点的指针
}ListNode;

void InitList(ListNode** head);

ListNode* CreatNode(DataType val);

void PushBack(ListNode** head, DataType x);

void ShowList(ListNode* head);

void PushHead(ListNode** head, DataType x);

void PopBack(ListNode** head);

void PopFront(ListNode** head);

ListNode* Find(ListNode** head, DataType x);

void Insert(ListNode* pos, DataType x);

void InsertFrontNode(ListNode* pos, DataType x);

void Erase(ListNode** head, ListNode* pos);

void DelNonTailNode(ListNode* pos);

void Remove(ListNode** head, DataType x);

ListNode* Reverse(ListNode* head);

void PrintTailtoHead(ListNode* head);

ListNode* FindMid(ListNode* head);

DataType Find_TheLast_Knode(ListNode* head, int k);

void swap(DataType* n, DataType* m);

void BubbleSort(ListNode** head);

ListNode* Merge_List(ListNode* l1, ListNode* l2);

ListNode* Joseph_Cycle(ListNode* head,int k);

ListNode* CreatCycle(ListNode* phead,int k);

int IsLoop(ListNode* phead);

ListNode* MeetNode(ListNode* phead);

int GetLength(ListNode* phead);

ListNode* GetEnterNode(ListNode* phead);


#endif
