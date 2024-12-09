#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int cnt = 0;
void solve(){
    int n,d;
    cin>>n>>d;
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            cnt++;
        }
    }
    cout<<cnt+d;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}