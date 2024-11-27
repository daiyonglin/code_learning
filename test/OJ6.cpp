#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    s+='.';
    vector<pair<int,int>>v;

    int now = s[0],num=0;
    for(int i=0;i<=n;i++){
        if(s[i]==now)num++;
        else{
            v.push_back({num,now-'0'});
            now = s[i];num=1;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<v[i].second;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}