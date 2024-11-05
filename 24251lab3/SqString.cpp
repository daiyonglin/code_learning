#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MaxSize 100

//顺序串实现
typedef struct{
    char data[MaxSize]; //存放字符
    int len; //字符串长度
}SqString;

//生成串
void StringAssign(SqString &s,char cstr[]){
    int i;
    for(i=0;cstr[i]!='\0';i++){
        s.data[i] = cstr[i];
    }
    s.len = i;//设置长度
}

//销毁字符串
void Destroy(SqString &s){
    //这里创建时并没有使用指针，OS会自动对这个变量进行内存管理，所以什么都不用做
}

//串的复制
void Copy(SqString &s,SqString t){
    int i;
    for(i=0;i<t.len;i++){
        s.data[i]=t.data[i];
    }
    s.len = t.len;
}

//判断串相等
bool Equal(SqString s,SqString t){
    bool same = true;//设置一个变量same记录状况
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

//求串长
int length(SqString s){
    return s.len;
}

//串的连接
SqString Concat(SqString s,SqString t){
    SqString ans;//创建一个新串存储两串连接的结果
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

//求子串（字符串s的第i位开始连续j个字符）
SqString SubStr(SqString s,int i,int j){
    SqString ans;//创建子串
    ans.len = 0;//先置空
    if(i<=0 || i>s.len || j<0 || i+j-1>s.len){
        cout<<"输入错误"<<endl;
        return ans;//返回空串
    }
    for(int k=i-1;k<i+j-1;k++){
        ans.data[k-i+1]=s.data[k]; //ans的data从0开始
    }
    ans.len = j;
    return ans;
}

//子串插入(s2插入到s1的第i个位置上,返回新串)
SqString InsertStr(SqString s1,int i,SqString s2){
    SqString ans;
    int j;
    ans.len = 0;
    if(i<=0 || i>s1.len+1){
        return ans;
    }
    //复制s1的第一截到ans
    for(j=0;j<i-1;j++){
        ans.data[j] = s1.data[j];
    }
    //复制s2到ans
    for(j=0;j<s2.len;j++){
        ans.data[i+j-1] = s2.data[j];
    }
    //复制s1的第二截
    for(j=i-1;j<s1.len;j++){
        ans.data[s2.len+j] = s1.data[j];
    }
    ans.len = s1.len + s2.len;
    return ans;
}

//输出串
void Print(SqString s){
    if(s.len > 0){                                      
        for(int i=0;i<s.len;i++){
            cout<<s.data[i];
        }
        cout<<endl;
    }
    else{
        cout<<"空"<<endl;
    }
}

//Brute-Force算法
int BF(SqString s,SqString t){
    int i=0,j=0;
    while(i<s.len && j<t.len) //两个串都没有遍历完时一直循环
    {   
        //一个位上字符相等，ij后移
        if(s.data[i] == t.data[j]){
            i++;
            j++;
        }
        //失败，i回溯，j重新到0
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=t.len){
        return i-t.len;//j超界，说明模式串成功匹配，返回首位
    }
    else{
        return -1;//否则匹配失败
    }
}

//KMP算法(改进前，不含nextval数组)
//next数组求解
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
            k = next[k];    //k回退
        }
    }
}
//KMP算法实现
int KMP(SqString s,SqString t){
    int next[MaxSize],i=0,j=0;
    GetNext(t,next);
    while(i<s.len && j<t.len){
        if(j==-1 || s.data[i]==t.data[j]){
            i++;
            j++;//相等往后移
        }
        else{
            j = next[j];//不相等i不变，j回溯
        }     
    }
    if(j>=t.len){
            return i-t.len;
    }
    else{
        return -1;
    }
}

//改进的KMP算法
//next_val求解
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
//KMP算法实现
int KMPpro(SqString s,SqString t){
    int next_val[MaxSize],i=0,j=0;
    GetNext_val(t,next_val);
    while(i<s.len && j<t.len){
        if(j==-1 || s.data[i]==t.data[j]){
            i++;
            j++;//相等往后移
        }
        else{
            j = next_val[j];//不相等i不变，j回溯
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
    cout << "请输入目标串：";
    cin.getline(str, MaxSize + 1); //读取
    cout <<"请输入模式串：";
    cin.getline(ttr,MaxSize+1);
    SqString s,t;
    StringAssign(s, str); // 将输入赋给s和t
    StringAssign(t,ttr);
    
    cout<<"BF算法匹配结果:"<<BF(s,t)<<endl; 
    cout<<"KMP算法匹配结果:"<<KMP(s,t)<<endl;
    cout<<"改进的KMP算法匹配结果:"<<KMPpro(s,t)<<endl;
    return 0;
}