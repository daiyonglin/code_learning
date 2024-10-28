#include <iostream>
using namespace std;

// 节点结构
struct Node {
    int data; // 节点数据
    Node* next; // 指向下一个节点的指针

    Node(int val) : data(val), next(nullptr) {}
};

// 创建约瑟夫环的链表
Node* createJosephusCircle(int n) {
    Node* head = new Node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
    }
    current->next = head; // 形成环
    return head;
}

// 解决约瑟夫环问题
int josephus(int n, int k) {
    Node* head = createJosephusCircle(n);
    Node* current = head;

    Node* previous = nullptr; // 用于保存前一个节点

    while (current->next != current) { // 当链表中有多个节点时
        // 找到要被淘汰的节点
        for (int i = 1; i < k; i++) {
            previous = current; // 保存当前节点
            current = current->next; // 移动到下一个节点
        }
        // 淘汰当前节点
        previous->next = current->next; // 将前一个节点指向下一个节点
        delete current; // 释放被淘汰节点的内存
        current = previous->next; // 更新当前节点
    }

    int survivor = current->data; // 最后剩下的人的编号
    delete current; // 释放最后一个节点的内存
    return survivor;
}

// 主函数
int main() {
    int n, k;
    cout << "请输入总人数 n：";
    cin >> n;
    cout << "请输入每次淘汰的步数 k：";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "最后剩下的人是: " << survivor << endl;

    return 0;
}
