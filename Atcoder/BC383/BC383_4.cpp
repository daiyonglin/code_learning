#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    if(n == 2 || n == 3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i == 0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}

int Count(long long N){
    int count = 0;
    for(long long i = 2;i<=N;i++){
        //检查N是否为一个质数的8次幂
        if(isPrime(i) && pow(i,8) <= N){
            count++;
        }
        //检查N是否为两个不同质数平方的乘积
        else{
            long long sqrt_i = sqrt(i);
            if(sqrt_i*sqrt_i == i && isPrime(sqrt_i)){
                long long sqrt_sqrt_i = sqrt(sqrt_i);
                if (sqrt_sqrt_i * sqrt_sqrt_i == sqrt_i && isPrime(sqrt_sqrt_i)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long N;
    cin>>N;
    cout<<Count(N)<<endl;
    return 0;
}