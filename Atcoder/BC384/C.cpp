#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int score[5];
    for(int i=0;i<5;i++){
        cin>>score[i];
    }
    pair<int,string> rec[50];
    int k=0;//记录rec数组下标移动
    for(int i=0;i<(1<<5);i++){
        string t = "";
        int result = 0;
        for(int j=0;j<5;j++){
            if(i & (1<<j)){//检查第j位是否非零，非零就是有这个题的得分
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