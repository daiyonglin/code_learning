#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    vector<int>v;
    for(int i=0;i<n;i++){
        if(s[i] == '/')v.push_back(i);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}