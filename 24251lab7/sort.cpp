#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//ֱ�Ӳ�������
void directInsert_Sort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; //�ƶ�Ԫ��
            --j;
        }
        arr[j+1] = key; //����key
    }
}

//�۰��������
void binaryInsert_Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int left = 0, right = i - 1, mid;
        
        // ʹ�ö��ֲ��Ҳ���λ��
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // �������Ԫ������ƶ�
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;  // ����key
    }
}

//���������Լ����������ÿ�ֽ�����
int partition(vector<int>& arr,int low,int high){
    int pivot = arr[high]; //ѡȡ���һ��Ԫ����Ϊ����
    int i = low-1; //iʱ���ֵ��ǰһ��λ��
    for(int j = low;j<high;++j){
        if(arr[j] < pivot){
            ++i;
            swap(arr[i],arr[j]); //����С�������Ԫ��
        }
    }
    swap(arr[i+1],arr[high]); //������Ԫ�ط��õ���ȷλ��
    return i+1; //��������λ��
}

void quick_Sort(vector<int>& arr,int low,int high){
    if(low < high){
        //������������ȡ����λ��
        int pi = partition(arr,low,high);

        //���ÿ�������������Լ�����λ��
        cout<<"���ֺ�����λ�ã�"<<pi<<" "<<"��ʱ˳���ṹ��";
        for(int i=0;i<arr.size();++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        //�ݹ�������������������
        quick_Sort(arr,low,pi-1);
        quick_Sort(arr,pi+1,high);
    }
}

int main(){
    vector<int>arr1 = {1,8,6,4,10,5,3,2,22};
    vector<int>arr2 = arr1;
    vector<int>arr3 = arr1;

    cout<<"ֱ�Ӳ�������"<<endl;
    directInsert_Sort(arr1);
    for(int i : arr1){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"�۰��������"<<endl;
    binaryInsert_Sort(arr2);
    for(int i : arr2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"��������"<<endl;
    quick_Sort(arr3,0,arr3.size()-1);

    return 0;
}