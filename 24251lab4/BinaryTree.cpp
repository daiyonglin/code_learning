#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct TreeNode{
    ElemType val; //�������
    TreeNode *left; //������
    TreeNode *right; //������
    TreeNode(char x) : val(x),left(nullptr),right(nullptr){}//���캯�����ڵ�ֵ��ʼ��Ϊx������ָ���ʼ��Ϊnullptr
}Node;

//���������������ɶ�������
TreeNode* buildTree(string& preorder,int& index){
    //����Ƿ����������ַ�
    if(index >= preorder.size()){
        return nullptr;
    }
    //��ȡ�ַ�������1�����ڵݹ�����¸��ַ�
    char current = preorder[index++];
    if(current == '#'){
        return nullptr;
    }
    //�������ڵ㲢�ݹ鴴����������
    TreeNode* root = new TreeNode(current);
    root->left = buildTree(preorder,index);
    root->right = buildTree(preorder,index);

    return root;
}

//�������
void PreorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    cout<<root->val<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
//�������
void inorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
//�������
void postorderTraversal(TreeNode* root){
    if(root == nullptr)return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}

//����Ҷ�ӽ����
int countLeaves(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    //�ݹ��������������������Ҷ�ӽ�������
    return countLeaves(root->left) + countLeaves(root->right);
}

//����������
int treeDepth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    //�ݹ�ֱ�����������������
    int left_depth = treeDepth(root->left);
    int right_depth = treeDepth(root->right);

    return max(left_depth,right_depth)+1;
}
int main(){
    string preorder;
    cout<<"���������������������:";
    cin>>preorder;

    int index = 0;
    TreeNode* root = buildTree(preorder,index);

    cout<<"�����Ķ�����������������Ϊ��";
    PreorderTraversal(root);
    cout<<endl;
    cout<<"�����Ķ�����������������Ϊ��";
    inorderTraversal(root);
    cout<<endl;
    cout<<"�����Ķ������ĺ���������Ϊ��";
    postorderTraversal(root);
    cout<<endl;


    cout<<"�ö�������Ҷ�ӽ�����Ϊ��";
    cout<<countLeaves(root)<<endl;

    cout<<"�ö����������Ϊ��";
    cout<<treeDepth(root)<<endl;
    return 0;
}

