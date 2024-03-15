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
    int _bf;				//ƽ������

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

    //����
    //����λ��
    //����ڵ�
    //����ƽ������
    //�����������ת��������parent������������

    bool Insert(const K& key, const V& value);

    void InOrder();

    bool IsBalanceTree();
    protected:

    //8. ������������֮ �ж�һ�ö������ǲ���ƽ�������
    bool _IsBalanceTree(Node* root);

    //����
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
