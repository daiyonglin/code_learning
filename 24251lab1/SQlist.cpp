#include<iostream>
#include "SQlist.h"
#define MAXSIZE 255
using namespace std;

//初始化表，构造一个空的顺序表
void InitList(SqList& L) {
    //初始化数据元素，全部设为0
    for (int i = 0; i < MAXSIZE; i++) {
        L.data[i] = 0;
    }
    //初始化表长为0
    L.length = 0;
}

//求表长
int get_length(SqList L) {
    return L.length;
}


//按值查找，返回位序
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //返回位序，比下标+1
        }
    }
    return 0;//没找到，跳出
}

//按序查找
/*
    1、判断pos值是否合法：1<=pos<=L.length
    2、若合法，直接返回第pos位置元素的值
*/
ElemType get_element(SqList L, int pos) {
    if (pos<1 || pos>L.length) {
        cout << "pos值不合法" << endl;
        exit(1);//退出
    }
    else {
        return L.data[pos - 1];//注意第pos个数下标是pos-1
    }
}

//插入操作，在L中第pos个位置插入指定元素e
/*
    1、检查是否已满
    2、判断pos值是否合法，1<=pos<=L.length+1
    3、移动元素，插入新元素
    4、顺序表长度+1
*/
bool Insert(SqList& L, int pos, ElemType e) {
    if (L.length >= MAXSIZE) {
        cout << "表已满，插入失败" << endl;
        return false;
    }
    else if (pos<1 || pos>L.length) {
        cout << "pos位置不合法" << endl;
        return false;
    }
    for (int i = L.length - 1; i >= pos - 1; i--) {
        L.data[i + 1] = L.data[i];
    }
    L.data[pos - 1] = e;
    L.length++;
    return true;
}

//删除操作，删除pos处的元素，并用e返回元素
/*
    1、判断是否为空
    2、检查pos是否合法，1<=pos<=L.length
    3、先把要删除的元素存进e
    4、移动数据
    5、表长-1
*/
bool Delete(SqList& L, int pos, ElemType e) {
    if (L.length == 0) {
        cout << "表为空" << endl;
        return false;
    }
    else if (pos<1 || pos >L.length) {
        cout << "pos不合法" << endl;
        return false;
    }
    e = L.data[pos - 1];
    for (int i = pos; i < L.length; i++)
    {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}

//输出表中元素
void Print(SqList L) {
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

//计算平均值并插入
/*
    1、判断是否为空
    2、计算平均值
    3、插入中间位置
*/
void Average(SqList& L) {
    int sum = 0;
    if (L.length == 0) {
        cout << "顺序表为空" << endl;
        exit(1);
    }
    else {
        for (int i = 0; i <= L.length; i++)
        {
            sum += L.data[i];
        }
        int ans = sum / L.length;
        Insert(L, L.length / 2, ans);
    }
}

//选做题：向右移动n位
void rightShift(SqList &list, int n) {
    if (list.length == 0 || n <= 0) return; // 如果表为空或n为非正数，直接返回

    n = n % list.length; // 处理n大于length的情况
    if (n == 0) return; // 如果n为0，不需要移动

    // 创建一个临时数组
    ElemType temp[MAXSIZE];

    // 将元素移动到新数组
    for (int i = 0; i < list.length; i++) {
        temp[(i + n) % list.length] = list.data[i];
    }

    // 将新数组的内容复制回原数组
    for (int i = 0; i < list.length; i++) {
        list.data[i] = temp[i];
    }
}

int main() {
    SqList L;
    InitList(L);
    L.length = 10;
    for(int i=0;i<L.length;i++){
        L.data[i]=i;
    }
    int n;
    cout<<"输入要向右移动的位数：";
    cin>>n;
    rightShift(L,n);
    Print(L);
}