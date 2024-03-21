/*************************************************************************
  > File Name: generalizedList.cpp
  > Author: szl
  > Mail: shaozonglin321@163.com
  > Created Time: 2024年03月21日 星期四 16时23分16秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

#include "generalizedList.h"


struct GeneralListNode
{
    Type _type;
    GeneralListNode* _next;

    union{
        char _value;
        GeneralListNode* _subLink;
    };

    GeneralListNode(Type type = VALUE, char value = 0)
        :_type(type)
         ,_next(NULL)
    {
        if (_type == VALUE)
        {
            _value = value;
        }
        else if (_type = SUB)
        {
            _subLink = NULL;
        }
    }
};

GeneralList::GeneralList()
    :_head(NULL)
{}

GeneralList::GeneralList(char* s)
    :_head(NULL)
{
    _head = _CreateGeneralList(s);
}

GeneralList::~GeneralList()
{
    _Destroy(_head);
}

GeneralList::GeneralList(const GeneralList& g)
{
    _head = _Copy(g._head);
}

GeneralList& GeneralList::operator=(GeneralList g)
{
    swap(_head, g._head);
    return *this;
}

size_t GeneralList::Size()
{
    return _Size(_head);
}

void GeneralList::Print()
{
    _Print(_head);
    cout << endl;
}

size_t GeneralList::Depth()
{
    return _Depth(_head);
}

GeneralListNode* GeneralList::_Copy(GeneralListNode* head)
{
    assert(head);
    GeneralListNode* cur = head->_next;

    GeneralListNode* newhead = new GeneralListNode(HEAD);
    GeneralListNode* newCur = newhead;

    while (cur)
    {
        if (cur->_type == VALUE)
        {
            newCur->_next = new GeneralListNode(VALUE, cur->_value);
            newCur = newCur->_next;
        }
        else if (cur->_type == SUB)
        {
            newCur->_next = new GeneralListNode(SUB);
            newCur = newCur->_next;
            newCur->_subLink = _Copy(cur->_subLink);
        }
        cur = cur->_next;
    }

    return newhead;
}

void GeneralList::_Destroy(GeneralListNode* head)
{
    GeneralListNode* cur = head;
    while (cur)
    {
        GeneralListNode* del = cur;
        cur = cur->_next;

        if (del->_type == SUB)
        {
            _Destroy(del->_subLink);
        }

        delete del;
    }
}

void GeneralList::_Print(GeneralListNode* head)
{
    GeneralListNode* cur = head;
    while (cur)
    {
        if (cur->_type == HEAD)
        {
            cout << "(";
        }
        else if (cur->_type == VALUE)
        {
            cout << cur->_value;
            if (cur->_next)
            {
                cout << ",";
            }
        }
        else
        {
            _Print(cur->_subLink);
            if (cur->_next)
            {
                cout << ",";
            }
        }
        cur = cur->_next;
    }

    cout << ")";
}

size_t GeneralList::_Depth(GeneralListNode* head)
{
    size_t depth = 1;
    GeneralListNode* cur = head;

    while (cur)
    {
        if (cur->_type == SUB)
        {
            size_t subDepth = _Depth(cur->_subLink);
            if (subDepth + 1 > depth)
            {
                depth = subDepth + 1;
            }
        }
        cur = cur->_next;
    }
    return depth;
}

size_t GeneralList::_Size(GeneralListNode* head)
{
    GeneralListNode* cur = head;
    size_t size = 0;
    while (cur)
    {
        if (cur->_type == VALUE)
        {
            ++size;
        }
        else if (cur->_type == SUB)
        {
            size += _Size(cur->_subLink);
        }

        cur = cur->_next;
    }

    return size;
}

bool GeneralList::IsValue(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    return false;
}

GeneralListNode* GeneralList::_CreateGeneralList(char*& s)
{
    assert(*s == '(');
    GeneralListNode* head = new GeneralListNode(HEAD);
    ++s;
    GeneralListNode* cur = head;

    while (*s)
    {
        if (*s == '(')
        {
            GeneralListNode* subNode = new GeneralListNode(SUB);
            cur->_next = subNode;
            cur = cur->_next;

            subNode->_subLink = _CreateGeneralList(s);
        }
        else if (*s == ')')
        {
            ++s;
            break;
        }
        else if (IsValue(*s))
        {
            GeneralListNode* valueNode = new GeneralListNode(VALUE, *s);
            cur->_next = valueNode;
            cur = cur->_next;
            ++s;
        }
        else
        {
            ++s;
        }
    }
    return head;
}


void Test1()
{
    GeneralList g1(const_cast<char*>("()"));
    GeneralList g2(const_cast<char*>("(a,b)"));
    GeneralList g3(const_cast<char*>("(a,b,(c,d))"));
    GeneralList g4(const_cast<char*>("(a,b,(c,d),(e,(f),h))"));
    GeneralList g5;
    g5 = g4;
    g4.Print();
    cout << "Depth:" << g4.Depth() << endl;
    cout << "Size:" << g4.Size() << endl;

    g5.Print();
}
