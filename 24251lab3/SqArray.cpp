#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;
#define MaxSize 100

typedef struct{
    ElemType data[MaxSize];
    int len;
}SqArray;

void InitArray(SqArray *&arr){
    arr = (SqArray*)malloc(sizeof(SqArray));
    arr->len = 0;
}

void DestroyArray(SqArray *&arr){
    free(arr);
}

void Value(SqArray *&arr){
    
}

void Assign(SqArray* &arr,int a[]){
    
}