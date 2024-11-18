#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int input[4];
    for(int i=0;i<4;i++){
        cin>>input[i];
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        int left = i,right = 3;
        while(left<right){
            if(input[left] == input[right]){
                ans++;
                input[left]=input[right] = -1;
            }
            right--;
        }
    }
    cout<<ans;
    return 0;
}