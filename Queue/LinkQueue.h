//
// Created by lwx on 2019/3/7.
//
#include "QElemType.h"
#ifndef CDATASTRUCT_LINKQUEUE_H
#define CDATASTRUCT_LINKQUEUE_H


typedef struct QNode
{
    QElemType data;
    QNode * next;
}*QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q);

bool EnQueue(LinkQueue &Q,QElemType e);
//再封装一个，使用方可以直接调用
bool EnQueue(LinkQueue &Q,int elem);

bool DeQueue(LinkQueue &Q,QElemType &e);

bool QueueEmpty(LinkQueue &Q);

QElemType GetHead(LinkQueue &Q);
#endif //CDATASTRUCT_LINKQUEUE_H
