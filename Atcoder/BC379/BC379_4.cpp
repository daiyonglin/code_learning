#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef long long ll;

void solve(){
    ll now = 0; //��ǰʱ��
    queue<ll> q; //����

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
            while(!q.empty() && now-q.front()>=H){//���в�Ϊ���ҳ��ȴﵽH�ģ����γ���
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