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

bool EnQuue(LinkQueue &Q,QElemType e);

bool DeQuue(LinkQueue &Q,QElemType &e);

bool QueueEmpty(LinkQueue &Q);

QElemType GetHead(LinkQueue &Q);
#endif //CDATASTRUCT_LINKQUEUE_H
