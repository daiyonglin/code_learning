#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> Find(int n){
    vector<int> primes;
    int num = 2;
    while(primes.size()<n){
        if(isPrime(num)){
            primes.push_back(num);
        }
        num++;
    }
    return primes;
}

int search(int n){
    vector<int> primes = Find(n);
    int num = 2;
    while(1){
        bool can =false;
        for(int prime : primes){
            if(num % prime == 0){
                can = true;
                break;
            }
        }
        if(!can){
            return num;
        }
        num++;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<search(n)<<endl;
    return 0;
}