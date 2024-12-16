#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int n;
    char c1,c2;
    cin>>n>>c1>>c2;

    string s;
    cin>>s;

    for(int i=0;i<n;i++){
        if(s[i] != c1)s[i] = c2;
    }
    cout<<s<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}