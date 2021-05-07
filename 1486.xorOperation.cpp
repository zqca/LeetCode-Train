#include <iostream>
#include <vector>

using namespace std;

int xorOperation(int n, int start) {
    int ans = 0;
    int tmp;
    for(int i = 0; i < n; i++) {
        tmp = start + 2 * i;
        ans = ans ^ tmp;
    }
    return ans;

}

int main()
{
   int n = 4;
   int start = 3;
   int ans = xorOperation(n, start);
   cout << ans << endl;
   return 0;
}
