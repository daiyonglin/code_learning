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

//十字链表 结点结构体
typedef struct Node{
    int row,col,data; //行、列、数据
    Node * down; //在一列上指向下的指针
    Node * right; //在一行上指向右边的指针
}Node;
//十字链表结构体
typedef struct{
    int L_row,L_col,NodeNum;//矩阵行数、列数、非零元素个数
    Node *RowHead,*ColHead;//行和列链表头指针向量
}CrossList;

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
//初始化十字链表
void Init_CrossList(CrossList*& C){
    C = (CrossList*)malloc(sizeof(CrossList));
    C->L_row = C->L_col = C->NodeNum =0;
    C->RowHead = C->ColHead = NULL;
}

//稀疏矩阵转为三元组
void Change_Tri(S_Matrix*M,Triplets*& T){
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

//稀疏矩阵转为十字链表
void Change_Cross(S_Matrix* M,CrossList*& C){
    //先统计非零元素个数
    int count = 0;
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            if(M->data[i][j] != 0){
                count++;
            }
        }
    }
    C->NodeNum = count;
    C->L_col = M->col;
    C->L_row = M->row;

    
}

//稀疏矩阵转成三元组之后转置
void Tri_trans(Triplets* T,Triplets*& Tb){
    Tb->count = T->count;
    for(int i=0;i<Tb->count;i++){
        Tb->arr[i].row = T->arr[i].col;
        Tb->arr[i].col = T->arr[i].row;
        Tb->arr[i].data = T->arr[i].data;
    }
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
    Triplets *T,*Tb;
    Init_Tri(T);
    Init_Tri(Tb);
    Change_Tri(M,T);
    cout<<"存储为三元组："<<endl;
    Print_Triplets(T);
    Tri_trans(T,Tb);
    cout<<"稀疏矩阵转置后的三元组："<<endl;
    Print_Triplets(Tb);

    S_Matrix* Mb;
    Init_Matrix(Mb);
    Mb->col = M->row;
    Mb->row = M->col;
    for(int i=0;i<Tb->count;i++){
        Mb->data[Tb->arr[i].row][Tb->arr[i].col] = Tb->arr[i].data;
    }
    cout<<"转置后的稀疏矩阵："<<endl;
    for(int i=0;i<Mb->col;i++){
        for(int j=0;j<Mb->row;j++){
            cout<<Mb->data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}