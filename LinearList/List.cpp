//
// Created by YT on 2021/3/23.
//

#include "List.h"


bool newSqList(Sqlist &p,int size){
    //分配内存空间为size*sizeof(int),p.ele为基址
    p.ele = (ElemType *)malloc(size*sizeof(ElemType));
    if(!p.ele)return false;
    p.lenth = 0;
    p.listsize = size;
    return true;
}

void DestoryList(Sqlist &L){
    //销毁线性表
    free(L.ele);
    cout<<"销毁成功"<<endl;
}

void ClearList(Sqlist &L){
    //将顺序表置为空
    free(L.ele);
    L.ele = (ElemType *)malloc(L.listsize*sizeof(ElemType));
    if(!L.ele){
        cout<<"分配内存失败"<<endl;
    }
    L.lenth = 0;
    cout<<"成功重置为空表"<<endl;
}

bool ListEmpty(Sqlist L){
    //判断表是否为空，为空返回ture，不空返回false
    if(!L.ele)return true;
    else return false;
}

int ListLength(const Sqlist L){
    //返回表长
    cout<<"当前表长为："<<L.lenth<<endl;
    return L.lenth;
}

void ListGetElem(const Sqlist L,int x,ElemType &e){
    //函数用e返回L中第x个元素
    //x满足0<=x<=L.lenth-1
    if(x>=L.lenth|x<0){
        cout<<"参数x超出范围，x应小于当前表长"<<endl;
    } else{
        e = *(L.ele+x);
        cout<<"第"<<x+1<<"个元素为:"<<e<<endl;
    }
}

void ListPrintAll(const Sqlist L){
    //遍历顺序表进行打印输出
    cout<<"顺序表的元素依次为：";
    for(int i=0;i<L.lenth;++i){
        cout<<*(L.ele+i)<<"  ";
    }
    cout<<endl;
}

void List_sort(Sqlist &L){
    //函数将a的数组从小到大排序
    //a为Sqlist型待排序数组首地址
    //size为数组大小
        for(int i=0;i<L.lenth;++i){              //从0遍历到l.listsize-i,共遍历l.listsize次，每次将较大的放在后面
            for(int j=0;j<L.lenth-i-1;++j){
                if((*(L.ele+j))>(*(L.ele+(j+1)))){      //如果第j个大于第j+1个交换，否则不交换
                    int temp = (*(L.ele+j));
                    (*(L.ele+j)) = (*(L.ele+(j+1)));
                    (*(L.ele+(j+1))) = temp;
            }
        }
    }
}

void ListInsert(Sqlist &L,int i,ElemType e){
    //向线性表第i个位置插入ElemType类型的e
    //注意i的取值：0<=i<=L.lenth-1
    if(L.lenth+1>L.listsize){
        cout<<"线性表已满，插入失败"<<endl;
        return;
    }else if(i>L.lenth){
        cout<<"插入的位置大于当前表长，插入失败"<<endl;
    }else{
        for(int j=L.lenth;j>=i;--j){
            *(L.ele+j+1) = *(L.ele+j);
        }
        *(L.ele+i) = e;
        L.lenth +=1;
        cout<<"成功在第"<<i<<"个位置插入"<<e<<"!"<<endl;
    }
}

void ListDelete(Sqlist &L,ElemType e){
    //在线性表L中寻找ElemType类型e，并删除
    bool k = false;
    for(int i=0;i<L.lenth;++i){
        if(e==*(L.ele+i)){  //遍历找到e
            k = true;
            for(int j=i;j<L.lenth-1;++j){
                *(L.ele+j) = *(L.ele+j+1);  //对e后面的元素循环向前移动一格
            }
            L.lenth -= 1;   //L表长减1
            break;
        }
    }
    if(k){
        cout<<"成功删除"<<e<<"!"<<endl;
    }
}

int main1()
{
    int size = 0;
    int c;
    cout<<"请输入顺序表的大小:"<<endl;
    cin>>size;
    Sqlist L;
    newSqList(L,LIST_SIZE_MAX);
    cout<<"请依次输入顺序表数据"<<endl;
    for (int i = 0; i < size; ++i) {
        cin >> c;
        ListInsert(L,i,c);
    }
    ListLength(L);
    ListPrintAll(L);
    ListInsert(L,3,5);
    ListPrintAll(L);
    ListLength(L);
    ListGetElem(L,4,c);
    ListDelete(L,6);
    ListPrintAll(L);
    ListLength(L);
    DestoryList(L);
    return 0;
}