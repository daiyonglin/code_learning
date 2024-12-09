#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    vector<int>v;
    for(int i=0;i<n;i++){
        if(s[i] == '/')v.push_back(i);
    }
    //遍历每一个'/'的位置
    for(int j:v){
        //左边
        int count1 = 0;
        for(int i=j-1;i!=-1;i--){
            if(s[i] != '1')break;
            count1++;
        }
        //右边
        int count2 = 0;
        for(int i=j+1;i<n+1;i++){
            if(s[i] != '2')break;
            count2++;
        }
        ans = max(ans,min(count1,count2));//ans记录了一半
    }
    cout<<2*ans+1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}