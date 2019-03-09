//
// Created by lwx on 2019/3/7.
//
/**
 * 10进制转成8进制！
 */
#include "../Stack/LinkStack.h"

LinkStack S;
void conversion(int N)
{
    InitStack(S);
    ElemType e;
    while (N)
    {
        e.elem = N%8;
        Push(S,e);
        N/=8;
    }
    while(!StackEmpty(S))
    {
        Pop(S,e);
        //输出打印，在ElemType中实现！
        e.print();
    }
}
/**
int main()
{
    conversion(1348);
}
*/

