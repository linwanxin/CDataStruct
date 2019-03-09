//
// Created by lwx on 2019/3/8.
//
#include <cstring>
#include "String.h"
#include <iostream>
using namespace std;
/**
 * BF算法
 * 从主串的pos开始匹配，返回在主串的位置
 * @param S
 * @param T
 * @param pos
 * @return
 */
int Index_BF(SString &S,SString &T,int pos)
{
    int i = pos,j = 1;
    while(i<=S.length && j<=T.length)
    {
        if(S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i-j + 2;
            j = 1;
        }
    }
    if(j >T.length)
        return i-T.length;
    else
        return 0;
}

/**
 * KMP算法:O（N+M）
 *总体：主串不回溯，子串尽可能最大的回溯！
 * 只和子串本身有关：
 * 子串关键是回溯到哪里：子串最前面的k个字符和j之前的最后k个字符是一样的：
 * 也就是求解子串每个j对应的k，next[j] = k;
 * 从表面来看就是寻找最大公共前后缀，从数学角度来说分成2个！
 * @return
 */
 void get_next(SString T,int next[])
 {
     int i = 1,j=0;
     next[1] = 0;
     while ( i<T.length)
     {
         if(j ==0 || T.ch[i] == T.ch[j])
         {
             ++i;
             ++j;
             next[i] = j;
         }
         else
             j = next[j];
     }

 }
int Index_KMP(SString S,SString T,int pos)
{
     int next[MAXSIZE];
     get_next(T,next);
    int i = pos,j = 1;
    while(i<=S.length && j<=T.length)
    {
        if( j== 0 ||S.ch[i] ==T.ch[j])
        {
            ++i;++j;
        }
        else
        {
            j = next[j];
        }
    }
    if(j>=T.length)
        return i-T.length;
    else
        return 0;
}

/**
int main()
{
    SString S;
    strcpy(S.ch," ababcabcacbab");
    S.length = 13;
    SString T;
    strcpy(T.ch," cac");
    T.length = 3;
    cout<< Index_BF(S,T,1)<< endl;

    cout<< Index_KMP(S,T,1)<< endl;
}
 */