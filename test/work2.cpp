#include<iostream>
using namespace std;
int main(){
    char c;
    int ans[5] = {0,0,0,0,0};//һ������洢5��Ԫ����ĸ�ֱ���ֵĴ���
    int sum = 0;//�����ܴ���
    while(cin>>c){
        //����#��س���ѭ������
        if(c == '#'){
            break;
        }
        //��Ϊ#ʱ������
        else{
            switch(c)
            {
            case 'a':
                ans[0]++;
                sum++;
                break;
            case 'e':
                ans[1]++;
                sum++;
                break;
            case 'i':
                ans[2]++;
                sum++;
                break;
            case 'o':
                ans[3]++;
                sum++;
                break;
            case 'u':
                ans[4]++;
                sum++;
                break;
            }
        } 
    }
    cout<<"5��Ԫ����ĸ���ֵ��ܴ���Ϊ:"<<sum<<endl;

    cout<<"5��Ԫ����ĸ�ֱ���ֵĴ���Ϊ:";
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}