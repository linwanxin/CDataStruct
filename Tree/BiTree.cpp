//
// Created by lwx on 2019/3/9.
//

#include "BiTree.h"
#include <iostream>
#include "../Stack/LinkStack.h"
using namespace std;
//递归实现中序遍历
void InOrderTraverse(BiTree &T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data.elem << endl;
        InOrderTraverse(T->rchild);
    }
}
//借助栈实现非递归实现中序遍历，而且这栈中的元素类型要等于链表的元素类型
void NInOrderTraverse(BiTree &T)
{
    LinkStack S;
    InitStack(S);
    BiTree  p = T;
    ElemType q;
    //这里的技巧是先利用p后面利用栈
    while(p|| !StackEmpty(S))
    {
        if(p)           //p非空
        {
            Push(S,p->data); //根节点入栈
            p = p->lchild;
        }
        else        //p为空
        {
            Pop(S,q);  //将栈顶元素出栈访问！
            cout<< q.elem << endl;
            p = p->rchild;
        }
    }
}

//先序遍历
void PerOrderTraverse(BiTree &T)
{
    if(T)
    {
        cout<<T->data.elem << endl;
        PerOrderTraverse(T->lchild);
        PerOrderTraverse(T->rchild);
    }
}
//还一种层次遍历法，借助队列实现
void CengCi(BiTree &T)
{

}


/**先序遍历创建二叉链表
 * 输入的话类似是输入整个完全二叉树的输入法！
//           A
          /
        B
     /  \
   C     D
       / \
     E   F
     \
      G
  输入:ABC##DE#GF###建立先序二叉树
   */
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch == '#')
        T= NULL;
    else
    {
       BiTNode *T = new BiTNode;
       T->data.elem = ch;
       CreateBiTree(T->lchild);
       CreateBiTree(T->rchild);
    }
}
//二叉树的复制
void Copy(BiTree &T,BiTree &NewT)
{
    if(T == NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiTNode;
        NewT->data = T->data;//复制根节点
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
}
//树的深度：节点最大的层次，在后序的遍历的基础上进行的！
int Depth(BiTree &T)
{
    if(T== NULL)
        return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m > n)
            return m+1;
        else
            return n+1;
    }
}

//统计二叉树节点的个数
int NodeCount(BiTree &T)
{
    if(T== NULL)
        return 0;
    else
        return NodeCount(T->lchild) +NodeCount(T->rchild) + 1;
}

//实现度为0，1，2节点的个数



