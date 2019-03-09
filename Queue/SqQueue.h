//
// Created by lwx on 2019/3/7.
//

#define MAXQIZE 100
#define ERROR 0
#define OK 1
//状态修饰返回值
typedef int Status;

typedef struct
{
    int elem;
}QElemType;

typedef struct
{
    QElemType * base;
    int front;
    int rear;
}SqQueue;

bool  InitQueue(SqQueue &Q);

int QueueLength(SqQueue &Q);

bool EnQueue(SqQueue &Q,QElemType e);

bool DeQueue(SqQueue &Q,QElemType & e);

QElemType GetHead(SqQueue &Q);