#include<iostream>
using namespace std;
int main() {
    double PAI=0;
    int n = 1;
    while (n <= (1e6 + 1) / 2)//满足这个条件就执行下面的运算，一直循环到不满足这个条件再结束
    {
        //奇数项，加
        if (n % 2 != 0) {//n%2 != 0表示n除2取余不为0，那就是奇数
            PAI += (4.0 / (2 * n - 1));//注意一定是4.0去除，不然会自动取整，最后PAI怎么算都是3
            n++;
        }
        //偶数项，减
        else {
            PAI -= (4.0/ (2 * n - 1));
            n++;
        }
    }
    cout <<"PAI的近似值为:"<<PAI << endl;
    return 0;
}