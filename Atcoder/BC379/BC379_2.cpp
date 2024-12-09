#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int K,N; //一共N个牙齿，需要用连续K个
    cin>>N>>K;
    string T; //字符串表示全部的牙齿状况
    cin>>T;
    
    int ans = 0;
    string cmp = string(K,'O');//构造一个模式串，用于连续匹配
    for(int i=0;i<N-K+1;i++){
        if(T.substr(i,K) == cmp){
            ans++; //连续K个匹配成功
            for(int j=i;j<i+K;j++){//使用过的位置全部置为X
                T[j] = 'X';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}