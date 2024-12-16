#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int D1(int S,int plus){
    if(S>=1600 && S<=2799){
        return S+plus;
    }
    else{
        return S;
    }
}
int D2(int S,int plus){
    if(S>=1200 && S<=2399){
        return S+plus;
    }
    else{
        return S;
    }
}
vector<pair<int,int>> ARCs;
void solve(){
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++){
        int D,Score;
        cin>>D>>Score;
        ARCs.push_back(make_pair(D,Score));
    }

    int rec = r;
    for(int i=0;i<n;i++){
        if(ARCs[i].first == 1){
            rec = D1(rec,ARCs[i].second);
        }
        else{
            rec = D2(rec,ARCs[i].second);
        }
    }
    cout<<rec<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}