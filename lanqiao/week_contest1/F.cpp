#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAXN 200000
int calculate(long long a,long long b,long long c,int n){
    if(b*n-c == 0){
        return 0;
    }
    else{
        return a/(b*n-c);
    }
}
bool judge(int num){
    if(num>floor(num) && num<abs(num))return true;
    else{
        return false;
    }
}
int main(){
    long long A,B,C;
    cin>>A>>B>>C;
    int sum=0;
    int i=1;
    while(i<=MAXN){
        if(judge(calculate(A,B,C,i))==true)sum++;
        i++;
    }
    cout<<sum;
    return 0;
}