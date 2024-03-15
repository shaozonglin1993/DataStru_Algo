#ifndef AVL
#define AVL
#include <iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
    K _key;
    V _value;
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;
    int _bf;				//平衡因子

    AVLTreeNode(const K& key, const V& value)
        : _key(key)
          , _value(value)
          , _left(NULL)
          , _right(NULL)
          , _parent(NULL)
          , _bf(0)
    {}
};

template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
    public:
    AVLTree()
        : _root(NULL)
    {}

    ~AVLTree()
    {}

    public:

    //空树
    //查找位置
    //插入节点
    //更新平衡因子
    //如果进行了旋转调整，则将parent进行重新连接

    bool Insert(const K& key, const V& value);

    void InOrder();

    bool IsBalanceTree();
    protected:

    //8. 二叉树面试题之 判断一棵二叉树是不是平衡二叉树
    bool _IsBalanceTree(Node* root);

    //左单旋
    void _RotateL(Node*& parent);

    void _RotateR(Node*& parent);

    void _RotateLR(Node*& parent);

    void _RotateRL(Node*& parent);


    void _InOrder(Node* root);

    int _Height(Node* root);

protected:
    Node* _root;
};

void TestAVL1();

void TestAVL2();


#endif
