//
// Created by lwx on 2019/3/9.
//

#ifndef CDATASTRUCT_BITREE_H
#define CDATASTRUCT_BITREE_H

#include "TElemType.h"
#include "../Stack/ElemType.h"

//二叉树
typedef struct BiTNode
{
    ElemType data;
    BiTNode *lchild,*rchild;
}*BiTree;
//线索二叉树
typedef struct BiThrNode
{
    ElemType data;
    BiThrNode *lchild,*rchild;
    int LTag,RTag;
}*BiThrTree;
//哈夫曼树:用动态数组存储2N个：1-N存储叶子节点，剩余N-1个存储非叶子节点！
typedef struct HTNode
{
    int weight;
    int parent,lchild,rchild;
}*HuffmanTree;

//哈夫曼编码表
typedef char **HuffmanCode;


void CreateHuffmanTree(HuffmanTree &HT,int n);

#endif //CDATASTRUCT_BITREE_H
