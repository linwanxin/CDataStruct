//
// Created by lwx on 2019/3/10.
//
#include "../Stack/LinkStack.h"
#include "BiaoDaShi.h"
#include "../Tree/BiTree.h"

//以a为左子树，b为右子树，ch为根创建一个二叉树T
void CreateExpTree(BiTree &T,char a,char b,char ch)
{
    T = new BiTNode;
    T->data.elem = ch;
    if(a!=NULL && b != NULL)
    {
        BiTNode *l = new BiTNode;
        l->data.elem = a;
        l->lchild = NULL;
        BiTNode *r  = new BiTNode;
        r->data.elem = b;
        r->rchild = NULL;
        T->lchild = l;
        T->rchild = r;
    }
    else
    {
        T->lchild = NULL;
        T->rchild = NULL;
    }

}
int GetValue(char oper,int lvaule,int rvalue)
{
    int result;
    switch (oper)
    {
        case '+':
            result =  lvaule + rvalue;
            break;
        case '-':
            result = lvaule - rvalue;
            break;
        case'*':
            result = lvaule * rvalue;
            break;
        case'/':
            result = lvaule / rvalue;
            break;
    }
    return result;
}
int EvaluateExpTree(BiTree &T)
{
    int lvalue =0 ,rvalue=0;
    if(T->lchild == NULL && T->rchild == NULL)
        return T->data.elem = '0';
    else
    {
        lvalue = EvaluateExpTree(T->lchild);
        rvalue = EvaluateExpTree(T->rchild);
        return GetValue(T->data.elem,lvalue,rvalue);
    }
}
//最终构造的T就是一颗完整的二叉表达树
int InitExpTree()
{
    BiTree T = NULL;
    LinkStack EXPT,OPTR;
    InitStack(EXPT);
    InitStack(OPTR);
    ElemType e;
    e.elem = '#';
    Push(OPTR,e);
    char ch;
    cin >> ch;
    while(ch!= '#' || GetTop(OPTR).elem != '#')
    {
        if(!In(ch))
        {
            CreateExpTree(T,NULL,NULL,ch);
            Push(EXPT,T->data);
            cin>> ch;
        }
        else
        {
            switch(Precede(GetTop(OPTR).elem,ch))
            {
                case '<':
                    e.elem = ch;
                    Push(OPTR,e);
                    cin >> ch;
                    break;
                case '>':
                    ElemType theta,b,a;
                    Pop(OPTR,theta);            //弹出栈顶运算符
                    Pop(EXPT,b);Pop(EXPT,a);    //
                    CreateExpTree(T,a.elem,b.elem,theta.elem);
                    Push(EXPT,T->data);
                    break;
                case'=':
                    ElemType x;
                    Pop(OPTR,x);
                    cin>> ch;
                    break;
            }
        }
    }
    return EvaluateExpTree(T);
}



/**
* 卡死在这里了，按理来说，构造出正常的表达式T树，直接调用计算！可是那个程序并没有构造出T树！
* 还缺少了一部！
* @return
*/

/**
int main()
{
    cout<< InitExpTree() << endl;
}
 */