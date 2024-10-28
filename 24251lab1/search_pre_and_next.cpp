#include <iostream>
using namespace std;

// 节点结构
struct Node {
    int data; // 节点数据
    Node* prev; // 指向前驱节点
    Node* next; // 指向后继节点

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// 双向链表类
class DoublyLinkedList {
private:
    Node* head; // 头指针
    Node* tail; // 尾指针
    int length; // 链表长度

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // 插入节点
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { // 如果链表为空
            head = tail = newNode;
        } else {
            tail->next = newNode; // 将新节点添加到尾部
            newNode->prev = tail;
            tail = newNode; // 更新尾指针
        }
        length++;
    }

    // 查找第n个节点的前驱和后继
    void findPredecessorAndSuccessor(int n) {
        if (n < 1 || n > length) {
            cout << "输入的n超出链表范围。" << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; i < n; i++) {
            current = current->next; // 遍历到第n个节点
        }

        // 输出前驱和后继
        if (current->prev) {
            cout << "第" << n << "个节点的前驱: " << current->prev->data << endl;
        } else {
            cout << "第" << n << "个节点没有前驱。" << endl;
        }

        if (current->next) {
            cout << "第" << n << "个节点的后继: " << current->next->data << endl;
        } else {
            cout << "第" << n << "个节点没有后继。" << endl;
        }
    }

    // 打印链表
    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 析构函数
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

// 主函数
int main() {
    DoublyLinkedList list;

    // 插入一些示例数据
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "链表元素为：";
    list.printList();

    int n;
    cout << "请输入要查找的节点位置n：";
    cin >> n;

    list.findPredecessorAndSuccessor(n);

    return 0;
}
