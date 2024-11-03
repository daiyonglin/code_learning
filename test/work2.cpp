#include<iostream>
using namespace std;
int main(){
    char c;
    int ans[5] = {0,0,0,0,0};//一个数组存储5个元音字母分别出现的次数
    int sum = 0;//出现总次数
    while(cin>>c){
        //输入#后回车，循环结束
        if(c == '#'){
            break;
        }
        //不为#时，计数
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
    cout<<"5个元音字母出现的总次数为:"<<sum<<endl;

    cout<<"5个元音字母分别出现的次数为:";
    for(int i=0;i<5;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}