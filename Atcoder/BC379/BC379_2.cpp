#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int K,N; //һ��N�����ݣ���Ҫ������K��
    cin>>N>>K;
    string T; //�ַ�����ʾȫ��������״��
    cin>>T;
    
    int ans = 0;
    string cmp = string(K,'O');//����һ��ģʽ������������ƥ��
    for(int i=0;i<N-K+1;i++){
        if(T.substr(i,K) == cmp){
            ans++; //����K��ƥ��ɹ�
            for(int j=i;j<i+K;j++){//ʹ�ù���λ��ȫ����ΪX
                T[j] = 'X';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}