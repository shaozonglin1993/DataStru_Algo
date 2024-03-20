/*************************************************************************
  > File Name: queue.cpp
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月20日 星期三 15时47分36秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include <assert.h>
#include "queue.h"


    template<class T>
Queue<T>::Queue()
    :_head(NULL)
     ,_tail(NULL)
{}

    template<class T>
Queue<T>::~Queue()
{
    QueueNode<T>* cur = _head;

    while (cur)
    {
        cur = cur->_next;
        delete _head;
    }
    _head = _tail = NULL;
}

    template<class T>  
void Queue<T>::Push(const T& x)
{
    if (_head == NULL)
    {
        _tail = _head = new QueueNode<T>(x);
    }
    else
    {
        _tail->_next = new QueueNode<T>(x);
        _tail = _tail->_next;
    }
}

    template<class T> 
void Queue<T>::Pop()
{
    assert(_head);
    if (_head == _tail)
    {
        delete _head;
        _tail = _head = NULL;
        return;
    }

    QueueNode<T>* del = _head;
    _head = _head->_next;
    delete del;
}

template<class T> 
size_t Queue<T>::Size()
{
    size_t count = 0;
    QueueNode<T>* head = _head;

    while(head != NULL)
    {
        count++;
        head = head->_next;
    }

    return count;
}

    template<class T> 
bool Queue<T>::Empty()
{
    return _head == NULL;
}

    template<class T> 
T& Queue<T>::Front()
{
    assert(_head);
    return _head->_data;
}

    template<class T> 
T& Queue<T>::Back()
{
    assert(_tail);
    return _tail->_data;
}


void TestQueue()
{
    Queue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    cout<<"size = "<<q.Size()<<endl;

    while (!q.Empty())
    {
        cout << q.Front() << " ";
        q.Pop();
    }
    cout<<endl;
}

