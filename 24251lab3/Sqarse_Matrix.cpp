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
    Node *down; //在一列上指向下的指针
    Node *right; //在一行上指向右边的指针
}Node;
//十字链表结构体
typedef struct{
    int L_row,L_col,NodeNum;//矩阵行数、列数、非零元素个数
    Node **RowHead,**ColHead;//行和列链表头指针向量
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
void Init_CrossList(CrossList*& C,int rows,int cols,int num_of_nonZero){
    C = (CrossList*)malloc(sizeof(CrossList));
    C->L_row = rows;//行数
    C->L_col = cols;//列数
    C->NodeNum = num_of_nonZero;//非零元素个数

    //为行和列链表头分配内存
    C->RowHead = new Node*[rows];
    C->ColHead = new Node*[cols];

    //初始化指针
    for(int i=0;i<rows;i++){
        C->RowHead[i] = nullptr;
    }
    for(int i=0;i<cols;i++){
        C->ColHead[i] = nullptr;
    }
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

//向稀疏矩阵的十字链表中插入元素
void InsertElem(CrossList*& C,int row,int col,int value){
    Node* newNode = new Node{row,col,value,nullptr};
    //插入到行链表中
    if(C->RowHead[row] == nullptr || C->RowHead[row]->col > col){//当前行没有结点或已有结点的列号比要插入的大
        newNode->right = C->RowHead[row];//新结点右指针连接已有结点
        C->RowHead[row] = newNode;//连接行头结点
    }
    else{//不为空且存在小的，那么需要遍历找到正确位置插入
        Node* temp = C->RowHead[row];
        while(temp->right != nullptr && temp->right->col <col){
            temp = temp->right;
        }
        newNode->right = temp->right;
        temp->right = newNode;
    }

    //插入到列链表中
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

//将稀疏矩阵传入十字链表
void Matrix_to_CrossList(CrossList*&C,S_Matrix*M){
    for(int i=0;i<C->L_row;i++){
        for(int j=0;j<C->L_col;j++){
            if(M->data[i][j]!=0){
                InsertElem(C,i,j,M->data[i][j]);
            }
        }
    }
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
//打印十字链表表示的稀疏矩阵
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

    int nonZero = 0;//非零元素个数
    cout<<"稀疏矩阵为："<<endl;
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
    cout<<"存储为三元组："<<endl;
    Print_Triplets(T);
    Tri_trans(T,Tb);
    cout<<"稀疏矩阵转置后的三元组："<<endl;
    Print_Triplets(Tb);

    CrossList* C;
    Init_CrossList(C,M->row,M->col,nonZero);
    Matrix_to_CrossList(C,M);
    cout<<"存储为十字链表后稀疏矩阵：(矩阵形式)"<<endl;
    Print_CrossList(C);

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