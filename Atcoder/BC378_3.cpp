#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<int> a(n),b(n,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp[a[i]]){
            b[i] = mp[a[i]];
        }
        mp[a[i]] = i+1;
    }
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}