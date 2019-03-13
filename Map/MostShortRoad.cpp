//
// Created by lwx on 2019/3/13.
//
#include "Map.h"

void ShortestPath_DIJ(AMGraph G,int v0)
{
    int n = G.vexnum;
    bool S[n];  //记录是否是确定的最短路径
    int Path[n]; //记录直接前驱
    int D[n];   //记录最短路径
    for(int v=0;v <n;v++)
    {
        S[v] = false; //初始化为空
        D[v] = G.arcs[v0][v]; //v0初始化为到各个终点的最短路径长度初始化为权值
        if(D[v] < MaxInt)
            Path[v] = v0;
        else
            Path[v] = -1;

    }
    S[v0] = true;
    D[v0] = 0;
    //-----------初始化结束，每次求得v0到某个顶点V的最短路径，将v加入到S中--------
    int v;
    for(int i=1;i<n;i++)
    {
        int min = MaxInt;
        for(int w = 0;w< n;w++)
        {
            if(!S[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        }
        S[v] = true;  //求出最短的一条的路径，终点为v，加入S中！
        for(int w =0;w<n;w++)  //更新从v0出发到V-S的所有顶点的最短路径，(因为增加了中转节点w，所以对)
        {
            if(!S[w] && D[v]+G.arcs[v][w] < D[w])
            {
                D[w] = D[v] +G.arcs[v][w];
                Path[w] = v;
            }
        }
    }

}
