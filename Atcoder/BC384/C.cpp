#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int score[5];
    for(int i=0;i<5;i++){
        cin>>score[i];
    }
    pair<int,string> rec[50];
    int k=0;//��¼rec�����±��ƶ�
    for(int i=0;i<(1<<5);i++){
        string t = "";
        int result = 0;
        for(int j=0;j<5;j++){
            if(i & (1<<j)){//����jλ�Ƿ���㣬��������������ĵ÷�
                t+=char('A'+j);
                result+=score[j];
            }           
        }
        rec[k++]={-1*result,t};
    }
    sort(rec,rec+k);
    for(int i=0;i<k;i++){
        cout<<rec[i].second<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}