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
    cout<<"���������Ԫ�أ�";
    do{
        cin>>arr->data[arr->len+1];
        arr->len++;
        if(getchar()=='\n')
            break;
    }while(1);

    int num;
    cout<<"Ҫ���ҵ�Ԫ�ظ���Ϊ��";
    cin>>num;
    while(num--){
        int target;
        cout<<"����Ҫ���ҵ�Ԫ�أ�";
        cin>>target;
        int pos = Sq_Search(arr,target);
        if(pos == 0){
            cout<<"Ԫ��"<<target<<"���ڱ��У�����ʧ��"<<endl;
        }
        else{
            cout<<"Ԫ��"<<target<<"�ڱ��е�"<<pos<<"��λ����"<<endl;
        }
    }
    free(arr);
    return 0;
}