#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfFour(int n) {
    if (n == 1) return true;
    if(n < 0) return false;
    while(n){
        if(n == 4) return true;
        if(n % 4) return false;
        n = n / 4;
    }
    return false;//象征性

}

int main()
{
   int n = 8;
   bool ans = isPowerOfFour(n);
   cout << ans << endl;
   return 0;
}
