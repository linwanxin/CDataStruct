//
// Created by lwx on 2019/3/9.
//

#ifndef CDATASTRUCT_BITREE_H
#define CDATASTRUCT_BITREE_H

#include "TElemType.h"
//二叉树
typedef struct BiTNode
{
    ElemType data;
    BiTNode *lchild,*rchild;
}*BiTree;
//线索二叉树

#endif //CDATASTRUCT_BITREE_H
