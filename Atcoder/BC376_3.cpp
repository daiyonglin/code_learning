#include<bits/stdc++.h>
#include<iostream>
using namespace std;


#define MaxN 200000
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll>A(n),B(n-1);
    ll output;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>B[i];
    }

    sort(A.begin(),A.end()); 
    sort(B.begin(),B.end());

    vector<ll>::iterator it_a = A.end()-1;
    vector<ll>::iterator it_b = B.end()-1;

    while(it_a != A.begin()-1 && it_b != B.begin()-1){       
            if(*(it_a) > *(it_b)){
                output = *(it_a);
                cnt++;
                it_a--;
            }
            else{
                it_a--;
                it_b--;
            } 
    }
    if(it_a == A.begin() && it_b == B.begin()-1){
        cout<<*(A.begin())<<endl;
    } 
    else{
        if(cnt>1){
        cout<<-1<<endl;
    }
    else{
        cout<<output<<endl;
    }
    }
        
}

    int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}