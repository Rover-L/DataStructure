//
// Created by TU on 2021/3/30.
//

#include "Queue.h"


void InitQueue(LinkQueue &Q){
    //构造一个空队列
    Q.front = (QueuePtr)malloc(sizeof(Queue));
    if(!Q.front){
        cout<<"内存分配失败"<<endl;
        exit(-1);
    }
    Q.rear = Q.front;
    Q.front->next = nullptr;
}

void DestoryQueue(LinkQueue &Q){
    //摧毁一个队列
    QueuePtr p;
    while(Q.front!=Q.rear){
        p = Q.front;
        Q.front = Q.front->next;
        free(p);
    }
}

void ClearQueue(LinkQueue &Q){
    //将队列置为空
    DestoryQueue(Q);
    InitQueue(Q);
}

bool QueueEmpty(LinkQueue Q) {
    //判断队列是否为空，如果队列为空，返回true，否则返回false
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}

int QueueLenth(const LinkQueue Q){
    //返回队列元素个数，即队列长度
    QueuePtr p = Q.front;
    int i = 0;
    while(p!=Q.rear){
        p = p->next;
        i += 1;
    }
    return i;
}


bool GetHead(const LinkQueue Q, Elemtype &e){
    //若队列不空，用e返回队头元素，成功返回true，否则返回false
    if(Q.rear==Q.front)
        return false;
    else{
        e = Q.front->data;
        return false;
    }
}


void EnQueue(LinkQueue &Q, Elemtype e){
    //插入元素成为新的队头元素
    Q.rear->next = (QueuePtr)malloc(sizeof(Queue));
    if(!Q.rear->next){
        cout<<"内存分配失败"<<endl;
        exit(-1);
    }
    Q.rear->data = e;
    Q.rear = Q.rear->next;
}

bool DeQueue(LinkQueue &Q, Elemtype &e){
    //若队列不空，用e返回队头元素，删除队头，返回true；否则返回false
    if(Q.front==Q.rear)
        return false;
    else{
        QueuePtr p = Q.front;
        e = Q.front->data;
        Q.front = Q.front->next;
        free(p);
        return true;
    }
}
