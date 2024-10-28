#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAXSIZE 50


//双链表结点结构体
typedef struct DNode{
    int data; //数据域
    DNode* pre; //前驱指针
    DNode* next; //后继指针
}*DLinkList; //定义双链表

//双链表初始化
bool InitList(DLinkList& L){
    L = new DNode;
    if(!L){
        cout<<"申请失败！"<<endl;
        return false;
    }
    else{
        L->next = NULL;
        L->pre = NULL;
        return true;
    }
}

//打印双链表
bool Print(DLinkList& L){
    //空链表的情况
    if(L->next == NULL){
        cout<<"双链表不存在！"<<endl;
        return false;
    }
    DNode* p = L->next;
    while(p){
        cout<<p->data<<" ";//打印数据域
        p = p->next; //工作指针向后移动
    }
    cout<<endl;
    return true;
}

//获取双链表长度
int get_length(DLinkList L){
    DNode* p = L->next; //申请一个新的工作结点
    int len; //保存长度
    while(p){
        len++;
        p = p->next;//向后移动
    }
    cout<<endl;
    return len;
}

//头插法创建双链表
bool Insert_head(DLinkList& L){
    int x;
    cout<<"请输入元素个数：";
    cin>>x;
    if(x<=0){
        cout<<"输入无意义"<<endl;
        return false;
    }
    cout<<"请依次输入元素的值："<<endl;
    while(x){
        DNode* p = new DNode; //申请一个新结点
        cin>>p->data; //输入数据
        p->next = L->next; //新节点的next是L的next
        p->pre = L; //新节点的pre是L
        L->next = p; //更新L的next
        x--;
    }
    cout<<"采用头插法创建双向链表为：";
    Print(L); //打印
    return true;
}

//尾插法创建双链表
bool Insert_tail(DLinkList& L){
    DNode* p = new DNode;//申请一个新节点
    InitList(p); //初始化新节点
    L = p;
    int x;
    cout<<"请输入元素个数：";
    cin>>x;
    cout<<"请以此输入元素的值："<<endl;
    while(x){
        DNode* r = new DNode;
        InitList(r);
        cin>>r->data;
        p->next = r;
        r->pre = p;
        p = p->next;//头结点向后移动
        x--;
    }
    cout<<"采用尾插法创建双链表结果为：";
    Print(L); //打印
    return true;
}

//中间插入(指定位置插入)
bool Insert(DLinkList& L){
    int x;
    cout<<"请输入要插入的位置：";
    cin>>x;
    if(x<1 || x>get_length(L)){
        cout<<"位置不合法！"<<endl;
        return false;
    }
    
    int value;
    cout<<"请输入要插入的值：";
    cin>>value;
    DNode* p = L;
    DNode* r;
    InitList(r);
    while(x){
        if(x==1){
            r->data = value;//数据保存到新结点中
            r->next = p->next;
            p->next->pre = r;
            r->pre = p;
            p->next = r;
            cout<<"插入新节点后的新链表为：";
            Print(L);
        }
        else{
            p = p->next;   
        } 
        x--;   
    }
    return true;
}

//按值查找
bool get_value(DLinkList& L){
    DNode* p = L->next;
    int x;
    cout<<"请输入要查找的值：";
    cin>>x;
    while(p){
        if(p->data == x){
            cout<<"您要查找的值"<<x<<"存在"<<endl;
            return true;
        }
        p = p->next;
    }
    cout<<"要查找的值不存在！"<<endl;
    return false;
}

//按序查找
bool get_bit(DLinkList& L){
    DNode* p = L->next;
    int x;
    cout<<"请输入要查找的位：";
    cin>>x;
    int len = get_length(L);
    if(x<1 || x>len){
        cout<<"位置不合法！"<<endl;
        return false;
    }
    else{
        while(p){
            x--;
            p = p->next;
            if(x==1){
                cout<<"查找成功！数据为："<<p->data<<endl;
                return true;
            }
        }
    }
}

//删除节点
bool Delete(DLinkList& L){
    int x;
    cout<<"请输入想要删除的结点：";
    cin>>x;
    if(x<1 || x>get_length(L)){
        cout<<"位置不合法！"<<endl;
        return false;
    }
    else{
        DNode* p = L;
        DNode* r;
        InitList(r);
        while(x){
            if(x==1){
                r->next = p->next;//新节点指向要删除的结点
                p->next->pre = r;//要删除的结点的前驱指针指向新节点
                p->next = r->next->next;//跨过要删除的结点
                free(r);
                cout<<"删除成功！"<<endl;
                cout<<"删除后的双链表为：";
                Print(L);//打印
                return true;
            }
            p = p->next;//向后移动
            x--;
        }
        return false;
    }
}

int main(){
    DLinkList L;
    InitList(L);
    Insert_head(L);
    Insert_tail(L);
    Insert(L);
    get_value(L);
    get_bit(L);
    Delete(L);
}