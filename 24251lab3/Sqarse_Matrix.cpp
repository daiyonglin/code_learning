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
//ʮ������ ���ṹ��
typedef struct Node{
    int row,col,data; //�С��С�����
    Node *down; //��һ����ָ���µ�ָ��
    Node *right; //��һ����ָ���ұߵ�ָ��
}Node;
//ʮ������ṹ��
typedef struct{
    int L_row,L_col,NodeNum;//��������������������Ԫ�ظ���
    Node **RowHead,**ColHead;//�к�������ͷָ������
}CrossList;

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
//��ʼ��ʮ������
void Init_CrossList(CrossList*& C,int rows,int cols,int num_of_nonZero){
    C = (CrossList*)malloc(sizeof(CrossList));
    C->L_row = rows;//����
    C->L_col = cols;//����
    C->NodeNum = num_of_nonZero;//����Ԫ�ظ���

    //Ϊ�к�������ͷ�����ڴ�
    C->RowHead = new Node*[rows];
    C->ColHead = new Node*[cols];

    //��ʼ��ָ��
    for(int i=0;i<rows;i++){
        C->RowHead[i] = nullptr;
    }
    for(int i=0;i<cols;i++){
        C->ColHead[i] = nullptr;
    }
}

//ϡ�����תΪ��Ԫ��
void Change_Tri(S_Matrix*M,Triplets*& T){
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

//��ϡ������ʮ�������в���Ԫ��
void InsertElem(CrossList*& C,int row,int col,int value){
    Node* newNode = new Node{row,col,value,nullptr};
    //���뵽��������
    if(C->RowHead[row] == nullptr || C->RowHead[row]->col > col){//��ǰ��û�н������н����кű�Ҫ����Ĵ�
        newNode->right = C->RowHead[row];//�½����ָ���������н��
        C->RowHead[row] = newNode;//������ͷ���
    }
    else{//��Ϊ���Ҵ���С�ģ���ô��Ҫ�����ҵ���ȷλ�ò���
        Node* temp = C->RowHead[row];
        while(temp->right != nullptr && temp->right->col <col){
            temp = temp->right;
        }
        newNode->right = temp->right;
        temp->right = newNode;
    }

    //���뵽��������
    if (C->ColHead[col] == nullptr || C->ColHead[col]->row > row) {
        newNode->down = C->ColHead[col];
        C->ColHead[col] = newNode;
    } else {
        Node* temp = C->ColHead[col];
        while (temp->down != nullptr && temp->down->row < row) {
            temp = temp->down;
        }
        newNode->down = temp->down;
        temp->down = newNode;
    }
}

//��ϡ�������ʮ������
void Matrix_to_CrossList(CrossList*&C,S_Matrix*M){
    for(int i=0;i<C->L_row;i++){
        for(int j=0;j<C->L_col;j++){
            if(M->data[i][j]!=0){
                InsertElem(C,i,j,M->data[i][j]);
            }
        }
    }
}

//ϡ�����ת����Ԫ��֮��ת��
void Tri_trans(Triplets* T,Triplets*& Tb){
    Tb->count = T->count;
    for(int i=0;i<Tb->count;i++){
        Tb->arr[i].row = T->arr[i].col;
        Tb->arr[i].col = T->arr[i].row;
        Tb->arr[i].data = T->arr[i].data;
    }
}
//��ӡ��Ԫ��
void Print_Triplets(Triplets* T){
    for(int i=0;i<T->count;i++){
        cout<<"{"<<T->arr[i].row<<","<<T->arr[i].col<<","<<T->arr[i].data<<"}"<<endl;
    }
}
//��ӡʮ�������ʾ��ϡ�����
void Print_CrossList(const CrossList* C){
    for(int i=0;i<C->L_row;i++){
        Node* temp = C->RowHead[i];
        for(int j=0;j<C->L_col;j++){
            if(temp != nullptr &&temp->col == j){
                cout<<temp->data<<" ";
                temp = temp->right;
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
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

    int nonZero = 0;//����Ԫ�ظ���
    cout<<"ϡ�����Ϊ��"<<endl;
    for(int i=0;i<M->row;i++){
        for(int j=0;j<M->col;j++){
            cout<<M->data[i][j]<<" ";
            if(M->data[i][j]!=0){
                nonZero++;
            }
        }
        cout<<endl;
    }
    Triplets *T,*Tb;
    Init_Tri(T);
    Init_Tri(Tb);
    Change_Tri(M,T);
    cout<<"�洢Ϊ��Ԫ�飺"<<endl;
    Print_Triplets(T);
    Tri_trans(T,Tb);
    cout<<"ϡ�����ת�ú����Ԫ�飺"<<endl;
    Print_Triplets(Tb);

    CrossList* C;
    Init_CrossList(C,M->row,M->col,nonZero);
    Matrix_to_CrossList(C,M);
    cout<<"�洢Ϊʮ�������ϡ�����(������ʽ)"<<endl;
    Print_CrossList(C);

    S_Matrix* Mb;
    Init_Matrix(Mb);
    Mb->col = M->row;
    Mb->row = M->col;
    for(int i=0;i<Tb->count;i++){
        Mb->data[Tb->arr[i].row][Tb->arr[i].col] = Tb->arr[i].data;
    }
    cout<<"ת�ú��ϡ�����"<<endl;
    for(int i=0;i<Mb->col;i++){
        for(int j=0;j<Mb->row;j++){
            cout<<Mb->data[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}