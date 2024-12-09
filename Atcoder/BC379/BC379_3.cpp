#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int maxn = 2e6 + 5;
typedef long long ll;

pair<ll,ll> a[maxn]; //pair类型的数组
void solve(){
    int n,m;
    cin>>n>>m; //n为空位总数，m为初始有石头的空位数(供应堆数量)

    ll sum = 0; //石头总数
    for(int i=1;i<=m;i++)cin>>a[i].first; //输入pair的键
    for(int i=1;i<=m;i++)cin>>a[i].second,sum+=a[i].second;//输入pair的值，同时求总数
    //石头总数不等于空位总数直接返回-1
    if(sum != n){
        cout<<-1<<endl;
        return;
    }
    sort(a+1,a+1+m); //对所有位-数键值对排序

    ll now = n; //当前需要放石头的位置，从最后一个开始
    ll ans = 0; //操作次数
    for(int i=m;i>=1;i--){
        ll pos = a[i].first; //pos为供应堆位置
        ll num = min(now-pos+1,a[i].second); //即将放置的石头数量，取供应堆(含)之后的空格数量与供应堆石头数量的最小值
        //从pos这个位置移动到[now-num+1,now]这个区间内，移动总步数就是等差数列求和
        ans += (now-num+1-pos + now-pos)*num/2;
        now = now-num;//now移动到放好石头的前一位
    }
    if(now==0)cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}