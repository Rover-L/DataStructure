//
// Created by YT on 2021/3/23.
//
#include <iostream>
using namespace std;

typedef  int ElemType;

typedef struct LNode{
    ElemType data;  //数据
    LNode *next;    //指向下一个结点
}*LinkNode;

void LinkInitList(LinkNode &);
////初始化L为带有头结点的链表
void LinkListDestroy(LinkNode &);
////摧毁单链表
void LinkList_HeadInsert(LinkNode &,ElemType);
////将链表L头部插入ElemType类型的i
void LinkList_TailInsert(LinkNode &,ElemType);
////向链表尾部插入ElemType类型的i
int LinkListSize(LinkNode);
////返回单链表L的长度
void LinkList_Print(const LinkNode &);
////对单链表数据打印输出
void LinkList_Delete(LinkNode &,ElemType);
////搜索单链表L中ElemType类型元素i，将其删除
void LinkList_Reverse_tail(LinkNode &);
////尾插法将单链表倒置
bool LinkList_Reverse_Head(LinkNode &);
////头插法将单链表逆置
void LinkList_Inverse1(LinkNode &);
////将单链表逆置，O(n^2)
