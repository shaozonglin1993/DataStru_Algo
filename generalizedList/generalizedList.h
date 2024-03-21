/*************************************************************************
    > File Name: generalizedList.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 16时23分12秒
 ************************************************************************/

#ifndef _GENERALIZEDLIST_H
#define _GENERALIZEDLIST_H

#include <iostream>
#include <assert.h>
using namespace std;

enum Type
{
	HEAD,
	VALUE,
	SUB,
};

struct GeneralListNode;

class GeneralList
{
public:
	GeneralList();

	GeneralList(char* s);

	~GeneralList();

	GeneralList(const GeneralList& g);
	
	GeneralList& operator=(GeneralList g);

	size_t Size();
	
	void Print();

	size_t Depth();

protected:

	GeneralListNode* _Copy(GeneralListNode* head);
	
	void _Destroy(GeneralListNode* head);
	
	void _Print(GeneralListNode* head);

	size_t _Depth(GeneralListNode* head);

	size_t _Size(GeneralListNode* head);

	bool IsValue(char ch);

	GeneralListNode* _CreateGeneralList(char*& s);

protected:
	GeneralListNode* _head;
};

void Test1();

#endif
