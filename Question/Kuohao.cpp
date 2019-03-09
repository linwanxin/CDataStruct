//
// Created by lwx on 2019/3/7.
//

#include "../Stack/LinkStack.h"

LinkStack S1;
char ch;
bool flag;
bool Matching()
{
    InitStack(S1);
    flag = true;
    cin >> ch;
    ElemType e;
    while(ch!= '#' && flag)
    {
        e.elem = ch;
        switch (ch)
        {
            //课本真坑;不可以用'('|| '['
            case '(':
                Push(S1,e);
                break;
            case '[':
                Push(S1,e);
                break;
            case ')':
                if(!StackEmpty(S1) && GetTop(S1).elem == '(')
                    Pop(S1,e);
                else
                    //错误！
                    flag = false;
                break;
            case ']':
                if(!StackEmpty(S1) && GetTop(S1).elem == '[')
                    Pop(S1,e);
                else
                    flag = false;
                break;
        }
        cin>>ch;
    }
    if(StackEmpty(S1) && flag)
        return true;
    else
        return false;
}

//
//int main()
//{
//    if(Matching())
//    {
//        cout<< "Success!"<< endl;
//    }
//    else{
//        cout<<"Failer"<< endl;
//    }
//}
