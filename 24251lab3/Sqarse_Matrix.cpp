#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100

//稀疏矩阵
typedef struct{
    int row; //行
    int col; //列
    int data[MaxSize][MaxSize]; //数据
}S_Matrix;
//三元组元素结构体
typedef struct{
    int row; //行
    int col; //列
    int data; //数据
}Tri_Elem;
//三元组结构体
typedef struct{
    int count; //元素个数
    Tri_Elem arr[MaxSize];
}Triplets;



//初始化矩阵
void Init_Matrix(S_Matrix*& M){
    M=(S_Matrix*)malloc(sizeof(S_Matrix));
    M->row=0;
    M->col=0;
}
//初始化三元组
void Init_Tri(Triplets*& T){
    T = (Triplets*)malloc(sizeof(Triplets));
    T->count=0;
}

//稀疏矩阵转为三元组
void Change(S_Matrix*M,Triplets*& T){
    //先统计非零元素个数
    int count = 0;
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            if(M->data[i][j] != 0){
                count++;
            }
        }
    }
    T->count = count;
    while(count != 0)
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            if(M->data[i][j] != 0){
                T->arr[T->count-count].row = i;
                T->arr[T->count-count].col = j;
                T->arr[T->count-count].data = M->data[i][j];
                count--;
            }
        }
    }
}
//转化为三元组后实现矩阵转置
void Tri_Trans(Triplets*& T){
    
}
//打印三元组
void Print_Triplets(Triplets* T){
    for(int i=0;i<T->count;i++){
        cout<<"{"<<T->arr[i].row<<","<<T->arr[i].col<<","<<T->arr[i].data<<"}"<<endl;
    }
}

int main(){
    S_Matrix* M;
    Init_Matrix(M);
    cout<<"请输入稀疏矩阵的行：";
    cin>>M->row;   
    cout<<"请输入稀疏矩阵的列：";
    cin>>M->col;
    cout<<"请依次输入稀疏矩阵的元素值：";
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            cin>>M->data[i][j];
        }
    }
    cout<<"稀疏矩阵为："<<endl;
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            cout<<M->data[i][j]<<" ";
        }
        cout<<endl;
    }
    Triplets* T;
    Init_Tri(T);
    Change(M,T);
    cout<<"存储为三元组："<<endl;
    Print_Triplets(T);
    cout<<endl;
}