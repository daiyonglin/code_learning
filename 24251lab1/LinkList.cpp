#include<iostream>
#include<cassert>
#include<string>

using namespace std;

//单链表结点结构体定义
typedef struct Node{
    int data; //数据域
    Node* next;//指针域
}LNode;
typedef LNode* LinkList;//LinkList表示一个单链表

/*1、初始化单链表的结点*/
bool InitList(LinkList& L){
    L = new LNode;
    if(!L){
        cout<<"创建结点失败"<<endl;
        return false;
    }
    L->next = NULL; //新结点指针指向NULL
    return true; //创建成功
}

/*2、打印单链表*/
bool PrintList(LinkList& L){
    LNode* p = L->next; //工作指针P，直接指向第一个结点
    if(p == NULL){
        return false;//链表是空的，不打印
    }
    while(p){
        cout<<p->data<<" "; //打印结点的数据
        p = p->next; //工作指针移动到下一个结点
    }
    return true;
}

/*3、创建单链表*/

//头插法
bool Insert_List_head(LinkList& L){
    InitList(L);//初始化链表结点

    int e; //元素个数
    cout<<"头插法创建单链表，输入元素个数："<<endl;
    cin>>e;
    //检查e合法
    if(e<=0){
        cout<<"输入错误，无法创建"<<endl;
        return false;
    }
    cout<<"依次输入数据："<<endl;

    while(e){
        LNode* s = new LNode; //创建一个新结点
        cin>>s->data; //输入
        s->next = L->next; //新结点指针指向第一个结点（头结点原来指向的那个）
        L->next = s; //头结点指向新结点
        e--; 
    }

    cout<<"采用头插法创建的单链表"<<endl;
    PrintList(L); //打印一下
    cout<<endl;
    return true;
}

//尾插法
bool Insert_List_tail(LinkList& L){
    InitList(L);
    LNode* p = new LNode;//申请新节点（也是后面用的工作结点）
    InitList(p); //初始化新结点
    L->next = p; //头结点指向新节点；

    int e; //元素个数
    cout<<"尾插法创建单链表，输入元素个数："<<endl;
    cin>>e;
    //检查e合法
    if(e<=0){
        cout<<"输入错误，无法创建"<<endl;
        return false;
    }
    cout<<"依次输入数据："<<endl;
    cin>>p->data; //已创建的新结点需要给一个值

    while(e-1){//第一个结点的值已经赋过了
        LNode* r = new LNode; //申请新结点
        InitList(r); //初始化结点
        cin>>r->data; //赋值
        p->next = r; //连上新的结点
        p = r;//工作节点向后转移到尾结点
        e--;
    }
    cout<<"采用尾插法创建单链表"<<endl;
    PrintList(L);
    cout<<endl;
    return true;
}

/*5、求单链表长度*/
int Length(LinkList& L){
    LNode* p = L->next; //申请新结点
    int length = 0; //长度
    while(p){
        length++;
        p = p->next; //往后移动
    }
    cout<<endl;
    return length;
}

/*4、插入结点*/
bool Insert(LinkList& L){
    LNode* p = L;
    LNode* q; //两个工作结点
    InitList(q);

    int x;
    cout<<"输入要插入的位数"<<endl;
    cin>>x;
    if(x > Length(L)){
        cout<<"错误"<<endl;
        return false;
    }
    cout<<"输入要插入的数据："<<endl;
    cin>>q->data;
    while(x){
        if(x==1){
            q->next = p->next;
            p->next = q;
            PrintList(L);
            cout<<endl;
            return true;
        }
        x--;//第x位移动了x-1次
         p = p->next;
    }
}

/*5、求单链表长度*/
/* int Length(LinkList& L){
    LNode* p = L->next; //申请新结点
    int length = 0; //长度
    while(p){
        length++;
        p = p->next; //往后移动
    }
    cout<<endl;
    return length;
} */

/*6、查找*/
//按值查找
bool get_elem_value(LinkList& L){
    LNode* p = L->next;
    int x;
    cout<<"输入要查找的值"<<endl;
    cin>>x;
    while(p){
        if(p->data == x){
            cout<<"查找成功"<<endl;
            return true;
        }
        else{
            p = p->next;
        }
    }
    cout<<"查找失败"<<endl;
    return false;
}

//按位查找
bool get_elem_bit(LinkList& L){
    LNode* p = L->next;
    int x;
    cout<<"输入要查找的位：";
    cin>>x;
    //两个合法性检查
    int t = Length(L);
    if(x>t){
        cout<<"该位不存在"<<endl;
        return false;
    }
    else if(x < 0){
        cout<<"该位不合法"<<endl;
        return false;
    }

    else{
        while(x){
            x--;
            p = p->next;
            if(x==1){
                cout<<"要查找位置的数据为："<<p->data<<endl;
            }
        }
        return true;
    }
}

/*7、删除结点*/
bool Delete(LinkList& L){
    int n;
    LNode* p = L;
    LNode* r;
    InitList(r);
    cout<<"输入要删除的结点:";
    cin>>n;

    if(n<1 || n>Length(L)){
        cout<<"不合法"<<endl;
        return false;
    }
    else{
        while(n){
            if(n==1){
                r->next = p->next;//工作结点指向要删除的结点
                p->next = r->next->next;//原结点指向待删除结点的下一个结点
                free(r);//释放新节点
                cout<<"删除成功"<<endl;
                PrintList(L);
                return true;
            }
            n--;
            p = p->next;
        }
    }
}

/*8、链表倒置*/
void Reserve(LinkList& L){
    assert(L != NULL);
    if(L == NULL){return;}
    if(Length(L) <= 1){return;}
    LNode* p = L->next;
    LNode* q = p->next;
    LNode* r = q->next;
    p->next = NULL;
    while(r != NULL){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    L->next = q;
}

int main(){
    LinkList L; //单链表L
    InitList(L); //初始化
    Insert_List_tail(L); //尾插法添加数据
    Reserve(L);
    cout<<"倒置后结果："<<endl;
    PrintList(L);
    /*
    Insert_List_head(L); //头插法添加数据
    cout<<"链表长度为"<<Length(L)<<endl; //输出长度
    get_elem_value(L); //按值查找
    get_elem_bit(L); //按位查找
    Insert(L); //插入结点
    Delete(L); //删除结点
    */
}