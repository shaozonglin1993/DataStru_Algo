/*************************************************************************
    > File Name: seqList.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月21日 星期四 15时56分45秒
 ************************************************************************/

#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <memory.h>
#include <assert.h>
#include <stdio.h>

#define  MAX_SIZE 100

typedef int DataType;			 //数据类型重命名
typedef struct SeqList		 //定义结构体类型
{
	DataType array[MAX_SIZE];	 // 数据段
	size_t size;				 // 数据个数
}SeqList;


void InitSeqList(SeqList* pSeq);

void PrintSeqList(SeqList* pSeq);

void PushBack(SeqList* pSeq, DataType x);

void PopBack(SeqList* pSeq);

void PushFront(SeqList* pSeq, DataType x);

void PopFront(SeqList* pSeq);

void Insert(SeqList* pSeq, size_t pos, DataType x);

int Find(SeqList* pSeq, DataType x);

void Erase(SeqList* pSeq, size_t pos);

void Remove(SeqList* pSeq, DataType x);


void RemoveAll(SeqList* pSeq, DataType x);

void BubbleSort(SeqList* pSeq);

void SeclectSort(SeqList* pSeq);

int BinarySearch(SeqList* pSeq, DataType x);

int _BinarySearch_R(SeqList* pSeq, int left, int right, DataType x);


#endif
