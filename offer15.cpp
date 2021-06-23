#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main()
{
   Solution solution;
   uint32_t n = 0b00000000000000000000000000001011;

   int ans = solution.hammingWeight(n);
   cout << ans << endl;
   return 0;
}
