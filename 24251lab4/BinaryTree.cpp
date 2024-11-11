#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct TreeNode{
    ElemType val; //结点数据
    TreeNode *left; //左子树
    TreeNode *right; //右子树
    TreeNode(char x) : val(x),left(nullptr),right(nullptr){}//构造函数，节点值初始化为x，左右指针初始化为nullptr
}Node;

//输入先序序列生成二叉链表
TreeNode* buildTree(string& preorder,int& index){
    //检查是否处理完所有字符
    if(index >= preorder.size()){
        return nullptr;
    }
    //读取字符并自增1，便于递归访问下个字符
    char current = preorder[index++];
    if(current == '#'){
        return nullptr;
    }
    //创建根节点并递归创建左右子树
    TreeNode* root = new TreeNode(current);
    root->left = buildTree(preorder,index);
    root->right = buildTree(preorder,index);

    return root;
}

//先序遍历
void PreorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    cout<<root->val<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
//中序遍历
void inorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
//后序遍历
void postorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}

//计算叶子结点数
int countLeaves(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    //递归计算左子树和右子树的叶子结点个数和
    return countLeaves(root->left) + countLeaves(root->right);
}

//求二叉树深度
int treeDepth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    //递归分别算出左右子树的深度
    int left_depth = treeDepth(root->left);
    int right_depth = treeDepth(root->right);

    return max(left_depth,right_depth)+1;
}
int main(){
    string preorder;
    cout<<"请输入二叉树的先序序列:";
    cin>>preorder;

    int index = 0;
    TreeNode* root = buildTree(preorder,index);

    cout<<"构建的二叉树的先序遍历结果为：";
    PreorderTraversal(root);
    cout<<endl;
    cout<<"构建的二叉树的中序遍历结果为：";
    inorderTraversal(root);
    cout<<endl;
    cout<<"构建的二叉树的后序遍历结果为：";
    postorderTraversal(root);
    cout<<endl;


    cout<<"该二叉树的叶子结点个数为：";
    cout<<countLeaves(root)<<endl;

    cout<<"该二叉树的深度为：";
    cout<<treeDepth(root)<<endl;
    return 0;
}

