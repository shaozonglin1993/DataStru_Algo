#ifndef BTREE
#define BTREE

#include <iostream>
using namespace std;

template<class K, int M = 3>
struct BTreeNode
{
    K _keys[M];					// 关键字数组
    BTreeNode<K, M>* _subs[M + 1];	// 孩子数组
    size_t _size;				// 关键字的个数

    BTreeNode<K, M>* _parent;	// 父亲

    BTreeNode()
        :_size(0)
         , _parent(NULL)
    {
        for (size_t i = 0; i < M + 1; ++i)
        {
            _subs[i] = NULL;
        }
    }
};

template<class K, class V>
struct Pair
{
    K _first;
    V _second;

    Pair(const K& k = K(), const V& v = V())
        :_first(k)
         , _second(v)
    {}
};

template<class K, int M = 3>
class BTree
{
public:
    typedef BTreeNode<K, M> Node;

    BTree()
        :_root(NULL)
    {}

    Pair<Node*, int> Find(const K& key);

    bool Insert(const K& key);

    void _InsertKey(Node* cur, const K& k, Node* sub);

    void InOrder();

    void _InOrder(Node* root);
protected:
    Node* _root;
};


void TestBTree1();

#endif
