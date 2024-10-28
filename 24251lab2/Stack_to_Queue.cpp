#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//��ջ�����ṹ��
typedef struct LinkNode{
    ElemType data; //������
    struct LinkNode* next; //ָ����
}LinkStack;

//��ʼ��
void InitStack(LinkStack*& s){
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->next = NULL;//ͷ���ָ��������ΪNULL
}

//��ջ
void Push(LinkStack*& s, ElemType e){
    LinkNode* p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = s->next; 
    s->next = p;
}

//��ջ
ElemType Pop(LinkStack*& s){
    LinkNode* p;
    if(s->next == NULL){
        cout<<"栈空"<<endl;
        return -1;
    }
    else{
        ElemType e;
        p = s->next;
        e = p->data; 
        s->next = p->next; 
        free(p);
        return e;
    }
}

//���
void enqueue(LinkStack* s1,LinkStack* s2,int data){
    Push(s1,data);
}
//����
ElemType dequeue(LinkStack* s1,LinkStack* s2){
    if(s2->next == NULL){
        while(s1->next != NULL){
            Push(s2,Pop(s1));
        }
    }
    else{
        return Pop(s2);
    }
}

int main(){
    LinkStack *s1,*s2;
    InitStack(s1);
    InitStack(s2);

    enqueue(s1,s2,1);
    enqueue(s1,s2,2);
    enqueue(s1,s2,3);

    cout<<"����Ԫ��Ϊ��"<<dequeue(s1,s2)<<endl;
    cout<<"����Ԫ��Ϊ��"<<dequeue(s1,s2)<<endl;

    enqueue(s1,s2,4);
    cout<<"����Ԫ��Ϊ��"<<dequeue(s1,s2)<<endl;
    cout<<"����Ԫ��Ϊ��"<<dequeue(s1,s2)<<endl;

    return 0;
}