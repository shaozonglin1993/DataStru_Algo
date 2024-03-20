/*************************************************************************
  > File Name: queue.h
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月20日 星期三 15时47分29秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

template<class T>
struct QueueNode
{
    T _data;
    QueueNode<T>* _next;

    QueueNode(const T& x)
        :_data(x)
         ,_next(NULL)
    {}
};

template<class T>
class Queue
{
public:
    Queue();

    ~Queue();

    void Push(const T& x);
    void Pop();
    size_t Size();
    bool Empty();
    T& Front();
    T& Back();

protected:
    QueueNode<T>* _head;
    QueueNode<T>* _tail;
};


void TestQueue();

#endif
