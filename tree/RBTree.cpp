
#include "RBTree.h"

    template<class K, class V>
bool RBTree<K, V>::Insert(const K& key, const V& v)
{
    if (_root == NULL)
    {
        _root = new Node(key, v, BLACK);
        return true;
    }
    Node* parent = NULL;
    Node* cur = _root;
    while (cur)
    {
        if (key < cur->_key)
        {
            parent = cur;
            cur = cur->_left;
        }
        else if (key > cur->_key)
        {
            parent = cur;
            cur = cur->_right;
        }
        else
        {
            return false;
        }
    }
    cur = new Node(key, v, RED);
    if (key < parent->_key)
    {
        parent->_left = cur;
        cur->_parent = parent;
    }
    else
    {
        parent->_right = cur;
        cur->_parent = parent;
    }
    //调色
    while (cur != _root && parent->_col == RED)
    {
        Node* GrandParent = parent->_parent;
        if (parent == GrandParent->_left)//往左子树插
        {
            Node* uncle = GrandParent->_right;
            if (uncle && uncle->_col == RED)
            {
                uncle->_col = parent->_col = BLACK;
                GrandParent->_col = RED;

                cur = GrandParent;
                parent = cur->_parent;
            }
            else
            {
                if (cur == parent->_right)
                {
                    _RotateL(parent);
                    swap(cur, parent);
                }
                _RotateR(GrandParent);
                parent->_col = BLACK;
                GrandParent->_col = RED;
            }
        }
        else//往右子树插
        {
            Node*uncle = GrandParent->_left;
            if (uncle && uncle->_col == RED)
            {
                uncle->_col = parent->_col = BLACK;
                GrandParent->_col = RED;

                cur = GrandParent;
                parent = cur->_parent;
            }
            else
            {
                if (cur == parent->_left)
                {
                    _RotateR(parent);
                    swap(cur, parent);
                }
                _RotateL(GrandParent);

                parent->_col = BLACK;
                GrandParent->_col = RED;
            }

        }
    }
    _root->_col = BLACK;
    return true;
}

    template<class K, class V>
bool RBTree<K, V>::IsBalanceTree()
{
    return _IsBalance(_root);
}

    template<class K, class V>
void RBTree<K, V>::InOrder()
{
    _InOrder(_root);
    cout << endl;
}

    template<class K, class V>
int RBTree<K, V>::_Height(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = _Height(root->_left) + 1;
    int right = _Height(root->_right) + 1;

    return (left > right) ? left : right;
}

    template<class K, class V>
bool RBTree<K, V>::_IsBalance(Node* root)
{
    if (root == NULL)
    {
        return true;
    }
    int left = _Height(root->_left);
    int right = _Height(root->_right);

    int bf = abs(left - right);
    if (bf > 1)
    {
        return false;
    }

    return _IsBalance(root->_left) && _IsBalance(root->_right);
}

    template<class K, class V>
void RBTree<K, V>::_RotateL(Node* parent)
{
    Node *subR = parent->_right;
    Node *subRL = subR->_left;
    parent->_right = subRL;
    if (subRL)
    {
        subRL->_parent = parent;

    }
    subR->_left = parent;
    subR->_parent = parent->_parent;
    parent->_parent = subR;
    parent = subR;
    //连爸爸:)
    if (parent->_parent == NULL)
    {
        _root = parent;
    }
    else
    {
        if (parent->_parent->_key < parent->_key)
        {
            parent->_parent->_right = parent;
        }
        else
        {
            parent->_parent->_left = parent;
        }
    }
}

    template<class K, class V>
void RBTree<K, V>::_RotateR(Node* parent)
{
    Node *subL = parent->_left;
    Node *subLR = subL->_right;
    parent->_left = subLR;
    if (subLR != NULL)
    {
        subLR->_parent = parent;
    }
    subL->_right = parent;
    subL->_parent = parent->_parent;
    parent->_parent = subL;
    parent = subL;
    if (parent->_parent == NULL)
    {
        _root = parent;
    }
    else
    {
        if (parent->_parent->_key < parent->_key)
        {
            parent->_parent->_right = parent;
        }
        else
        {
            parent->_parent->_left = parent;
        }
    }
}

    template<class K, class V>
void RBTree<K, V>::_InOrder(Node*& root)
{
    if (root == NULL)
    {
        return;
    }
    _InOrder(root->_left);
    cout << root->_key << " ";
    _InOrder(root->_right);
}


void TestRBTree1()
{
    RBTree<int, int> t1;

    int a[10] = { 5, 2, 9, 6, 7, 3, 4, 0, 1, 8 };
    for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        t1.Insert(a[i], i);
        t1.InOrder();
    }
    cout << "IsBalanceTree ? "<< t1.IsBalanceTree() << endl;
}
