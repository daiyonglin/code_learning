#include <iostream>
using namespace std;

//项及结点结构体定义
typedef struct Node {
    long long coe; //系数
    int exp; //指数
    struct Node* next; //下一个结点指针

    Node(long long c, int e) : coe(c), exp(e), next(nullptr) {}
};

class Polynomial {
public:
    Node* head; //头结点
    Polynomial() : head(nullptr) {}

// 添加项
    void insert_term(long long coe, int exp) {
        if (coe == 0) return; // 忽略系数为0的项
        Node* newNode = new Node(coe, exp); // 创建新结点
        if (!head || head->exp < exp) { // 如果链表为空或最高项指数小于当前指数
            newNode->next = head;
            head = newNode; // 通过头插法插入多项式链表
        } else { // 否则遍历插入
            Node* current = head;
            Node* pre = nullptr;
            while (current && current->exp > exp) {
                pre = current;
                current = current->next;
            }
            if (current && current->exp == exp) { // 如果找到同类项（指数相同）
                current->coe += newNode->coe; // 合并
                if (current->coe == 0) { // 如果合并后系数为0，则删除该项
                    if (pre) pre->next = current->next;
                    else head = current->next;
                    delete current;
                }
                delete newNode; // 释放新结点
            } else {
                // 循环结束，该正常插入结点
                newNode->next = current;
                if (pre) pre->next = newNode;
                else head = newNode;
            }
        }
    }

    //输出多项式
    void Print() {
        Node* cur = head;
        while (cur) {
            if (cur->coe > 0 && cur != head) cout << "+";
            cout << cur->coe << "x^" << cur->exp << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    //多项式加法
    Polynomial operator+(const Polynomial& other) {
        Polynomial ans;
        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 || current2) {
            if (!current1) {
                ans.insert_term(current2->coe, current2->exp);
                current2 = current2->next;
            } else if (!current2) {
                ans.insert_term(current1->coe, current1->exp);
                current1 = current1->next;
            } else if (current1->exp > current2->exp) {
                ans.insert_term(current1->coe, current1->exp);
                current1 = current1->next;
            } else if (current2->exp > current1->exp) {
                ans.insert_term(current2->coe, current2->exp);
                current2 = current2->next;
            } else {
                ans.insert_term(current1->coe + current2->coe, current1->exp);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        return ans;
    }

   // 多项式乘法
    Polynomial operator*(const Polynomial& other) {
        Polynomial result;
        for (Node* node1 = this->head; node1 != nullptr; node1 = node1->next) {
            for (Node* node2 = other.head; node2 != nullptr; node2 = node2->next) {
                long long productCoe = node1->coe * node2->coe;
                int productExp = node1->exp + node2->exp;
                result.insert_term(productCoe, productExp);
            }
        }
        return result;
    }

    //析构函数
    ~Polynomial() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

int main() {
    Polynomial p1, p2;

    //输入第一个多项式
    p1.insert_term(1, 2);
    p1.insert_term(1, 1);
    p1.insert_term(2, 0);

    //输入第二个多项式
    p2.insert_term(1, 1);
    p2.insert_term(1, 0);

    cout << "第一个多项式为：";
    p1.Print();
    cout << endl;

    cout << "第二个多项式为：";
    p2.Print();
    cout << endl;

    //多项式加法
    Polynomial sum = p1 + p2;
    cout << "两个多项式的和为：";
    sum.Print();
    cout << endl;

    //多项式乘法
    Polynomial multi = p1 * p2;
    cout << "两个多项式的积为：";
    multi.Print();
    cout << endl;

    return 0;
}
