#include "Heap.h"


    template< class T, class Compare>
Heap<T, Compare>::Heap(const T* a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        _arrays.push_back(a[i]);
    }

    //建堆
    for (int i = (_arrays.size() - 2) / 2; i >= 0; i--)
    {
        AdjustDown(i);
    }
}
    template< class T, class Compare>
void Heap<T, Compare>::Push(const T& x)
{
    _arrays.push_back(x);
    AdjustUp(_arrays.size() - 1); 
}
    template< class T, class Compare>
void Heap<T, Compare>::Pop()
{
    assert(_arrays.size() > 0);

    swap(_arrays[0], _arrays[_arrays.size() - 1]);
    _arrays.pop_back();

    AdjustUp(0);
}
    template< class T, class Compare>
T& Heap<T, Compare>::top()
{
    assert(_arrays.size() > 0);
    return _arrays[0];
}
    template< class T, class Compare>
bool Heap<T, Compare>::Empty()
{
    return _arrays.empty();
}
    template< class T, class Compare>
bool Heap<T, Compare>::Size()
{
    return _arrays.size();
}
    template< class T, class Compare>
void Heap<T, Compare>::AdjustDown(int root)
{
    int child = root * 2 + 1;

    Compare com;
    while (child < _arrays.size())
    {
        //if (child + 1 < _arrays.size() && (_arrays[child + 1] > _arrays[child]));
        if (child + 1<_arrays.size() && com(_arrays[child + 1], _arrays[child]))
        {
            child++;
        }

        //if (_arrays.[child] < _arrays[root])
        if (com(_arrays[child], _arrays[root]))
        {
            cout<<"swap "<<_arrays[child]<<" "<<_arrays[root]<<endl;
            swap(_arrays[child], _arrays[root]);
            root = child;
            child = 2 * root + 1;
        }

        else
        {
            break;
        }
    }
}
    template< class T, class Compare>
void Heap<T, Compare>::AdjustUp(int child)
{
    int parent = (child - 1) / 2;

    while (child > 0)
    {
        //if (_arrays[child] > _arrays[parent])
        if (Compare()(_arrays[child], _arrays[parent]))
        {
            swap(_arrays[child], _arrays[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }

        else
        {
            break;
        }
    }
}
    template< class T, class Compare>
void Heap<T, Compare>::Print()
{
    for (size_t i = 0; i < _arrays.size(); i++)
    {
        cout << _arrays[i] << " ";
    }
    cout << endl;
}

void Test1()
{
    //int arr[10] = { 1, 2, 3, 8, 9, 0, 4, 5, 6, 7 };

    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    Heap< int, Greater<int> > hp1 (arr, 10);
    //hp1.Push(10);

    hp1.Print();
}
