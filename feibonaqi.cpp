//
// Created by Anyouto on 2021/3/15.
//

#include<iostream>
using namespace std;

int feibonaqiDigui(int n){
    //斐波那契数列f0=0，f1=1，f2=1，……fi=f(i-1)+f(i-2)
    //采用递归方法进行计算
    if(n==0)return 0;
    else if(n==1)return 1;
    else if(n>1)return feibonaqiDigui(n-1)+feibonaqiDigui(n-2);
    else{
        cout<<"输入错误，n大于等于0"<<endl;
        return 0;
    }
}

int feibonaqiXunhuan(int n){
    //采用循环进行计算
    if(n==0)return 0;
    else if(n==1)return 1;
    else if(n>1){
        int a=0,b=1;
        int result = 0;
        for(int i=1;i<n;++i){
            result = a+b;
            a = b;
            b = result;
        }
        return result;
    }
    else{
        cout<<"输入错误，n大于等于0"<<endl;
        return 0;
    }
}
int main3(){
    int m = 7;
    cout<<"递归结果："<<feibonaqiDigui(7)<<endl;
    cout<<"循环算法结果："<<feibonaqiXunhuan(7);
}