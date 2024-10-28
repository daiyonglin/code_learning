#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//���������(ʹ��ѭ������)
class Queue{
private:
    int* arr;
    int front,rear,capacity;//��ͷָ�롢��βָ�롢������
public:
    //���캯��/��ʼ��
    Queue(int size){
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    //��������/����
    ~Queue(){
        delete[]arr;
    }

    //�����Ƿ�Ϊ��
    bool isEmpty()const{
        return (front == -1);
    }

    //�����Ƿ���
    bool isFull()const{
        //�ر�ע��ѭ�����е�����������rearѭ����1==front
        return (rear+1)%capacity == front;
    }

    //���
    void push(int value){
        if(isFull()){
            cout<<"����"<<endl;
            return ;
        }
        else{
            if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear+1)%capacity;//ѭ��+1
        }
        arr[rear] = value;
        } 
    }

    //����
    void pop(){
        if(isEmpty()){
            cout<<"�ӿ�"<<endl;
            return ;
        }
        else{
            if(front == rear){//ֻ��һ��Ԫ��
                front = rear = -1;//�������
            }
            else{
                front = (front+1)%capacity;
            }
        }
    }

    //���ض���Ԫ��
    int getTop()const{
        if(isEmpty()){
            cout<<"�ӿ�"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    //���������Ԫ�ظ���
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

// ��ӡ�������
void printPascalsTriangle(int numRows) {
    Queue prevQueue(numRows * numRows); // ���ڱ�����һ��
    Queue currentQueue(numRows * numRows); // �������ɵ�ǰ��

    for (int i = 0; i < numRows; ++i) {
        // ÿ�п�ͷ���벢��ӡ1
        currentQueue.push(1);
        cout << "1 ";

        // ����ÿ�е��м�Ԫ��
        for (int j = 1; j < i; ++j) {
            int left = prevQueue.getTop();
            prevQueue.pop();
            int right = prevQueue.getTop();
            int next = left + right;
            currentQueue.push(next);
            cout << next << " ";
        }

        // ÿ��ĩβ���벢��ӡ1
        if (i > 0) {
            cout << "1 ";
            currentQueue.push(1);
        }

        cout << endl; // ����

        // �������У�����ǰ�б�Ϊ��һ��
        while (!prevQueue.isEmpty()) prevQueue.pop(); // �����һ�ж���
        while (!currentQueue.isEmpty()) {
            prevQueue.push(currentQueue.getTop());
            currentQueue.pop();
        }
    }
}

int main(){
    int row;
    cout<<"������������ǵ�������";
    cin>>row;
    printPascalsTriangle(row);
    return 0;
}