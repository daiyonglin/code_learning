#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAXSIZE 200000
void solve(){
    long long  n,s,sum=0;
    cin>>n>>s;
    int a[MAXSIZE];
    map<long long,int>rec; //前缀和是否出现过
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        rec[sum]=1;//sum前缀和出现过，置为1
    }
    rec[0]=1;//前缀和当然有0
    s %= sum;
    long long suf =0;
    for(int i=n;i>=0;i--){
        suf+=a[i];
        if(rec.count(s-suf) != 0 || rec.count(s-suf+sum)){
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}