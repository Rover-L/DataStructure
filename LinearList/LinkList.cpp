//
// Created by TU on 2021/3/21.
//
#include <iostream>
using namespace std;


typedef  int ElemType;

typedef struct LNode{
    ElemType data;
    LNode *next;
}*LinkNode;

void LinkInitList(LinkNode &L){
    //初始化L为带有头结点的链表
    //若L不是空表则返回错误，否则将L.data初始化为0，L.next置为空指针
    if(!L) {
        LinkNode p;
        p = (LinkNode) malloc(sizeof(LNode));
        if (!p) {
            cout << "内存分配失败" << endl;
            exit;
        }
        p->next = nullptr;
        p->data = 0; //这里将p指向的data初始化为0，可能会有BUG
        L = p;
        cout << "内存分配成功" << endl;
    } else{
        cout<<"初始化链表不为空！"<<endl;
    }
}

void LinkList_HeadInsert(LinkNode &L,ElemType i){
    //将链表L头部插入ElemType类型的i
    LinkNode s;
    s = (LinkNode)malloc(sizeof(LNode));
    if(!s){
        cout<<"内存分配失败"<<endl;
        exit;
    }
    s->next = L;
    s->data = i;
    L = s;
    cout<<"链表头部插入成功"<<endl;
}

void LinkList_TailInsert(LinkNode &L,ElemType i){
    //向链表尾部插入ElemType类型的i
    LinkNode s,p = L;
    s = (LinkNode)malloc(sizeof(LinkNode));
    if(!s){
        cout<<"内存分配失败"<<endl;
        exit;
    }
    while(p){
        p = p->next;
    }
    p->next = s;
    s->next = nullptr;
    s->data = i;
    cout<<"尾部插入成功"<<endl;
}

int LinkListSize(LinkNode &L){
    //返回单链表L的长度
    int i = 0;
    while(L){
        i += 1;
        L = L->next;
    }
    return i;
}


void LinkList_Delete(LinkNode &L,ElemType i){
    //搜索单链表L中ElemType类型元素i，将其删除
    //若搜索不到，提示未找到
    bool K = false;
    while(L){
        if(L->data!=i){
            L = L->next;
        }else{
            LNode *s;
            s = L->next;
            L = s->next;
            free(s);
            cout<<"元素成功删除"<<endl;
            K = true;
            break;
        }
    }
    if(!K){
        cout<<"未找到该元素"<<endl;
    }
}

void LinkList_Inverse(LinkNode &L){
    //将单链表L全部倒置
    //新定义单链表temp，采用头插法将单链表L装入，实现倒置
    LinkNode temp;
    temp = (LinkNode)malloc(sizeof(LNode));
    if(!temp){
        cout<<"内存分配不足"<<endl;
    }
    while(L){
        LinkList_HeadInsert(temp,L->data);
        L = L->next;
    }
    L = temp;
    free(temp);
    cout<<"单链表实现倒置！"<<endl;
}

int main(){
    LinkNode L;
    LinkInitList(L);
    cout<<"链表目前长度为"<<LinkListSize(L)<<endl;
    LinkList_HeadInsert(L,5);
    LinkList_HeadInsert(L,7);
    cout<<"链表目前长度为"<<LinkListSize(L)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;

}