#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//链队的数据结点结构体
typedef struct qNode{
    ElemType data;
    struct qNode* next;
}DataNode;
//链队的指针结点（头结点）结构体
typedef struct{
    DataNode* front; //指向队首结点
    DataNode* rear; //指向队尾结点
}LinkNode;

//初始化链队头结点
void InitQueue(LinkNode*& q){
    q = (LinkNode*)malloc(sizeof(LinkNode));
    q->front = q->rear = NULL;
}

//进队
void enQueue(LinkNode*& q,ElemType e){
    DataNode* p;
    p = (DataNode*)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if(q->rear == NULL){
        //如果此时链队还是空的，队头和队尾指针都指向p
        q->front = q->rear = p;
    }
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

//出队
bool deQueue(LinkNode*& q,ElemType& e){
    DataNode* t;
    if(q->rear == NULL){
        cout<<"队空"<<endl;
        return false;
    }
    else{
        t = q->front;
        e = t->data;
        if(q->front == q->rear){
            //队中只有一个元素时，改变指针即可
            q->front = q->rear =NULL;
        }
        else{
            q->front = q->front->next;
        }
        free(t);
        return true;
    }
} 

//返回队头元素
ElemType GetTop(LinkNode* q){
    if(q->rear == NULL){
        cout<<"队空"<<endl;
        return -1;
    }
    else{
        return q->front->data;
    }
}

//输出队列
void Print(LinkNode* q){
    if(q->rear == NULL){
        cout<<"队空"<<endl;
    }
    else{
        DataNode *s;
        s = q->front;
        while(s != NULL){
            cout<<s->data<<" ";
            s = s->next;
        }
        cout<<endl;
    }
}

int main(){
    LinkNode* q;
    InitQueue(q);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);

    int top;
    top = GetTop(q);
    cout<<"队头元素为："<<top<<endl;

    ElemType e;
    deQueue(q,e);
    cout<<"出队的元素为："<<e<<endl;

    cout<<"此时队列为：";
    Print(q);
}