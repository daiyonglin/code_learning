#include <iostream>
using namespace std;
int main()
{
  long long sum = 20250601;
  int ans = sum;
    while(ans--){
        if(ans % 305 == 0){
            cout<<ans<<endl;
            break;
        }
        else{
            continue;
        }

    }
  return 0;
}