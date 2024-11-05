#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100

//ϡ�����
typedef struct{
    int row; //��
    int col; //��
    int data[MaxSize][MaxSize]; //����
}S_Matrix;
//��Ԫ��Ԫ�ؽṹ��
typedef struct{
    int row; //��
    int col; //��
    int data; //����
}Tri_Elem;
//��Ԫ��ṹ��
typedef struct{
    int count; //Ԫ�ظ���
    Tri_Elem arr[MaxSize];
}Triplets;



//��ʼ������
void Init_Matrix(S_Matrix*& M){
    M=(S_Matrix*)malloc(sizeof(S_Matrix));
    M->row=0;
    M->col=0;
}
//��ʼ����Ԫ��
void Init_Tri(Triplets*& T){
    T = (Triplets*)malloc(sizeof(Triplets));
    T->count=0;
}

//ϡ�����תΪ��Ԫ��
void Change(S_Matrix*M,Triplets*& T){
    //��ͳ�Ʒ���Ԫ�ظ���
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
//ת��Ϊ��Ԫ���ʵ�־���ת��
void Tri_Trans(Triplets*& T){
    
}
//��ӡ��Ԫ��
void Print_Triplets(Triplets* T){
    for(int i=0;i<T->count;i++){
        cout<<"{"<<T->arr[i].row<<","<<T->arr[i].col<<","<<T->arr[i].data<<"}"<<endl;
    }
}

int main(){
    S_Matrix* M;
    Init_Matrix(M);
    cout<<"������ϡ�������У�";
    cin>>M->row;   
    cout<<"������ϡ�������У�";
    cin>>M->col;
    cout<<"����������ϡ������Ԫ��ֵ��";
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            cin>>M->data[i][j];
        }
    }
    cout<<"ϡ�����Ϊ��"<<endl;
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            cout<<M->data[i][j]<<" ";
        }
        cout<<endl;
    }
    Triplets* T;
    Init_Tri(T);
    Change(M,T);
    cout<<"�洢Ϊ��Ԫ�飺"<<endl;
    Print_Triplets(T);
    cout<<endl;
}