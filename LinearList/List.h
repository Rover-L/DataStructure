//
// Created by YT on 2021/3/23.
//
#include<iostream>
using namespace std;
#define  LIST_SIZE_MAX 100
typedef int ElemType;
typedef struct {
    ElemType* ele;   //储存基址
    int listsize;   //表长
    int lenth;      //当前长度
}Sqlist;

bool newSqList(Sqlist &,int);
////分配内存空间为size*sizeof(int),p.ele为基址

void DestoryList(Sqlist &);
////销毁线性表

void ClearList(Sqlist &);
////将顺序表置为空

bool ListEmpty(Sqlist);
////判断表是否为空，为空返回ture，不空返回false

int ListLength(Sqlist);
////返回表长

void ListGetElem(Sqlist ,int ,ElemType &);
////函数用e返回L中第x个元素

void ListPrintAll(Sqlist);
////遍历顺序表进行打印输出

void List_sort(Sqlist &);
////函数将a的数组从小到大排序(冒泡法)

void ListInsert(Sqlist &,int ,ElemType );
////向线性表第i个位置插入ElemType类型的e

void List_sorted_Insert(Sqlist &L,ElemType);
////向递增有序的线性表按顺序插入ElemType类型的e

void ListDelete(Sqlist &,ElemType );
////在线性表L中寻找ElemType类型e，并删除

void List_sorted_Delete(Sqlist &,ElemType m,ElemType n);
////在线性表L中寻找小于m且大于n的ElemType元素，并删除

void ListReverse(Sqlist &);
////将顺序表倒置