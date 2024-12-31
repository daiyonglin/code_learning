#include <iostream>
using namespace std;

// 定义二叉排序树的节点结构
struct TreeNode {
    int value;        // 节点存储的值
    TreeNode* left;   // 左子树
    TreeNode* right;  // 右子树

    // 构造函数初始化节点
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 二叉排序树的插入函数
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);  // 如果树为空，创建新节点
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);  // 插入到左子树
    } else {
        root->right = insert(root->right, value);  // 插入到右子树
    }
    
    return root;
}

// 查找指定节点
TreeNode* find(TreeNode* root, int value) {
    if (root == nullptr || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return find(root->left, value);
    }
    return find(root->right, value);
}

// 输出指定节点的左右子树信息
void printSubtreeInfo(TreeNode* node) {
    if (node == nullptr) {
        cout << "Node does not exist." << endl;
        return;
    }

    cout << "Node value: " << node->value << endl;

    if (node->left) {
        cout << "Left child: " << node->left->value << endl;
    } else {
        cout << "Left child: NULL" << endl;
    }

    if (node->right) {
        cout << "Right child: " << node->right->value << endl;
    } else {
        cout << "Right child: NULL" << endl;
    }
}

// 主程序
int main() {
    // 初始化空树
    TreeNode* root = nullptr;

    // 按照给定的顺序插入元素
    int values[] = {50, 30, 40, 80, 35, 90, 85, 20, 10, 25, 88, 23};
    int n = sizeof(values) / sizeof(values[0]);
    
    // 插入数据元素到二叉排序树
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // 查找并输出指定节点的左右子树信息
    int nodesToFind[] = {50, 80, 90, 10};
    
    for (int i = 0; i < 4; i++) {
        TreeNode* node = find(root, nodesToFind[i]);
        cout << "Subtree information for node " << nodesToFind[i] << ":" << endl;
        printSubtreeInfo(node);
        cout << "--------------------------" << endl;
    }

    return 0;
}
