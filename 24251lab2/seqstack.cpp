#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

//顺序栈结构体
typedef struct{
    ElemType data[MaxSize]; //数组存放数据
    int top; //栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack*& s){
    s = (SqStack*)malloc(sizeof(SqStack));//分配空间，s指向栈地址
    s->top = -1; //栈顶指针为-1时表示栈为空
}

//销毁栈
void DestroyStack(SqStack*& s){
    free(s); //释放指针s
}

//判断栈是否为空
bool isEmpty(SqStack* s){
    return(s->top == -1);
}

//入栈
bool Push(SqStack*& s,ElemType e){
    if(s->top == MaxSize-1){
        cout<<"栈满"<<endl;
        return false;
    }
    else{
        s->top++;//先把栈顶指针上移一位
        s->data[s->top] = e;//存入数据
        return true;
    }
}

//出栈
bool Pop(SqStack*& s,ElemType &e){
    if(s->top == -1){
        cout<<"栈空"<<endl;
        return false;
    }
    else{
        e = s->data[s->top];//把要出栈的存入e
        s->top--;//栈顶指针下移一位
        return true;
    }
}

//取栈顶指针
ElemType GetTop(SqStack* s){
    if(s->top == -1){
        cout<<"栈空"<<endl;
        return -1;
    }
    else{
        return s->data[s->top];
    }
}

//打印
void Print(SqStack* s){
    if(s->top == -1){
        cout<<"栈空"<<endl;
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
    cout<<"出栈的数据为："<<e<<endl;

    ElemType ans = GetTop(s);
    cout<<"栈顶元素为："<<ans<<endl;

    Print(s);
}