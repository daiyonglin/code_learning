#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

//˳��ջ�ṹ��
typedef struct{
    ElemType data[MaxSize]; //����������
    int top; //ջ��ָ��
}SqStack;

//��ʼ��ջ
void InitStack(SqStack*& s){
    s = (SqStack*)malloc(sizeof(SqStack));//����ռ䣬sָ��ջ��ַ
    s->top = -1; //ջ��ָ��Ϊ-1ʱ��ʾջΪ��
}

//����ջ
void DestroyStack(SqStack*& s){
    free(s); //�ͷ�ָ��s
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(SqStack* s){
    return(s->top == -1);
}

//��ջ
bool Push(SqStack*& s,ElemType e){
    if(s->top == MaxSize-1){
        cout<<"ջ��"<<endl;
        return false;
    }
    else{
        s->top++;//�Ȱ�ջ��ָ������һλ
        s->data[s->top] = e;//��������
        return true;
    }
}

//��ջ
bool Pop(SqStack*& s,ElemType &e){
    if(s->top == -1){
        cout<<"ջ��"<<endl;
        return false;
    }
    else{
        e = s->data[s->top];//��Ҫ��ջ�Ĵ���e
        s->top--;//ջ��ָ������һλ
        return true;
    }
}

//ȡջ��ָ��
ElemType GetTop(SqStack* s){
    if(s->top == -1){
        cout<<"ջ��"<<endl;
        return -1;
    }
    else{
        return s->data[s->top];
    }
}

//��ӡ
void Print(SqStack* s){
    if(s->top == -1){
        cout<<"ջ��"<<endl;
    }
    else{
        while(s->top != -1){
            cout<<s->data[s->top]<<" ";
            s->top--;
        }
    }
}

int main(){
    SqStack* s;
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

    Pop(s,e);
    cout<<"��ջ������Ϊ��"<<e<<endl;

    ElemType ans = GetTop(s);
    cout<<"ջ��Ԫ��Ϊ��"<<ans<<endl;

    Print(s);
}