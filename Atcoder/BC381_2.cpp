#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.length();
    map<char,int>mp;
    if(n%2==1){
        cout<<"No"<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=1;i<=n/2;i++){
            if(s[2*i] != s[2*i+1]){
                cout<<"No"<<endl;
                return;
            }
        }
        for(map<char,int>::iterator it = mp.begin();it!=mp.end();it++){
            if(it->second != 2){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}