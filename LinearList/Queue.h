//
// Created by TU on 2021/3/30.
//
#include<iostream>

using namespace std;

typedef int Elemtype;

typedef struct Queue{
    Elemtype data;
    struct Queue *next;
}Queue,* QueuePtr;
typedef struct{
    QueuePtr front;     //队列头指针
    QueuePtr rear;      //队列尾指针
}LinkQueue;

void InitQueue(LinkQueue &);
////构造一个空队列

void DestoryQueue(LinkQueue &);
////摧毁一个队列

void ClearQueue(LinkQueue &);
////将队列置为空

bool QueueEmpty(LinkQueue);
////判断队列是否为空，如果队列为空，返回true，否则返回false

int QueueLenth(LinkQueue);
////返回队列元素个数，即队列长度

bool GetHead(LinkQueue, Elemtype &);
////若队列不空，用e返回队头元素，成功返回true，否则返回false

void EnQueue(LinkQueue &, Elemtype);
////插入元素成为新的队头元素

bool DeQueue(LinkQueue &, Elemtype &);
////若队列不空，用e返回队头元素，删除队头，返回true；否则返回false

