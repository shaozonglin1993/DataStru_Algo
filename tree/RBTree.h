#ifndef RBTREE
#define RBTREE

#include <iostream>
using namespace std;

enum Color{ RED, BLACK };

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode(const K& key, const V& v, Color col = RED)
	:_left(NULL)
	, _right(NULL)
	, _parent(NULL)
	, _key(key)
	, _vlaue(v)
	, _col(col)
	{}
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	K _key;
	V _vlaue;
	Color _col;
};
template<class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;
	RBTree()
		:_root(NULL)
	{}
	
	bool Insert(const K& key, const V& v);

	bool IsBalanceTree();
	
	void InOrder();
	
	int _Height(Node* root);
	
	bool _IsBalance(Node* root);
	
	void _RotateL(Node* parent);
	
	void _RotateR(Node* parent);
	
	void _InOrder(Node*& root);

protected:
	Node* _root;
};

void TestRBTree1();


#endif
