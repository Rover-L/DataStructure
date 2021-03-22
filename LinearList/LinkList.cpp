//
// Created by TU on 2021/3/21.
//
#include "LinkList.h"
typedef  int ElemType;


void LinkInitList(LinkNode &L){
    //初始化L为带有头结点的链表
    //L.next置为空指针
    L = (LinkNode)malloc(sizeof(LNode));
    if (!L) {
        cout << "内存分配失败" << endl;
        exit(0);
    }
    L->next = nullptr;
    cout << "内存分配成功" << endl;
}

void LinkListDestroy(LinkNode &L){
    //摧毁单链表L
    LinkNode s;
    while(L){
        s = L->next;
        free(L);
        L = s;
    }
    cout<<"成功回收内存空间"<<endl;
}

void LinkList_HeadInsert(LinkNode &L,ElemType i){
    //将链表L头部插入ElemType类型的i
    LinkNode s;
    s = (LinkNode)malloc(sizeof(LNode));
    if(!s){
        cout<<"内存分配失败"<<endl;
        exit(0);
    }
    s->next = L->next;
    s->data = i;
    L->next = s;
    cout<<"链表头部插入成功"<<endl;
}

void LinkList_TailInsert(LinkNode &L,ElemType i){
    //向链表尾部插入ElemType类型的i
    LinkNode s,p = L;
    s = (LinkNode)malloc(sizeof(LNode));
    if(!s){
        cout<<"内存分配失败"<<endl;
        exit(0);
    }
    while(p->next){
        p = p->next;
    }
    s->data = i;
    s->next = nullptr;
    p->next = s;
    cout<<"尾部插入成功"<<endl;
}

int LinkListSize(LinkNode L){
    //返回单链表L的长度
    int i = 0;
    LinkNode p = L->next;
    while(p) {
        i += 1;
        p = p->next;
    }
    return i;
}


void LinkList_Print(const LinkNode &L) {
    //对单链表数据打印输出
    cout<<"单链表储存的数据依次为：";
    LinkNode p = L;  //保存头结点
    while(p->next){
        cout<<p->next->data<<"  ";
        p = p->next;
    }
    cout<<endl;
}

void LinkList_Delete(LinkNode &L,ElemType i){
    //搜索单链表L中ElemType类型元素i，将其删除
    //若搜索不到，提示未找到
    bool K = false;
    LinkNode p = L; //保存头结点
    while(p->next){
        if(p->next->data!=i){
            p = p->next; //p指向的下一个结点的数据不等于i，则指向下一个
        }else{
            LNode *s;
            s = p->next->next; //找到i，则将s指向i所在的结点
            p->next = s;
            cout<<"元素成功删除"<<endl;
            K = true;
            break;
        }
    }
    if(!K){
        cout<<"未找到该元素"<<endl;
    }
}

void LinkList_Reverse_tail(LinkNode &L){
    //尾插法将单链表倒置
    LinkNode temp = L->next;
    L->next = nullptr;
    while(temp){
        LinkList_TailInsert(L,temp->data);
        temp = temp->next;
    }
    cout<<"单链表实现倒置！"<<endl;
}


bool LinkList_Reverse_Head(LinkNode &L){
    //头插法逆置
    LinkNode p, q;        //p在前面指引，q与头结点实现插入
    p = L->next;
    L->next = nullptr;
    while (p)
    {
        q = p;
        p = p->next;
        q->next = L->next;  //
        L->next = q;
    }
    return true;
}

void LinkList_Inverse1(LinkNode &L){
    //将单链表L全部倒置
    //前指针和后指针的值交换
    LinkNode front,last;
    ElemType temp;
    front = (LinkNode)malloc(sizeof(LNode));
    last = (LinkNode)malloc(sizeof(LNode));
    if(!front||!last){
        cout<<"内存分配不足"<<endl;
        exit(0);
    }
    int linkListSize = LinkListSize(L);
    for(int i=0;i<linkListSize/2;++i){
        front = L->next;
        last = L->next;
        for(int j=linkListSize-i-1;j>0;--j){
            last = last->next;
        }
        for(int k=0;k<i-1;++k){
            front = front->next;
        }
        temp = last->data;
        last->data = front->data;
        front->data = temp;
    }
    cout<<"单链表实现倒置！"<<endl;
}

int main(){
    LinkNode L;
    LinkInitList(L);
    cout<<"链表目前长度为"<<LinkListSize(L)<<endl;
    LinkList_HeadInsert(L,5);
    LinkList_HeadInsert(L,7);
    LinkList_TailInsert(L,9);
    LinkList_TailInsert(L,10);
    LinkList_Print(L);
    cout<<"链表目前长度为"<<LinkListSize(L)<<endl;
    LinkList_Inverse1(L);
    LinkList_Print(L);
    LinkList_Reverse_Head(L);
    LinkList_Print(L);
    LinkList_Reverse_tail(L);
    LinkList_Delete(L,7);
    LinkList_Print(L);
    LinkListDestroy(L);
    return 0;
}