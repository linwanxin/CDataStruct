//
// Created by lwx on 2019/3/11.
//

#ifndef CDATASTRUCT_MAP_H
#define CDATASTRUCT_MAP_H
#define MaxInt 32767    //极大值  无穷大
#define MVNum 100      // 最大的顶点数

//图的邻接矩阵表示法
typedef char VerTexType;  //顶点数据类型
typedef int ArcType;    //权值类型

typedef struct AMGraph
{
    VerTexType vexs[MVNum];    //顶点表
    ArcType arcs[MVNum][MVNum];  //邻接矩阵
    int vexnum,arcnum;   //当前点数和边数
};
bool CreateUDN(AMGraph &G);



//图的邻接表表示法
typedef int OtherInfo ;  //表示权值之类的
//边节点
typedef struct ArcNode
{
    int adjvex ;   //指向的顶点在数组中的位置
    ArcNode *nextArc ;  //指向下条边
    OtherInfo info;
};
//顶点信息
typedef struct VNode
{
    VerTexType data;        //顶点数据
    ArcNode * firstArc  ; // 指向第一条边
}AdjList[MVNum];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum,arcnum;  //当前的顶点和边数
};


#endif //CDATASTRUCT_MAP_H
