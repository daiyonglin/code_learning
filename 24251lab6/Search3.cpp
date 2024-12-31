#include <iostream>
using namespace std;

// ��������������Ľڵ�ṹ
struct TreeNode {
    int value;        // �ڵ�洢��ֵ
    TreeNode* left;   // ������
    TreeNode* right;  // ������

    // ���캯����ʼ���ڵ�
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// �����������Ĳ��뺯��
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);  // �����Ϊ�գ������½ڵ�
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);  // ���뵽������
    } else {
        root->right = insert(root->right, value);  // ���뵽������
    }
    
    return root;
}

// ����ָ���ڵ�
TreeNode* find(TreeNode* root, int value) {
    if (root == nullptr || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return find(root->left, value);
    }
    return find(root->right, value);
}

// ���ָ���ڵ������������Ϣ
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

// ������
int main() {
    // ��ʼ������
    TreeNode* root = nullptr;

    // ���ո�����˳�����Ԫ��
    int values[] = {50, 30, 40, 80, 35, 90, 85, 20, 10, 25, 88, 23};
    int n = sizeof(values) / sizeof(values[0]);
    
    // ��������Ԫ�ص�����������
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    // ���Ҳ����ָ���ڵ������������Ϣ
    int nodesToFind[] = {50, 80, 90, 10};
    
    for (int i = 0; i < 4; i++) {
        TreeNode* node = find(root, nodesToFind[i]);
        cout << "Subtree information for node " << nodesToFind[i] << ":" << endl;
        printSubtreeInfo(node);
        cout << "--------------------------" << endl;
    }

    return 0;
}
