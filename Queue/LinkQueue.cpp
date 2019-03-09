//
// Created by lwx on 2019/3/7.
//

#include "LinkQueue.h"

bool InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = nullptr;
    return true;
}

bool EnQuue(LinkQueue &Q,QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = nullptr;
    //
    Q.rear->next = p;
    //
    Q.rear = p;
    return true;

}

bool DeQuue(LinkQueue &Q,QElemType &e)
{
    if(Q.front == Q.rear)
        return false;
    //增加头节点的原因
    QNode * p = Q.front->next;

    e = p->data;
    Q.front->next = p->next;
    //如果为最后一个！则修改尾指向，为空使用！
    if(Q.rear == p)
        Q.rear = Q.front;
    delete  p;
    return true;
}
QElemType GetHead(LinkQueue &Q)
{
    if(Q.front !=Q.rear)
        return Q.front->next->data;
}
bool QueueEmpty(LinkQueue &Q)
{
    //判空的条件！
    if(Q.front == Q.rear)
        return true;
    return false;
}