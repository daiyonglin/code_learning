#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    string input;
    cout<<"�������ַ�����";
    getline(cin,input);
    int count[256]={0}; //��¼�ַ����ִ���
    string order; //��¼�ַ�����˳��
    for(char c:input){//����input�е�ÿ���ַ�cִ��һ��ѭ��
        if(count[c] == 0){
            //����ַ��ǵ�һ�γ��֣���¼��˳����
            order += c;
        }
        count[c]++;
    }

    for(char c: order){
        cout<<c<<" "<<count[c]<<endl;
    }
    return 0;
}