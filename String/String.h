//
// Created by lwx on 2019/3/8.
//
/**
 * 顺序存储：
 * 分为串的定长和不定长
 * 链式存储：基本不用！
 */
#ifndef CDATASTRUCT_STRING_H
#define CDATASTRUCT_STRING_H
#define MAXSIZE 255
/**
 * 定长存储:
 * 为了方便处理，【0】不适用！，因为长度是从1开始！
 */
typedef struct
{
    char ch[MAXSIZE+1] = {'\0'};
    int length = 0;
}SString;
/**
 * 不定长
 */
typedef struct
{
    char *ch;
    int length;
}HString ;

int Index_BF(SString &S,SString &T,int pos);
int Index_KMP(SString S,SString T,int pos);

#endif //CDATASTRUCT_STRING_H
