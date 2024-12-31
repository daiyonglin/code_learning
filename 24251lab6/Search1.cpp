#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef struct LNode{
    int data[MAXSIZE];
    int len;
}LNode,*List;

List InitList(){
    List arr;
    arr = (List)malloc(sizeof(LNode));
    arr->len = 0;
    return arr;
}

int Sq_Search(List arr,int target){
    int i;
    arr->data[0] = target;
    for(i=arr->len;arr->data[i]!=target;i--);
    return i;
}

int main(){
    List arr;
    arr = InitList();
    cout<<"输入有序表元素：";
    do{
        cin>>arr->data[arr->len+1];
        arr->len++;
        if(getchar()=='\n')
            break;
    }while(1);

    int num;
    cout<<"要查找的元素个数为：";
    cin>>num;
    while(num--){
        int target;
        cout<<"输入要查找的元素：";
        cin>>target;
        int pos = Sq_Search(arr,target);
        if(pos == 0){
            cout<<"元素"<<target<<"不在表中，查找失败"<<endl;
        }
        else{
            cout<<"元素"<<target<<"在表中第"<<pos<<"个位置上"<<endl;
        }
    }
    free(arr);
    return 0;
}