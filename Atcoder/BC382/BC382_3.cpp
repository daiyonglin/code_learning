#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<m;i++){
        b[i]=-1;
    }
    int ptr_a=0,ptr_b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    while(ptr_b<m){
        while(ptr_a<n){
            if(b[ptr_b]>=a[ptr_a]){
                b[ptr_b]=ptr_a+1;
                ptr_a=0;
                break;
            }
            else{
                ptr_a++;
            }
            if(ptr_a==n-1 && b[ptr_b]<a[ptr_a]){
            b[ptr_b]=-1;
        }
        }
        ptr_b++;    
    }
    for(int i=0;i<m;i++){
        cout<<b[i]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}