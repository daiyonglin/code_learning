#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
void solve(){
    int h,w,d;
    cin>>h>>w>>d;
    char Floor[h][w];
    vector<pair<int,int>>pos;
    vector<int>ans;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>Floor[i][j];
            if(Floor[i][j]=='.'){
                pair p (i,j);
                pos.push_back(p);
            }
        }
    }
    for(int i=0;i<pos.size();i++){
        for(int j=i+1;j<pos.size();j++){
            int cnt=0;
            for(int k=0;k<pos.size();k++){   
                if(abs(pos[k].first-pos[j].first)+abs(pos[k].second-pos[j].second)<=d ||
                abs(pos[k].first-pos[i].first)+abs(pos[k].second-pos[i].second)<=d){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(),ans.end()-1,cmp);
    cout<<ans[0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}