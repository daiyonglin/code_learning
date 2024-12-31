#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAXSIZE 1000
typedef struct LNode{
    int data[MAXSIZE];
    int len;
}LNode,*List;

List Init_List(){
    List L;
    L = (List)malloc(sizeof(LNode));
    L->len=0;
    return L;
}   

pair<int,int> Binary_Search(List L,int target){
    int cnt=0;//�ȽϹؼ��ִ���
    int low=0,high=L->len,mid;
    while(low<=high){
        mid = (low+high)/2;
        if(target < L->data[mid]){
            high = mid-1;
            cnt++;
        }
        else if(target > L->data[mid]){
            low = mid+1;
            cnt++;
        }
        else{
            return {mid,cnt};
        }
    }
    return {-1,cnt};
}
int main(){
    List L;
    L = Init_List();
    cout<<"�����������Ԫ�أ�";
    do{
        cin>>L->data[L->len+1];
        L->len++;
        if(getchar()=='\n'){
            break;
        }
    }while(1);

    int times;
    cout<<"���������Ԫ�ظ�����";
    cin>>times;
    while(times--){
        int target;
        cout<<"������Ҫ���ҵ�Ԫ�أ�";
        cin>>target;
        int pos = Binary_Search(L,target).first;
        if(pos == -1){
            cout<<"��Ԫ�ز���˳�����"<<endl;
            cout<<"�ȽϹؼ��ִ�����"<<Binary_Search(L,target).second-1<<endl;
        }
        else{
            cout<<"Ԫ��"<<target<<"�ڱ��е�"<<pos<<"��λ����"<<endl;
            cout<<"�ȽϹؼ��ִ�����"<<Binary_Search(L,target).second<<endl;
        }
    }
    free(L);
    return 0;
}