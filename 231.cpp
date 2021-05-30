#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfTwo(int n) {
    if(n == 1) return true;//奇数
    if(n == 0 || n % 2) return false;//0,奇数

    while(n != 1){
        if((n & 1)){
            return false;
        }
        n = n >> 1;
    }

    return true;

}

int main()
{
   int n = 8;
   bool ans = isPowerOfTwo(n);
   cout << ans << endl;
   return 0;
}
