#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int left=0,right=n-1;
    if(n%2 == 1){
        if(s[(n/2)]!='/'){
            cout<<"No"<<endl;
        }
        else{
             while(left != right){
                if(s[left]!='1' || s[right]!='2'){
                    cout<<"No"<<endl;
                    
                    return;
                }
                else{
                    left++;
                    right--;
                }
            }
            cout<<"Yes"<<endl;
        }      
        }  
    else{
        cout<<"No"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}