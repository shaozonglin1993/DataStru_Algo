/*************************************************************************
    > File Name: sort.h
    > Author: szl
    > Mail: shaozonglin321@163.com
    > Created Time: 2024年03月19日 星期二 15时18分12秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H

void Print(int *a, size_t);
void Insert_Sort(int* a, size_t size);
void Shell_Sort(int* a, size_t size);
void AdjustDown(int* a, size_t size, int root);
void AdjustUp(int* a, size_t size, int root);
void Heap_Sort(int* a, size_t size);
void _Heap_Sort(int* a, size_t size);
void BubbleSort(int* a, size_t size);
int Partition1(int *a, int left, int right);
void QuickSort1(int *a, int left, int right);
int Partition2(int *a, int left, int right);
void QuickSort2(int *a, int left, int right);
int Partition3(int* a, size_t left, size_t right);
void QuickSort3(int *a, int left, int right);
int GetMidIndex(int* a, size_t left, size_t right);
void QuickSort4(int* a, size_t left, size_t right);
void SelectSort(int* a, size_t size);
void MergeSection(int* a, int* tmp, size_t left, size_t mid, size_t right);
void _MergeSort(int* a, int* tmp, size_t left, size_t right);
bool MergeSort(int* a, size_t size);
void CountSort(int* a, size_t size);
int GetMaxDigit(int* a, size_t size);
void DigitSort(int* a, size_t size);
void TestInsertSort();
void TestShell_Sort();
void TestHeap_Sort_down();
void TestHeap_Sort_up();
void TestQuickSort1();
void TestQuickSort2();
void TestQuickSort3();
void TestQuickSort4();
void TestSelectSort();
void TestMergeSort();
void TestCountSort();
void TestBubbleSort();
void TestDigitSort();
#endif
