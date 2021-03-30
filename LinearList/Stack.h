//
// Created by TU on 2021/3/30.
//
#include<iostream>
using namespace std;

#define STACK_INIT_SIZE 50
#define STACK_INCREMENT 10

typedef int Elemtype;
typedef struct stack {
    Elemtype * base;    //始终指向栈底
    Elemtype * top;     //指向栈顶，栈空：top = base
    int stacksize;
}SqStack;

void InitStack(SqStack &);
////构造一个空栈，S.base为基址

void DestoryStack(SqStack &);
////摧毁栈

void ClearStack(SqStack &);
////将栈置为空

bool StackEmpty(SqStack &);
////判断栈是否为空，栈空返回true，栈不空返回false

int StackLength(SqStack);
////返回栈中元素个数，求长度

bool GetTop(SqStack,Elemtype &);
////若栈不空，用e返回栈顶元素，成功返回true，否则返回false

void Push(SqStack &,Elemtype);
////若栈不满，则插入e成为栈顶，否则栈满追加储存空间

bool Pop(SqStack &,Elemtype &);
////若栈不空，删除栈顶元素，用e返回栈顶元素，成功返回true，否则栈空，返回false
