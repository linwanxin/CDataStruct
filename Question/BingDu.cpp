//
// Created by lwx on 2019/3/8.
//
#include <fstream>
#include <iostream>
#include "../String/String.h"
using namespace std;

/**
 * 病毒检测问题：
 */

void Virus_detection()
{
    //实践得知，1不可以用中文，2使用相对路径是从cmake-build-debug开始寻找文件！
    ifstream inFile("../Question/cin.txt");
    ofstream outFile("E:/CLionProjects/CDataStruct/Question/cout.txt");
    int num ;
    inFile >> num;
    while(num--)
    {
        //第2轮开始要初始化，所以放到里面来！
        SString Virus;
        SString Person;
        SString Vir;                  //仅仅用来保存输出
        inFile >>Virus.ch+1;         //从下标1开始储存
        inFile >> Person.ch+1;

        int flag = 0;
        //分别求出2条的长度
        int index1 = 1;
        while(Virus.ch[index1++] != '\0')
            Virus.length++;
        int m = Virus.length;

        int index2 = 1;
        while(Person.ch[index2++] != '\0')
            Person.length++;

        for(int i = m+1,j=1;j<=m;j++)
            Vir.ch[j] = Virus.ch[i++] = Virus.ch[j];
       // Virus.ch[2*m+1] = '\0';

        for(int i =0;i< m;i++)
        {
            SString temp;
            for(int j=1;j<=m;j++)
                temp.ch[j] = Virus.ch[i+j];
            //temp.ch[m+1] = '\0';
            temp.length = m;
            flag = Index_KMP(Person, temp,1);
            if(flag)
                break;
        }
        if(flag)
            outFile<<Vir.ch+1<<"   "<<Person.ch+1<<"  " <<"YES" << endl;
        else
            outFile<<Vir.ch+1<<"   "<<Person.ch+1<<"  " <<"NO" << endl;
    }
    //不用了就关闭，防止内存泄漏！小程序直接结束无所谓，但是大型项目不可以！
    if(inFile)
        inFile.close();
    if(outFile)
        outFile.close();

}

int main()
{
    Virus_detection();
}