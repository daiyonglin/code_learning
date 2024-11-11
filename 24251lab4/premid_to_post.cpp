#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string buildTree(const string& preorder,const string& inorder){
    if(preorder.empty())return ""; //ǰ�����Ϊ�գ����ؿ�
    //ǰ������ĵ�һ���ַ�һ��Ϊ���ڵ�
    char root = preorder[0];
    //�����������Ѱ�Ҹ����
    int rootIndex = inorder.find(root);
    //��������ǰ��������������
    string leftPreorder = preorder.substr(1,rootIndex);
    string leftInorder = inorder.substr(0,rootIndex);
    // ��������ǰ��������������
    string rightPreorder = preorder.substr(rootIndex + 1);
    string rightInorder = inorder.substr(rootIndex + 1);
     // �ݹ鹹�����������������ĺ������������ϳ����յĺ������
    return buildTree(leftPreorder, leftInorder) +
           buildTree(rightPreorder, rightInorder) +
           root;
}

int main(){
    string preorder,inorder;
    while(cin>>preorder>>inorder){
        cout<<buildTree(preorder,inorder)<<endl;
    }
    return 0;
}