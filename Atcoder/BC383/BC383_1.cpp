#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int water=0;
void solve(){
    int n;
    cin>>n;
    int Delete[100]={0},time[100],plus[100];
    for(int i=0;i<n;i++){
        cin>>time[i]>>plus[i];
    }
    for(int i=0;i<n-1;i++){
        Delete[i]=time[i+1]-time[i];
    }
    for(int i=0;i<n;i++){
        water+=plus[i];
        water-=Delete[i];
        if(water < 0)water=0;
    }
    cout<<water;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}