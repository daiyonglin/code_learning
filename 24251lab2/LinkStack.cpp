#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//��ջ������ṹ��
typedef struct LinkNode{
    ElemType data; //������
    struct LinkNode* next; //ָ����
}LinkStack;

//��ʼ��
void InitStack(LinkStack*& s){
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->next = NULL;
}

//����
void DestroyStack(LinkStack*& s){
    LinkNode *pre = s,*p = s->next;//preָ��ͷ��㣬pָ���׽��
    while(p != NULL){
        free(pre); //�ͷ���ǰ��Ľ��
        pre = p;
        p = p->next; //pre��pͬ������ƶ�
    }
    free(pre);//ѭ������ʱ��ʣһ��û�ͷ�
}

//�ж��Ƿ�Ϊ��
bool isEmpty(LinkStack* s){
    return (s->next == NULL);
}

//��ջ
void Push(LinkStack*& s, ElemType e){
    LinkNode* p;//�����½��
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    //ͷ�巨
    p->next = s->next; 
    s->next = p;
}

//��ջ
bool Pop(LinkStack*& s,ElemType& e){
    LinkNode* p;
    if(s->next == NULL){
        cout<<"ջ��"<<endl;
        return false;
    }
    else{
        p = s->next;
        e = p->data; //��e���
        s->next = p->next; //ɾ���׽��
        free(p);
        return true;
    }
}

//����ջ��Ԫ��
ElemType GetTop(LinkStack*& s,ElemType& e){
    if(s->next == NULL){
        cout<<"ջ��"<<endl;
        return -1;
    }
    else{
        e = s->next->data;
        return e;
    }
}

//���ջ������Ԫ��
void Print(LinkStack* s){
    LinkNode* p;
    p = s->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){
    LinkStack* s;
    ElemType e;
    InitStack(s);
    Push(s,1);
    Push(s,2);
    Push(s,3);
    Push(s,4);
    Push(s,5);
    Push(s,6);
    Push(s,7);
    Push(s,8);
    Push(s,9);
    Push(s,10);

    Print(s);
    Pop(s,e);
    cout<<e<<endl;

    ElemType ans;

    ans = GetTop(s,ans);
    cout<<ans<<endl;
}