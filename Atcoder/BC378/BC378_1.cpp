#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    vector<int> a(4);
    map<int,int>mp;

    for(int i=0;i<4;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    int ans=0;
    for(int i=1;i<=4;i++){
        ans+=mp[i]/2;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}