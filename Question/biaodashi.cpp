#include "../Stack/LinkStack.h"

//
// Created by lwx on 2019/3/8.
//

//返回是运算符！
bool In(char ch)
{
    if(isdigit(ch))
        return false;
    else
        return true;

}
//比较运算符优先级
char Precede(char ch,char operate)
{
    char result;
    //这里用if会好点！
    if(operate == '+' || operate == '-')
    {
        if(ch == '(' || ch == '#')
            result = '<';
        else
            result = '>';
    }
    else if(operate == '*' || operate == '/')
    {
        if(ch == '+'|| ch == '-' || ch =='('|| ch == '#')
            result = '<';
        else
            result = '>';
    }
    else if(operate == '(')
    {
        if(ch != ')' )
            result = '<';
    }
    else if(operate == ')')
    {
        if(ch == '(')
            result = '=';
        else if(ch == '#');
        else
            result = '>';
    }
    else if(operate == '#')
    {
        if(ch == '#')
            result = '=';
        else if(ch == '(');
        else
            result = '>';
    }
    return result;
}
//算术
char Operate(char a,char oper,char b)
{
    int result;
    switch (oper)
    {
        case '+':
           result =  int(a-'0') +int(b-'0');
            break;
        case '-':
            result = int(a-'0') - int(b-'0');
            break;
        case'*':
            result = int(a-'0') * int(b-'0');
            break;
        case'/':
            result = int(a-'0') / int(b-'0');
            break;
    }
    return char(result +'0');
}
char EvaluateExpression()
{
    LinkStack OPND;
    LinkStack OPTR;
    InitStack(OPND);
    InitStack(OPTR);
    ElemType e;
    e.elem = '#';
    char ch;
    Push(OPTR,e);
    cin >> ch;
    while(ch!='#' || GetTop(OPTR).elem !='#')
    {
        e.elem = ch;
        if(!In(ch))
        {
            Push(OPND,e);
            cin>> ch;
        }
        else
        {
            //比较栈顶元素和ch的优先级
            switch(Precede(GetTop(OPTR).elem,ch))
            {
                case '<':
                    Push(OPTR,e);
                    cin>>ch;
                    break;
                case '>':
                    ElemType theta,a,b;
                    Pop(OPTR,theta);
                    Pop(OPND,b),Pop(OPND,a);
                    ElemType result;
                    result.elem = Operate(a.elem,theta.elem,b.elem);
                    Push(OPND,result);
                    break;
                case '=':
                    ElemType x;
                    Pop(OPTR,x);
                    cin>>ch;
                    break;
            }
        }
    }
    return GetTop(OPND).elem;
}

/**
int main()
{
    cout<< int(EvaluateExpression()-'0')<<endl;
}
*/