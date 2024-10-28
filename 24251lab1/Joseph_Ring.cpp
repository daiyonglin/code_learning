#include <iostream>
using namespace std;

// �ڵ�ṹ
struct Node {
    int data; // �ڵ�����
    Node* next; // ָ����һ���ڵ��ָ��

    Node(int val) : data(val), next(nullptr) {}
};

// ����Լɪ�򻷵�����
Node* createJosephusCircle(int n) {
    Node* head = new Node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
    }
    current->next = head; // �γɻ�
    return head;
}

// ���Լɪ������
int josephus(int n, int k) {
    Node* head = createJosephusCircle(n);
    Node* current = head;

    Node* previous = nullptr; // ���ڱ���ǰһ���ڵ�

    while (current->next != current) { // ���������ж���ڵ�ʱ
        // �ҵ�Ҫ����̭�Ľڵ�
        for (int i = 1; i < k; i++) {
            previous = current; // ���浱ǰ�ڵ�
            current = current->next; // �ƶ�����һ���ڵ�
        }
        // ��̭��ǰ�ڵ�
        previous->next = current->next; // ��ǰһ���ڵ�ָ����һ���ڵ�
        delete current; // �ͷű���̭�ڵ���ڴ�
        current = previous->next; // ���µ�ǰ�ڵ�
    }

    int survivor = current->data; // ���ʣ�µ��˵ı��
    delete current; // �ͷ����һ���ڵ���ڴ�
    return survivor;
}

// ������
int main() {
    int n, k;
    cout << "������������ n��";
    cin >> n;
    cout << "������ÿ����̭�Ĳ��� k��";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "���ʣ�µ�����: " << survivor << endl;

    return 0;
}
