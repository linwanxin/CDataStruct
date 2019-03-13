//
// Created by lwx on 2019/3/13.
//
/**
 * 最小生成树算法:
    1.普里姆算法：：整体思想：(加点法)
    随便第一个点u，然后找权值最小的边，然后关联的点加入U中，再找U关联的最小的边，循环知道U=V；
 */

#include "Map.h"
#include <iostream>
using namespace std;
//辅助数组，
typedef  struct
{
    VerTexType adjvex; //最小边在U中的顶点
    ArcType  lowcost;  //最小边的权值
}Closedge[MVNum];

Closedge closedge;
AMGraph G;
//这里以邻接矩阵表示无向网为例子
int Min(Closedge closedge1)
{
    int min = INT32_MAX;
    int index = 0;
    for(int i=0;i<G.vexnum;++i)
    {
        if(closedge1[i].lowcost != 0 && closedge1[i].lowcost < min )
        {
            min = closedge1[i].lowcost;
            index = i;
        }
    }
    return index;
}

void MiniSpanTree_Prim(AMGraph &G,VerTexType u)
{
    //初始化
    int k = LocateVex(G,u);//顶点值在G中顶点数组的下标，也就是在矩阵的下标
    for(int j=0;j<G.vexnum;++j)
        if(j!=k)
            closedge[j] = {u,G.arcs[k][j]};//对应的边开始全部为u

    closedge[k].lowcost = 0; //U={u};
    for(int i=1;i<G.vexnum;++i)
    {
        k = Min(closedge); //从closedge选出最小边，在初始化做好了
        VerTexType u0 = closedge[k].adjvex;//开始v1节点 u0= U;
        VerTexType v0 = G.vexs[k];    //另一个顶点 v0 = V-U；
        cout << u0 << v0 << endl;
        closedge[k].lowcost = 0;
        for(int j=0;j<G.vexnum;++j)
            //这里是更新的closedge的边的值！
            if(G.arcs[k][j] < closedge[j].lowcost)
                closedge[j] = {G.vexs[k],G.arcs[k][j]};
    }
}

/**
 * 2.克鲁斯卡尔算法：（加边法）
 * 从权值最小的边开始往上加，如果加上不行成回路，则可以，也就是不在同一个连通分量上
 */
typedef  struct
{
    VerTexType  Head; //边的始点
    VerTexType  Tail; //边的终点
    ArcType lowcost;  //权值
}Edge[100];  //边数量
//辅助数组
int Vexset[MVNum];

void Sort(Edge &edge)
{

}
//需要增加一个初始化Edge的方法
void InitEdge(AMGraph G,Edge &edge)
{

}

//前提是边数组的信息是初始化好的
void MiniSpanTree_Kruskal(AMGraph G)
{
    Edge edge;
    InitEdge(G,edge);
    Sort(edge);
    for(int i=0;i<G.vexnum;++i)
        Vexset[i] = i;
    for(int i=0;i<G.arcnum;++i)
    {
        int v1 = LocateVex(G,edge[i].Head);
        int v2 = LocateVex(G,edge[i].Tail);
        int vs1 = Vexset[v1];
        int vs2 = Vexset[v2];
        if(vs1 != vs2)
        {
            cout<< edge[i].Head << edge[i].Tail ;
            for(int j=0;j<G.vexnum ;++j)
                if(Vexset[j] == vs2)
                    Vexset[j] == vs1;
        }
    }
}
