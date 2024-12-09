#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int input;
    cin>>input;
    int x=input/100;
    int y=(input%100)/10;
    int z=input-x*100-y*10;

    int num1 = x + y*100 + z*10;
    int num2 = z*100 + x*10 + y;
    cout<<num1<<" "<<num2<<endl;
    return 0;
}