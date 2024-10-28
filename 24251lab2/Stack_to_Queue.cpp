#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//链栈及结点结构体
typedef struct LinkNode{
    ElemType data; //数据域
    struct LinkNode* next; //指针域
}LinkStack;

//初始化
void InitStack(LinkStack*& s){
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->next = NULL;//头结点指针域设置为NULL
}

//入栈
void Push(LinkStack*& s, ElemType e){
    LinkNode* p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = s->next; 
    s->next = p;
}

//出栈
ElemType Pop(LinkStack*& s){
    LinkNode* p;
    if(s->next == NULL){
        cout<<"鏍堢┖"<<endl;
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

//入队
void enqueue(LinkStack* s1,LinkStack* s2,int data){
    Push(s1,data);
}
//出队
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

    cout<<"出队元素为："<<dequeue(s1,s2)<<endl;
    cout<<"出队元素为："<<dequeue(s1,s2)<<endl;

    enqueue(s1,s2,4);
    cout<<"出队元素为："<<dequeue(s1,s2)<<endl;
    cout<<"出队元素为："<<dequeue(s1,s2)<<endl;

    return 0;
}