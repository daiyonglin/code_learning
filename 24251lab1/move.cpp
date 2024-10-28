#include <iostream>
using namespace std;

#define MAXSIZE 100
#define NULL_INDEX -1

typedef int ElemType; // 假设元素类型为int

// 静态链表的节点结构
typedef struct {
    ElemType data;
    int next; // 指向下一个节点的索引
} Node;

// 静态链表结构
typedef struct {
    Node nodes[MAXSIZE];
    int head; // 头指针
    int length; // 链表长度
} StaticList;

// 初始化静态链表
void initList(StaticList &list) {
    list.head = NULL_INDEX;
    list.length = 0;
    for (int i = 0; i < MAXSIZE - 1; i++) {
        list.nodes[i].next = i + 1; // 设置下一个节点索引
    }
    list.nodes[MAXSIZE - 1].next = NULL_INDEX; // 最后一个节点指向NULL
}

// 插入节点
void insertNode(StaticList &list, ElemType value) {
    if (list.length >= MAXSIZE) {
        cout << "链表已满，无法插入元素！" << endl;
        return;
    }

    // 找到可用位置
    int newIndex = list.nodes[0].next; // 取出第一个空闲节点的索引
    list.nodes[0].next = list.nodes[newIndex].next; // 更新空闲节点链表
    list.nodes[newIndex].data = value; // 插入新元素
    list.nodes[newIndex].next = list.head; // 新节点指向当前头
    list.head = newIndex; // 更新头指针
    list.length++;
}

// 右移n位函数
void rightShift(StaticList &list, int n) {
    if (list.length == 0 || n <= 0) return; // 如果链表为空或n为非正数，直接返回

    n = n % list.length; // 处理n大于length的情况
    if (n == 0) return; // 如果n为0，不需要移动

    // 找到新的头指针
    int newHeadIndex = list.head;
    for (int i = 0; i < list.length - n; i++) {
        newHeadIndex = list.nodes[newHeadIndex].next; // 移动到新的头位置
    }

    // 找到旧链表的尾部
    int oldTailIndex = newHeadIndex;
    for (int i = 0; i < n - 1; i++) {
        oldTailIndex = list.nodes[oldTailIndex].next; // 找到新链表的尾部
    }

    // 将旧链表的尾部的next指向原链表的头
    list.nodes[oldTailIndex].next = list.head;

    // 更新头指针
    list.head = newHeadIndex;

    // 找到新尾部并断开
    for (int i = 0; i < list.length - n; i++) {
        oldTailIndex = list.nodes[oldTailIndex].next;
    }
    list.nodes[oldTailIndex].next = NULL_INDEX; // 断开新链表
}

// 打印静态链表
void printList(const StaticList &list) {
    int currentIndex = list.head;
    while (currentIndex != NULL_INDEX) {
        cout << list.nodes[currentIndex].data << " ";
        currentIndex = list.nodes[currentIndex].next;
    }
    cout << endl;
}

// 测试代码
int main() {
    StaticList list;
    initList(list);

    // 插入元素
    insertNode(list, 1);
    insertNode(list, 2);
    insertNode(list, 3);
    insertNode(list, 4);
    insertNode(list, 5);

    cout << "原链表为：";
    printList(list);

    int n = 2; // 右移2位
    rightShift(list, n);

    cout << "右移" << n << "位后的链表为：";
    printList(list);

    return 0;
}
