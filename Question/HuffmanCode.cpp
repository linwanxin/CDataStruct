//
// Created by lwx on 2019/3/10.
//
#include <cstring>
#include "../Tree/BiTree.h"
/**
 * 根据huffman树求哈夫曼编码；前提是哈夫曼树是构建好的！
 */
 void CreatHuffmanCode(HuffmanTree &HT,HuffmanCode &HC,int n)
{
     HC = new char*[n+1];  //存储分配n个字符编码的哈夫曼编码，存储在编码表HC中
     char *cd = new char[n]; //分配临时存放每个字符编码的动态数组空间，n仅仅是随便的
     cd[n-1] = '\0';
     int start,c,f;
     //倒叙求解
     for(int i=1;i<=n;i++)
     {
         start = n-1;
         c = i,f = HT[i].parent;//1-n存储叶子节点
         while(f!=0)
         {
             --start;
             if(HT[f].lchild == c)
                 cd[start] = '0';
             else
                 cd[start] = '1';

             c = f;
             f = HT[f].parent;
         }
         HC[i] = new char[n-start];
         strcpy(HC[i],&cd[start]);
     }
     delete cd; //释放临时空间
}

void printHuffmanCode( HuffmanCode &HC,int n)
{
     for(int i=1;i<=n;i++)
     {
         cout<<HC[i] << endl;
     }
}
int main()
{
     HuffmanTree  HT;
     int n = 8;
     HuffmanCode HC;
     CreateHuffmanTree(HT,n);
     CreatHuffmanCode(HT,HC,n);
     printHuffmanCode(HC,n);
     return 0;
}