#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
    int y = 0;
    while(x != 0){
        if(y > INT32_MAX/10 || y < INT32_MIN/10) return 0;
        y = y * 10 + x % 10;
        x = x / 10;
    }
    return y;
}

int main()
{
   int x = 1200;
   int ans = reverse(x);
   cout << ans << endl;
   return 0;
}
