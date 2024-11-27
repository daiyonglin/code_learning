#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(){
    int n,q;
    cin>>n>>q;

    int pos_L=1;
    int pos_R=2;
    int ans=0;
    for(int i=0;i<q;i++){
        char hand;int mov;
        cin>>hand>>mov;
        int to=0,from=0,block=0;
        if(hand == 'R'){
            block = pos_L;
            from = pos_R;
            to = mov;
            if(to < from){
                swap(to,from);
            }
            
                if(from<block && block<to){
                    ans += n-(to-from);
                }
                else{
                    ans += to-from;
                }
            
            pos_R = mov;
        }
        else if(hand == 'L'){
            block = pos_R;
            from = pos_L;
            to = mov;
            if(to < from){
                swap(to,from);
            }
            
                if(from<block && block<to){
                    ans += n-(to-from);
                }
                else{
                    ans += to-from;
                }
            
            pos_L = mov;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}