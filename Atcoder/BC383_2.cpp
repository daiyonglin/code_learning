#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct point_pos{
    int hang;
    int lie;
    int cnt;
};
char Floor[10][10]={0};
vector<point_pos>Pos;
int ans =0;

bool Cmp(point_pos a,point_pos b){
    return a.cnt > b.cnt;
}
void solve(){
    int H,W,D;
    cin>>H>>W>>D;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>Floor[i][j];
            if(Floor[i][j]=='.'){
                point_pos p;
                p.hang =i;
                p.lie=j;
                Pos.push_back(p);
            }
        }
    }

    for(int i=0;i<Pos.size();i++){
        for(int j=0;j<Pos.size();j++){
            if(abs(Pos[j].hang-Pos[i].hang)+abs(Pos[j].lie-Pos[i].lie)<=D){
                Pos[i].cnt++;
                Pos[i].hang = Pos[i].lie = 100;
            }
        }
    }

    sort(Pos.begin(),Pos.end(),Cmp);
    ans=Pos[0].cnt+Pos[1].cnt;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}