#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    map<char,int>mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    if(mp['1']==1 && mp['2']==2 && mp['3']==3){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}