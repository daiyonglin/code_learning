#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define Max 100

int arr[Max]={0};
void solve(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int now=0,temp=1,ans=1;
    while(temp < n){
        if((arr[temp]-arr[now]) < c){
            temp++;
        }
        else{
            ans++;
            now = temp;
            temp++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}