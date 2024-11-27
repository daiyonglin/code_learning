#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    vector<int>v,ans;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='|'){
            v.push_back(i);
        }
    }
    for(int j=0;j<v.size();j++){
        ans.push_back(v[j+1]-v[j]-1);
    }
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}