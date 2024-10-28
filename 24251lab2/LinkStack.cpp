#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef int ElemType;

//链栈及其结点结构体
typedef struct LinkNode{
    ElemType data; //数据域
    struct LinkNode* next; //指针域
}LinkStack;

//初始化
void InitStack(LinkStack*& s){
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->next = NULL;
}

//销毁
void DestroyStack(LinkStack*& s){
    LinkNode *pre = s,*p = s->next;//pre指向头结点，p指向首结点
    while(p != NULL){
        free(pre); //释放最前面的结点
        pre = p;
        p = p->next; //pre和p同步向后移动
    }
    free(pre);//循环结束时还剩一个没释放
}

//判断是否为空
bool isEmpty(LinkStack* s){
    return (s->next == NULL);
}

//进栈
void Push(LinkStack*& s, ElemType e){
    LinkNode* p;//创建新结点
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    //头插法
    p->next = s->next; 
    s->next = p;
}

//出栈
bool Pop(LinkStack*& s,ElemType& e){
    LinkNode* p;
    if(s->next == NULL){
        cout<<"栈空"<<endl;
        return false;
    }
    else{
        p = s->next;
        e = p->data; //用e存放
        s->next = p->next; //删除首结点
        free(p);
        return true;
    }
}

//返回栈顶元素
ElemType GetTop(LinkStack*& s,ElemType& e){
    if(s->next == NULL){
        cout<<"栈空"<<endl;
        return -1;
    }
    else{
        e = s->next->data;
        return e;
    }
}

//输出栈中所有元素
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