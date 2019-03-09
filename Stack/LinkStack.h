//
// Created by lwx on 2019/3/7.
//
/**
 * 链栈的实现
 */
#ifndef CDATASTRUCT_LINKSTACK_H
#define CDATASTRUCT_LINKSTACK_H

#include "ElemType.h"

typedef struct StackNode
{
    ElemType data;
    StackNode * next;
}*LinkStack;

bool InitStack(LinkStack &S);
bool Push(LinkStack &S,ElemType e);
bool Pop(LinkStack &S,ElemType &e);
ElemType GetTop(LinkStack &S);
void TraverseList(LinkStack &p);
bool StackEmpty(LinkStack &S);


#endif //CDATASTRUCT_LINKSTACK_H
