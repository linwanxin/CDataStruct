//
// Created by lwx on 2019/3/7.
//

#include "LinkStack.h"
#include <iostream>
using namespace std;
bool InitStack(LinkStack &S)
{
    S= nullptr;
    return true;
}

bool Push(LinkStack &S,ElemType e)
{
    StackNode * p = new StackNode;
    p->data = e;
    //接入尾部,这里是倒插法！
    p->next = S;
    //S始终指向栈顶！
    S = p;
    return true;
}
bool Pop(LinkStack &S,ElemType &e)
{
    if(S == nullptr)
        return false;

    e = S->data;
    StackNode * p = S;
    S = S->next;
    delete p;
    return true;
}

ElemType GetTop(LinkStack &S)
{
    if(S!= nullptr)
        return S->data;
}

//利用递归遍历输出栈
void TraverseList(LinkStack &p)
{
    if(p == nullptr)
        return;
    else
    {
        p->data.print();
        TraverseList(p->next);
    }
}
bool StackEmpty(LinkStack &S)
{
    if(S == nullptr)
        return true;
    return false;
}