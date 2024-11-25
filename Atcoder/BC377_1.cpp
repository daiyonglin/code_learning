#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s == "ABC"){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}