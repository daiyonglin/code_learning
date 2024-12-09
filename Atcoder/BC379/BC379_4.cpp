#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

void solve(){
    ll now = 0; //当前时间
    queue<ll> q; //队列

    ll Q;
    cin>>Q;
    while(Q--){
        int op;
        cin>>op;
        if(op == 1){
            q.push(now);
        }
        else if(op == 2){
            int T;
            cin>>T;
            now+=T;
        }
        if(now == 3){
            int ans = 0;
            int H;cin>>H;
            while(!q.empty() && now-q.front()>=H){//队列不为空且长度达到H的，依次出队
                ans++;
                q.pop();
            }
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}