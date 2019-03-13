//
// Created by lwx on 2019/3/11.
//
#include "Map.h"
#include "../Queue/LinkQueue.h"
#include <iostream>

using namespace std;
//顶点在图中的位置：顶点依次输入到数组：5，3，4，2
int LocateVex(AMGraph &G,int v)
{
    for(int i=0;i<G.vexnum;++i)
    {
        if(G.vexs[i] == v)
            return i;
    }
}
//邻接矩阵法创建无向网
bool CreateUDN(AMGraph &G)
{
    int v1,v2;  //2边关系
    int w;      //w权重
    int i,j;      //
    cin >> G.vexnum >> G.arcnum;
    for(int i=0;i<G.vexnum;i++)
        cin >> G.vexs[i];
    for(int i=0;i<G.vexnum;++i)         //初始化为最大值
        for(int j=0;j<G.vexnum;++j)
            G.arcs[i][j] = MaxInt;

    for(int k =0;k<G.arcnum;k++)
    {
        cin >> v1 >> v2 >> w ;
        i = LocateVex(G,v1);j = LocateVex(G,v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return true;
}
//邻接表的定位顶点所在的坐标！
int LocateVex1(ALGraph &G,char v)
{
    for(int i=0;i<G.vexnum;++i)
    {
        if(G.vertices[i].data == v)
            return i;
    }
}
//邻接表创建无向图
bool CreateUDG(ALGraph &G)
{
    char v1,v2;
    int i,j;
    cin >> G.vexnum >> G.arcnum;
    for(int i=0;i < G.vexnum;++i)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstArc = NULL;
    }
    for(int k=0;k<G.arcnum;++k)
    {
        cin >>v1 >> v2;
        i = LocateVex1(G,v1);
        j = LocateVex1(G,v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextArc = G.vertices[i].firstArc;   //是为了连接起来+初始化p1-》next为NULL,他是倒叙插入的！先让p1指向，然后再自己指向p1
        G.vertices[i].firstArc = p1;

        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextArc = G.vertices[j].firstArc;
        G.vertices[j].firstArc = p2;
    }
    return true;
}

/**
 * 关于这2个函数，邻接矩阵表示法和邻接表的实现方式不同，下面是采用邻接表实现！
 */
//顶点v第一个邻接点
int FirstAdjVex(ALGraph &G,int v)
{
    ArcNode * firstArc =G.vertices[v].firstArc;
    if(firstArc)
        return firstArc->adjvex;
    else
        return -1;
}
//w相对于v的下一个邻接点
int NextAdjVex(ALGraph &G,int v,int w)
{
//    ArcNode *firstArc = G.vertices[v].firstArc;
//    ArcNode *cur = firstArc;
//    if(!firstArc)
//        return -1;
//    else
//    {
//        while (cur)
//        {
//            if(cur->adjvex == w)
//                break;
//            cur = cur->nextArc;
//        }
//    }
//    if(cur->nextArc)
//        return cur->nextArc->adjvex;
//    else
//        return -1;
//这里有坑，注意要判断是不是结束了，要是没有返回-1！！
   while(w != G.vertices[v].firstArc->adjvex)
       G.vertices[v].firstArc = G.vertices[v].firstArc->nextArc;

   if(G.vertices[v].firstArc->nextArc)
       return G.vertices[v].firstArc->nextArc->adjvex;
   else
       return -1;
}
//深度优先搜索遍历连通图,注意是连通图！
bool visited[MVNum] = {false};   //是否访问过

//这个DFS针对2种存储形式都可以，但是我实现了邻接表的
void DFS(ALGraph &G,int v)
{
    cout<< v << endl;
    visited[v] = true; //访问第v个顶点，并置访问标志数组为true
    for( int w = FirstAdjVex(G,v);w >= 0 ;w = NextAdjVex(G,v,w))
    {
        if(!visited[w])
            DFS(G,w);
    }
}

//深度优先搜索遍历非连通图
void DFSTraverse(ALGraph &G)
{
    for(int v = 0;v<G.vexnum;++v)
        visited[v] = false;

    for(int v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}

//用邻接表表示图的深度优先遍历
void DFS_AL(ALGraph G,int v)
{
    cout << v ;
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstArc;
    while (p!= NULL)
    {
        int w = p -> adjvex;
        if(!visited[w])
            DFS(G,w);
        p = p->nextArc;
    }
}
//用邻接矩阵表示图的深度优先遍历
/**
void DFS_AM(AMGraph G,int v)
{
    cout << v ;
    visited[v] = true;
    for(int w = 0;w < G.vexnum;w++)
    {
        if((G.arcs[v][w] != 0) && (!visited[w]))
            DFS(G,w);

    }
}
 */
//
//广度优先遍历搜索连通图
LinkQueue Q;
void BFS(ALGraph G,int v)
{
    cout << v;
    visited[v] = true;
    InitQueue(Q);
    EnQueue(Q,v);
    while(!QueueEmpty(Q))
    {
        QElemType u;
        DeQueue(Q,u);//对头出队
        for(int w = FirstAdjVex(G,u.elem);w >=0;w = NextAdjVex(G,u.elem,w))
        {
            if(!visited[w])
            {
                cout<< w;
                visited[w] =true;
                EnQueue(Q,w);
            }
        }
    }
}
//广度优先遍历非连通图
void BFSTraverse(ALGraph &G)
{
    for(int v = 0;v<G.vexnum;++v)
        visited[v] = false;

    for(int v=0;v<G.vexnum;++v)
        if(!visited[v])
            BFS(G,v);
}
//还有2种邻接法的广度优先遍历的实现
//用邻接表表示图的广度优先遍历
void BFS_AL(ALGraph G,int v)
{
    cout << v ;
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstArc;
    while (p!= NULL)
    {
        int w = p -> adjvex;
        if(!visited[w])
            BFS(G,w);
        p = p->nextArc;
    }
}


/**测试遍历
int main()
{
    ALGraph G;
    CreateUDG(G);
    DFS(G,0);
}
*/