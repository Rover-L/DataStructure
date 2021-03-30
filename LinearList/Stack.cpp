//
// Created by TU on 2021/3/30.
//
#include "Stack.h"

void InitStack(SqStack &S){
    //构造一个空栈，S.base为基址
    S.base = (Elemtype *)malloc(S.stacksize*sizeof(Elemtype));
    if(!S.base){
        cout<<"内存分配失败"<<endl;
        exit(-1);
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}

void DestoryStack(SqStack &S){
    //摧毁栈
    free(S.base);
}

void ClearStack(SqStack &S){
    //将栈置为空
    free(S.base);
    InitStack(S);
}

bool StackEmpty(SqStack &S){
    //判断栈是否为空，栈空返回true，栈不空返回false
    if(S.top==S.base){
        return true;
    }else{
        return false;
    }
}

int StackLength(const SqStack S){
    //返回栈中元素个数，求长度
    return S.top-S.base;
}

bool GetTop(const SqStack S,Elemtype &e){
    //若栈不空，用e返回栈顶元素，成功返回true，否则返回false
    if(S.top==S.base)
        return false;
    else{
        e = *S.top;
        return true;
    }
}

void Push(SqStack &S,Elemtype e){
    //若栈不满，则插入e成为栈顶，否则栈满追加储存空间
    if(S.top-S.base>=S.stacksize){
        S.base = (Elemtype *)realloc(S.base,S.stacksize+(STACK_INCREMENT)*sizeof(Elemtype));
        if(!S.base){
            cout<<"内存分配失败"<<endl;
            exit(-1);
        }
    }else{
        *S.top = e;
        S.top += 1;     //栈顶加1
    }
}

bool Pop(SqStack &S,Elemtype &e){
    //若栈不空，删除栈顶元素，用e返回栈顶元素，成功返回true，否则栈空，返回false
    if(S.top==S.base)
        return false;
    else{
        e = *(S.top-1);     //栈顶减一
        return true;
    }
}


