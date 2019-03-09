//
// Created by lwx on 2019/3/7.
//
/**
 * 舞伴问题：2个链队
 */
#include "../Queue/LinkQueue.h"
#include <iostream>
#include <cstring>
using namespace std;
LinkQueue Mdancers,Fdancers;

void DancePartner(QElemType dancer[],int num)
{
    InitQueue(Mdancers);
    InitQueue(Fdancers);
    for(int i =0;i<num;i++)
    {
        if(dancer[i].sex == 'F')
            EnQuue(Fdancers,dancer[i]);
        else
            EnQuue(Mdancers,dancer[i]);
    }
    QElemType p;
    while(!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
    {
        DeQuue(Fdancers,p);
        cout<< p.name<< " ";
        DeQuue(Mdancers,p);
        cout<<p.name<< " "<< endl;
    }
    if(!QueueEmpty(Fdancers))
    {
        p = GetHead(Fdancers);
        cout<< "第一个获得陪伴的女士是："<< p.name<< endl;
    }
    else if(!QueueEmpty(Mdancers))
    {
        p = GetHead(Fdancers);
        cout<< "第一个获得陪伴的男士是："<< p.name<< endl;
    }
    return ;
}

/*
int main()
{
    //char的初始化问题！
    int num = 4;
    QElemType p1 ={"yulenka",'F'};
    QElemType p2 ={"lwx",'M'};
    QElemType p3 ={"zhang",'M'};
    QElemType p4 ={"wang",'M'};

    QElemType dancer[num] = {p1,p2,p3,p4};
    DancePartner(dancer,num);
    return 0;
}
*/


