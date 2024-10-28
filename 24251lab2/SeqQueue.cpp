#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;
#define MaxSize 100

//顺序队列结构体定义
typedef struct{
    ElemType data[MaxSize]; //数组存放数据
    int front,rear; //队头和队尾指针
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue*& q){
    q = (SeqQueue*)malloc(sizeof(SeqQueue));
    q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(SeqQueue*& q){
    free(q);
}

//判断队列是否为空
bool isEmpty(SeqQueue* q){
    return (q->front == q->rear);
}

//进队
bool enQueue(SeqQueue*& q,ElemType e){
    if(q->rear == MaxSize-1){
        cout<<"队满"<<endl;
        return false;
    }
    else{
        q->rear++;
        q->data[q->rear] = e;
        return true;
    }
}

//出队
bool deQueue(SeqQueue*& q,ElemType &e){
    if(q->front == q->rear){
        cout<<"队空"<<endl;
        return false;
    }
    else{
        q->front++;
        e = q->data[q->front];
        return true;
    }
}

//返回队头元素
ElemType GetTop(SeqQueue* q){
    if(q->front == q->rear){
        cout<<"队空"<<endl;
        return false;
    }
    else{
        return q->data[0];
    }
}

//输出队列
bool Print(SeqQueue* q){
    if(q->front == q->rear){
        cout<<"队空"<<endl;
        return false;
    }
    else{
        q->front++;
        while(q->front != q->rear){
            cout<<q->data[q->front]<<" ";
            q->front++;
        }
        cout<<q->data[q->rear];
        cout<<endl;
        return true;
    }
}

int main(){
    SeqQueue* q;
    InitQueue(q);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);

    int top;
    top = GetTop(q);
    cout<<"队头元素为："<<top<<endl;

    int e;
    deQueue(q,e);
    cout<<"出队的元素为："<<e<<endl;

    Print(q);
}