#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//定义队列类(使用循环队列)
class Queue{
private:
    int* arr;
    int front,rear,capacity;//队头指针、队尾指针、队容量
public:
    //构造函数/初始化
    Queue(int size){
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    //析构函数/销毁
    ~Queue(){
        delete[]arr;
    }

    //队列是否为空
    bool isEmpty()const{
        return (front == -1);
    }

    //队列是否满
    bool isFull()const{
        //特别注意循环队列的判满条件！rear循环增1==front
        return (rear+1)%capacity == front;
    }

    //入队
    void push(int value){
        if(isFull()){
            cout<<"队满"<<endl;
            return ;
        }
        else{
            if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear+1)%capacity;//循环+1
        }
        arr[rear] = value;
        } 
    }

    //出队
    void pop(){
        if(isEmpty()){
            cout<<"队空"<<endl;
            return ;
        }
        else{
            if(front == rear){//只有一个元素
                front = rear = -1;//队列清空
            }
            else{
                front = (front+1)%capacity;
            }
        }
    }

    //返回队首元素
    int getTop()const{
        if(isEmpty()){
            cout<<"队空"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    //计算队列中元素个数
    int size()const{
        if(isEmpty()){
            return 0;
        }
        else{
            if(rear >= front){
                return rear-front+1;
            }
            else{
                return capacity-front+rear+1;
            }
        }
    }   
};

// 打印杨辉三角
void printPascalsTriangle(int numRows) {
    Queue prevQueue(numRows * numRows); // 用于保存上一行
    Queue currentQueue(numRows * numRows); // 用于生成当前行

    for (int i = 0; i < numRows; ++i) {
        // 每行开头插入并打印1
        currentQueue.push(1);
        cout << "1 ";

        // 生成每行的中间元素
        for (int j = 1; j < i; ++j) {
            int left = prevQueue.getTop();
            prevQueue.pop();
            int right = prevQueue.getTop();
            int next = left + right;
            currentQueue.push(next);
            cout << next << " ";
        }

        // 每行末尾插入并打印1
        if (i > 0) {
            cout << "1 ";
            currentQueue.push(1);
        }

        cout << endl; // 换行

        // 交换队列，将当前行变为上一行
        while (!prevQueue.isEmpty()) prevQueue.pop(); // 清空上一行队列
        while (!currentQueue.isEmpty()) {
            prevQueue.push(currentQueue.getTop());
            currentQueue.pop();
        }
    }
}

int main(){
    int row;
    cout<<"请输入杨辉三角的行数：";
    cin>>row;
    printPascalsTriangle(row);
    return 0;
}