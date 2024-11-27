#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s,ans;
    cin>>s;
    s+='.'; //特殊操作，针对最后一位在存储过程中没被放进去，单独设置一个'.'
    int now=s[0],num=0;
    vector<pair<int,int>>v;

    for(int i=0;i<s.size();i++){
        if(s[i] == now)num++;
        else{
            v.push_back({now-'0',num});
            now = s[i],num=1;
        }
    }

    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first == 1){
            count++;
            if(count==k){
                swap(v[i],v[i-1]);
            }
        }
    }

    for(auto x:v){
        for(int i=0;i<x.second;i++){
            cout<<x.first;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}