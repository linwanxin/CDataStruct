//
// Created by lwx on 2019/3/7.
//
/**顺序队列的实现
 * C中没有引用一说，所以书本上错误的，如果是C只能用指针，因为形参和实参传递值；
 所以为了达到目的，所以我打算采用C++实现，但是还是以C为原型，更加灵活，这样子可以用引用了！
 局限性：必须设置最大队列长度！如果无法估计则采用链队！
 */
#include "SqQueue.h"
bool InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXQIZE];
    if(!Q.base)
        return false;
    Q.front = Q.rear = 0;
    return true;
}
int QueueLength(SqQueue &Q)
{
    return (Q.rear - Q.front + MAXQIZE) %MAXQIZE;
}

bool EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear + 1 ) % MAXQIZE == Q.front)
        return false;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+ 1)%MAXQIZE;
    return true;
}

bool DeQueue(SqQueue &Q,QElemType & e)
{
    if(Q.rear == Q.front)
        return false;

    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXQIZE;
    return true;
}
QElemType GetHead(SqQueue &Q)
{
    if(Q.front != Q.rear)
        return Q.base[Q.front];
}