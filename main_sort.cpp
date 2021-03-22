#include<iostream>
using namespace std;


typedef struct {
    int* ele;   //储存基址
    int listsize;   //表长
    int lenth;      //当前长度
}Sqlist;


bool newSqList(Sqlist &p,int size){
    p.ele = (int *)malloc(size*sizeof(int)); //分配内存空间为size*sizeof(int),p.ele为基址
    if(!p.ele)return false;
    p.lenth = 0;
    p.listsize = size;
    return true;
}

void DestoryList(Sqlist &L){    //销毁线性表
    free(L.ele);
    cout<<"销毁成功"<<endl;
}

void ClearList(Sqlist &L){      //将表置为空
    free(L.ele);
    L.ele = (int *)malloc(L.listsize*sizeof(int));
    if(!L.ele){
        cout<<"分配内存失败"<<endl;
    }
    L.lenth = 0;
    cout<<"成功重置为空表"<<endl;
}

bool ListEmpty(Sqlist L){      //判断表是否为空，为空返回ture，不空返回false
    if(!L.ele)return true;
    else return false;
}

//int ListLength(Sqlist L)(){     //返回表长
//    return (int)L.lenth;
//}

void GetElem(Sqlist L,int x,int &e){
    //函数用e返回L中第x个元素
    //1<=x<=L.listsize
    if(x>=L.listsize|x<1){
        cout<<"参数x超出范围，x应满足1<=x<=L.listsize"<<endl;
    } else{
        e = *(L.ele+(x-1)*sizeof(int));
        cout<<"第x个元素:"<<e<<endl;
    }
}

//bool LocateElem(){};
//void PriorElem(){};
//void NextElem(){};

void ListInsert(Sqlist &L,int i,int e){
    //在L表中第i个位置插入e，L表长加1；
    //1<=i<=L.listsize-1
};


void sort(Sqlist &l){
    //a为Sqlist型待排序数组首地址
    //size为数组大小
    //函数将a的数组从小到大排序
    for(int i=0;i<l.listsize;++i){              //从0遍历到l.listsize-i,共遍历l.listsize次，每次将较大的放在后面
        for(int j=0;j<l.listsize-i-1;++j){
            if((*(l.ele+j*sizeof(int)))>(*(l.ele+(j+1)*sizeof(int)))){      //如果第j个小于第j+1个交换，否则不交换
                int temp = (*(l.ele+j*sizeof(int)));
                (*(l.ele+j*sizeof(int))) = (*(l.ele+(j+1)*sizeof(int)));
                (*(l.ele+(j+1)*sizeof(int))) = temp;
            }
        }
    }
}

int main_sort()
{
    int size = 0;
    cout<<"请输入排序的大小:"<<endl;
    cin>>size;
    Sqlist L;
    if(newSqList(L,size)) {
        for (int i = 0; i < size; ++i) {
            cin >> (*(L.ele+i*sizeof(int)));
            L.lenth += 1;
        }
        sort(L);
        cout << "从小到大排排序："<<endl;
        for (int i = 0; i < size; ++i) {
            cout <<(*(L.ele+i*sizeof(int)))<<"  ";
        }
    } else{
        cout<<"内存分配失败"<<endl;
        return 0;
    }
    cout<<"上传成功了吗"<<endl;
    DestoryList(L);
    return 0;
}
