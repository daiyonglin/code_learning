#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define Max 200000
int a[Max];
int n;
int cnt[Max] = {0}; //记录[l,r)区间中每个数字出现的次数

int solve(int start_l){
    int ans=0;
    int r = start_l;
    for(int l = start_l;l<=n;l+=2){
        while(r+1<=n && a[r]==a[r+1] && cnt[a[r]==0]){
            cnt[a[r]] += 2;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    return 0;
}