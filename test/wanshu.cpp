#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ���������ж�һ�����Ƿ�Ϊ����
bool isPerfectNumber(int num) {
    int sum = 1; // 1����һ������
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) sum += num / i; // ����ƽ�������ظ�������
        }
    }
    return sum == num && num != 1;
}

int main() {
    int start, end;
    cout << "������������������";
    cin >> start >> end;

    vector<int> perfectNumbers;
    for (int i = start; i <= end; i++) {
        if (isPerfectNumber(i)) {
            perfectNumbers.push_back(i);
        }
    }

    // �������Ļ
    cout << "�����У�";
    for (int num : perfectNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // ������ļ�
    ofstream outFile("result.txt");
    if (outFile.is_open()) {
        outFile << start << " " << end << endl;
        for (int num : perfectNumbers) {
            outFile << num << " ";
        }
        outFile << endl;
        outFile.close();
    } else {
        cout << "�޷����ļ�" << endl;
    }

    return 0;
}