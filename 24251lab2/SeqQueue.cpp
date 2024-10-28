#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;
#define MaxSize 100

//˳����нṹ�嶨��
typedef struct{
    ElemType data[MaxSize]; //����������
    int front,rear; //��ͷ�Ͷ�βָ��
}SeqQueue;

//��ʼ������
void InitQueue(SeqQueue*& q){
    q = (SeqQueue*)malloc(sizeof(SeqQueue));
    q->front = q->rear = -1;
}

//���ٶ���
void DestroyQueue(SeqQueue*& q){
    free(q);
}

//�ж϶����Ƿ�Ϊ��
bool isEmpty(SeqQueue* q){
    return (q->front == q->rear);
}

//����
bool enQueue(SeqQueue*& q,ElemType e){
    if(q->rear == MaxSize-1){
        cout<<"����"<<endl;
        return false;
    }
    else{
        q->rear++;
        q->data[q->rear] = e;
        return true;
    }
}

//����
bool deQueue(SeqQueue*& q,ElemType &e){
    if(q->front == q->rear){
        cout<<"�ӿ�"<<endl;
        return false;
    }
    else{
        q->front++;
        e = q->data[q->front];
        return true;
    }
}

//���ض�ͷԪ��
ElemType GetTop(SeqQueue* q){
    if(q->front == q->rear){
        cout<<"�ӿ�"<<endl;
        return false;
    }
    else{
        return q->data[0];
    }
}

//�������
bool Print(SeqQueue* q){
    if(q->front == q->rear){
        cout<<"�ӿ�"<<endl;
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
    cout<<"��ͷԪ��Ϊ��"<<top<<endl;

    int e;
    deQueue(q,e);
    cout<<"���ӵ�Ԫ��Ϊ��"<<e<<endl;

    Print(q);
}