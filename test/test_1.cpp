#include<iostream>
using namespace std;
int main(){
    for(int i=1;i<10;i++){
        for(int j=1;j<=12-i;j++)
        cout<<" ";
        for(int j=1;j<=i;j++)
            cout<<i<<" ";
        cout<<endl;
    }
}