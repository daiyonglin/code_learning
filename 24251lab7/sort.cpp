#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//直接插入排序
void directInsert_Sort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; //移动元素
            --j;
        }
        arr[j+1] = key; //插入key
    }
}

//折半插入排序
void binaryInsert_Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1, mid;
        
        // 使用二分查找插入位置
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // 将后面的元素向后移动
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;  // 插入key
    }
}

//快速排序以及快速排序的每轮结果输出
int partition(vector<int>& arr,int low,int high){
    int pivot = arr[high]; //选取最后一个元素作为枢轴
    int i = low-1; //i时区分点的前一个位置
    for(int j = low;j<high;++j){
        if(arr[j] < pivot){
            ++i;
            swap(arr[i],arr[j]); //交换小于枢轴的元素
        }
    }
    swap(arr[i+1],arr[high]); //将枢轴元素放置到正确位置
    return i+1; //返回枢轴位置
}

void quick_Sort(vector<int>& arr,int low,int high){
    if(low < high){
        //分区操作，获取枢轴位置
        int pi = partition(arr,low,high);

        //输出每轮排序后的数组以及枢轴位置
        cout<<"该轮后枢轴位置："<<pi<<" "<<"此时顺序表结构：";
        for(int i=0;i<arr.size();++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        //递归对左右子数组进行排序
        quick_Sort(arr,low,pi-1);
        quick_Sort(arr,pi+1,high);
    }
}

int main(){
    vector<int>arr1 = {1,8,6,4,10,5,3,2,22};
    vector<int>arr2 = arr1;
    vector<int>arr3 = arr1;

    cout<<"直接插入排序："<<endl;
    directInsert_Sort(arr1);
    for(int i : arr1){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"折半插入排序："<<endl;
    binaryInsert_Sort(arr2);
    for(int i : arr2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"快速排序："<<endl;
    quick_Sort(arr3,0,arr3.size()-1);

    return 0;
}