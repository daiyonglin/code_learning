#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string input;
    cout<<"请输入字符串：";
    getline(cin,input);
    int count[256]={0}; //记录字符出现次数
    string order; //记录字符出现顺序
    for(char c:input){//对于input中的每个字符c执行一次循环
        if(count[c] == 0){
            //如果字符是第一次出现，记录到顺序中
            order += c;
        }
        count[c]++;
    }

    for(char c: order){
        cout<<c<<" "<<count[c]<<endl;
    }
    return 0;
}