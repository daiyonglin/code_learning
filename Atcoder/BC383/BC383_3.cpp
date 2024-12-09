#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int MAX_N = 1000+5;
char Floor[MAX_N][MAX_N];
int h,w,d;

queue<pair<int,int>>que;
int dis[MAX_N][MAX_N];

//左右和上下方向
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void solve(){
    cin>>h>>w>>d;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>Floor[i][j];
        }
    }

    //bfs step1:清空相关信息
    memset(dis,-1,sizeof(dis));

    //bfs step2:将起点加入队列
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(Floor[i][j] == 'H'){
                que.push(make_pair(i,j));
                dis[i][j]=0;
            }
        }
    }

    //bfs step2:主体
    while(!que.empty()){
        auto[x,y] = que.front();
        que.pop();

        for(int k=0;k<4;k++){
            int xx=x+dx[k]; int yy=y+dy[k];
            if(xx>=1 && xx<=h && yy>=1 && yy<=w && Floor[xx][yy]!='#'){
                if(dis[xx][yy]==-1){
                    dis[xx][yy] = dis[x][y]+1;
                    que.push(make_pair(xx,yy));
                }
            }
        }
    }

    int ans=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(dis[i][j]<=d && dis[i][j]!=-1){
                ans++;
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}