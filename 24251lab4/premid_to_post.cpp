#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string buildTree(const string& preorder,const string& inorder){
    if(preorder.empty())return ""; //前序遍历为空，返回空
    //前序遍历的第一个字符一定为根节点
    char root = preorder[0];
    //在中序遍历中寻找根结点
    int rootIndex = inorder.find(root);
    //左子树的前序和中序遍历序列
    string leftPreorder = preorder.substr(1,rootIndex);
    string leftInorder = inorder.substr(0,rootIndex);
    // 右子树的前序和中序遍历序列
    string rightPreorder = preorder.substr(rootIndex + 1);
    string rightInorder = inorder.substr(rootIndex + 1);
     // 递归构建左子树和右子树的后序遍历，并组合成最终的后序遍历
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