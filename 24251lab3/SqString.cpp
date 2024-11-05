#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100

//˳��ʵ��
typedef struct{
    char data[MaxSize]; //����ַ�
    int len; //�ַ�������
}SqString;

//���ɴ�
void StringAssign(SqString &s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++){
        s.data[i] = cstr[i];
    }
    s.len = i;//���ó���
}

//�����ַ���
void Destroy(SqString &s){
    //���ﴴ��ʱ��û��ʹ��ָ�룬OS���Զ���������������ڴ��������ʲô��������
}

//���ĸ���
void Copy(SqString &s,SqString t){
    int i;
    for(i=0;i<t.len;i++){
        s.data[i]=t.data[i];
    }
    s.len = t.len;
}

//�жϴ����
bool Equal(SqString s,SqString t){
    bool same = true;//����һ������same��¼״��
    int i;
    if(s.len != t.len){
        same = false;
    }
    else{
        for(i=0;i<s.len;i++){
            if(s.data[i] != t.data[i]){
                same = false;
                break;
            }
        }
    }
    return same;
}

//�󴮳�
int length(SqString s){
    return s.len;
}

//��������
SqString Concat(SqString s,SqString t){
    SqString ans;//����һ���´��洢�������ӵĽ��
    ans.len = s.len + t.len;
    int i;
    for(i=0;i<s.len;i++){
        ans.data[i] = s.data[i];
    }
    for(i=0;i<t.len;i++){
        ans.data[s.len+i] = t.data[i];
    }
    return ans;
}

//���Ӵ����ַ���s�ĵ�iλ��ʼ����j���ַ���
SqString SubStr(SqString s,int i,int j){
    SqString ans;//�����Ӵ�
    ans.len = 0;//���ÿ�
    if(i<=0 || i>s.len || j<0 || i+j-1>s.len){
        cout<<"�������"<<endl;
        return ans;//���ؿմ�
    }
    for(int k=i-1;k<i+j-1;k++){
        ans.data[k-i+1]=s.data[k]; //ans��data��0��ʼ
    }
    ans.len = j;
    return ans;
}

//�Ӵ�����(s2���뵽s1�ĵ�i��λ����,�����´�)
SqString InsertStr(SqString s1,int i,SqString s2){
    SqString ans;
    int j;
    ans.len = 0;
    if(i<=0 || i>s1.len+1){
        return ans;
    }
    //����s1�ĵ�һ�ص�ans
    for(j=0;j<i-1;j++){
        ans.data[j] = s1.data[j];
    }
    //����s2��ans
    for(j=0;j<s2.len;j++){
        ans.data[i+j-1] = s2.data[j];
    }
    //����s1�ĵڶ���
    for(j=i-1;j<s1.len;j++){
        ans.data[s2.len+j] = s1.data[j];
    }
    ans.len = s1.len + s2.len;
    return ans;
}

//�����
void Print(SqString s){
    if(s.len > 0){                                      
        for(int i=0;i<s.len;i++){
            cout<<s.data[i];
        }
        cout<<endl;
    }
    else{
        cout<<"��"<<endl;
    }
}

//Brute-Force�㷨
int BF(SqString s,SqString t){
    int i=0,j=0;
    while(i<s.len && j<t.len) //��������û�б�����ʱһֱѭ��
    {   
        //һ��λ���ַ���ȣ�ij����
        if(s.data[i] == t.data[j]){
            i++;
            j++;
        }
        //ʧ�ܣ�i���ݣ�j���µ�0
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=t.len){
        return i-t.len;//j���磬˵��ģʽ���ɹ�ƥ�䣬������λ
    }
    else{
        return -1;//����ƥ��ʧ��
    }
}

//KMP�㷨(�Ľ�ǰ������nextval����)
//next�������
void GetNext(SqString t,int next[]){
    int j,k;
    j=0;k=-1;
    next[0]=-1;
    while(j<t.len-1){
        if(k==-1 || t.data[j]==t.data[k]){
            j++;k++;
            next[j]=k;
        }
        else{
            k = next[k];    //k����
        }
    }
}
//KMP�㷨ʵ��
int KMP(SqString s,SqString t){
    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while(i<s.len && j<t.len){
        if(j==-1 || s.data[i]==t.data[j]){
            i++;
            j++;//���������
        }
        else{
            j = next[j];//�����i���䣬j����
        }     
    }
    if(j>=t.len){
            return i-t.len;
    }
    else{
        return -1;
    }
}

//�Ľ���KMP�㷨
//next_val���
void GetNext_val(SqString t,int next_val[]){
    int j=0,k=-1;
    next_val[0]=-1;
    while(j<t.len){
        if(k == -1 || t.data[j]==t.data[k]){
            j++;k++;
            if(t.data[j]!=t.data[k]){
                next_val[j]=k;
            }
            else{
                next_val[j]=next_val[k];
            }
        }
        else{
            k=next_val[k];
        }
    }
}
//KMP�㷨ʵ��
int KMPpro(SqString s,SqString t){
    int next_val[MaxSize],i=0,j=0;
    GetNext_val(t,next_val);
    while(i<s.len && j<t.len){
        if(j==-1 || s.data[i]==t.data[j]){
            i++;
            j++;//���������
        }
        else{
            j = next_val[j];//�����i���䣬j����
        }     
    }
    if(j>=t.len){
            return i-t.len;
    }
    else{
        return -1;
    }
}
int main() {
    char str[MaxSize + 1];
    char ttr[MaxSize+1];
    cout << "������Ŀ�괮��";
    cin.getline(str, MaxSize + 1); //��ȡ
    cout <<"������ģʽ����";
    cin.getline(ttr,MaxSize+1);
    SqString s,t;
    StringAssign(s, str); // �����븳��s��t
    StringAssign(t,ttr);
    
    cout<<"BF�㷨ƥ����:"<<BF(s,t)<<endl; 
    cout<<"KMP�㷨ƥ����:"<<KMP(s,t)<<endl;
    cout<<"�Ľ���KMP�㷨ƥ����:"<<KMPpro(s,t)<<endl;
    return 0;
}