#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 函数用于判断一个数是否为完数
bool isPerfectNumber(int num) {
    int sum = 1; // 1总是一个因子
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) sum += num / i; // 避免平方根被重复加两次
        }
    }
    return sum == num && num != 1;
}

int main() {
    int start, end;
    cout << "请输入两个正整数：";
    cin >> start >> end;

    vector<int> perfectNumbers;
    for (int i = start; i <= end; i++) {
        if (isPerfectNumber(i)) {
            perfectNumbers.push_back(i);
        }
    }

    // 输出到屏幕
    cout << "完数有：";
    for (int num : perfectNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // 输出到文件
    ofstream outFile("result.txt");
    if (outFile.is_open()) {
        outFile << start << " " << end << endl;
        for (int num : perfectNumbers) {
            outFile << num << " ";
        }
        outFile << endl;
        outFile.close();
    } else {
        cout << "无法打开文件" << endl;
    }

    return 0;
}