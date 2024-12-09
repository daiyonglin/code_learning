#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int maxn = 2e6 + 5;
typedef long long ll;

pair<ll,ll> a[maxn]; //pair���͵�����
void solve(){
    int n,m;
    cin>>n>>m; //nΪ��λ������mΪ��ʼ��ʯͷ�Ŀ�λ��(��Ӧ������)

    ll sum = 0; //ʯͷ����
    for(int i=1;i<=m;i++)cin>>a[i].first; //����pair�ļ�
    for(int i=1;i<=m;i++)cin>>a[i].second,sum+=a[i].second;//����pair��ֵ��ͬʱ������
    //ʯͷ���������ڿ�λ����ֱ�ӷ���-1
    if(sum != n){
        cout<<-1<<endl;
        return;
    }
    sort(a+1,a+1+m); //������λ-����ֵ������

    ll now = n; //��ǰ��Ҫ��ʯͷ��λ�ã������һ����ʼ
    ll ans = 0; //��������
    for(int i=m;i>=1;i--){
        ll pos = a[i].first; //posΪ��Ӧ��λ��
        ll num = min(now-pos+1,a[i].second); //�������õ�ʯͷ������ȡ��Ӧ��(��)֮��Ŀո������빩Ӧ��ʯͷ��������Сֵ
        //��pos���λ���ƶ���[now-num+1,now]��������ڣ��ƶ��ܲ������ǵȲ��������
        ans += (now-num+1-pos + now-pos)*num/2;
        now = now-num;//now�ƶ����ź�ʯͷ��ǰһλ
    }
    if(now==0)cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    int T = 1;
    while(T--)solve();
}