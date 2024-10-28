#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//���ӵ����ݽ��ṹ��
typedef struct qNode{
    ElemType data;
    struct qNode* next;
}DataNode;
//���ӵ�ָ���㣨ͷ��㣩�ṹ��
typedef struct{
    DataNode* front; //ָ����׽��
    DataNode* rear; //ָ���β���
}LinkNode;

//��ʼ������ͷ���
void InitQueue(LinkNode*& q){
    q = (LinkNode*)malloc(sizeof(LinkNode));
    q->front = q->rear = NULL;
}

//����
void enQueue(LinkNode*& q,ElemType e){
    DataNode* p;
    p = (DataNode*)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if(q->rear == NULL){
        //�����ʱ���ӻ��ǿյģ���ͷ�Ͷ�βָ�붼ָ��p
        q->front = q->rear = p;
    }
    else{
        q->rear->next = p;
        q->rear = p;
    }
}

//����
bool deQueue(LinkNode*& q,ElemType& e){
    DataNode* t;
    if(q->rear == NULL){
        cout<<"�ӿ�"<<endl;
        return false;
    }
    else{
        t = q->front;
        e = t->data;
        if(q->front == q->rear){
            //����ֻ��һ��Ԫ��ʱ���ı�ָ�뼴��
            q->front = q->rear =NULL;
        }
        else{
            q->front = q->front->next;
        }
        free(t);
        return true;
    }
} 

//���ض�ͷԪ��
ElemType GetTop(LinkNode* q){
    if(q->rear == NULL){
        cout<<"�ӿ�"<<endl;
        return -1;
    }
    else{
        return q->front->data;
    }
}

//�������
void Print(LinkNode* q){
    if(q->rear == NULL){
        cout<<"�ӿ�"<<endl;
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
    cout<<"��ͷԪ��Ϊ��"<<top<<endl;

    ElemType e;
    deQueue(q,e);
    cout<<"���ӵ�Ԫ��Ϊ��"<<e<<endl;

    cout<<"��ʱ����Ϊ��";
    Print(q);
}