//
// Created by TU on 2021/3/30.
//
#include<iostream>
using namespace std;

#define STACK_INIT_SIZE 50;
#define STACK_INCREMENT 10;

typedef int Elemtype;
typedef struct stack {
    Elemtype * base;    //始终指向栈底
    Elemtype * top;     //指向栈顶，栈空：top = base
    int stacksize;
}SqStack;
