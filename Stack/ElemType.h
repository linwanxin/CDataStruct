//
// Created by lwx on 2019/3/7.
//

#ifndef CDATASTRUCT_ELEMTYPE_H
#define CDATASTRUCT_ELEMTYPE_H

#include <iostream>
using namespace std;
/**为数制题目设计
typedef struct ElemType
{
    //填充数据
    int elem;

    //为了实现递归打印而增加的函数
    void print()
    {
        cout<< elem << endl;
    }
};
*/
//为括号匹配设计的
typedef struct ElemType
{
    //填充数据
    char elem;

    //为了实现递归打印而增加的函数
    void print()
    {
        cout<< elem << endl;
    }
};

#endif //CDATASTRUCT_ELEMTYPE_H
