#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;
#define MaxSize 100

typedef struct{
    ElemType data[MaxSize];
    int len;
}SqArray;

//数组初始化
void InitArray(SqArray *&arr){
    arr = (SqArray*)malloc(sizeof(SqArray));
    arr->len = 0;
}
//销毁数组
void DestroyArray(SqArray *&arr){
    free(arr);
}
//将一个数组存入自定义数组结构
void Value(SqArray *&arr,int a[],int len){
    arr->len = len;
    for(int i=0;i<len;i++){
        arr->data[i] = a[i];
    }
}

//打印数组
void Print(SqArray* arr){
    for(int i=0;i<arr->len;i++){
        cout<<arr->data[i]<<" ";
    }
    cout<<endl;
}

int main(){
    SqArray* arr;
    int a[5] = {1,2,3,4,5};
    InitArray(arr);
    int len = sizeof(a)/sizeof(a[0]);
    Value(arr,a,len);
    cout<<arr->len<<endl;
    Print(arr);
}