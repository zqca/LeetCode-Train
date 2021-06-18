#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long nVal = stol(n);
        long long mMax = floor(log(nVal) / log(2));//m的上界
        //给定m,使用二分法确定是否存在符合要求的k
        long long low, high;
        long long mid, sum;

        for (int m = mMax; m > 1; m--) {//k越小m越大，为了找到小的k，需要倒着遍历m.
            low = 2, high = powl(nVal, 1.0 / m) + 1;
            while (low < high) {
                mid = (low + high) / 2;
                sum = 1;
                for (int j = 0; j < m; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == nVal) {
                    return string(to_string(mid));
                }
                else if (sum < nVal) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
        }
        return to_string(nVal - 1);
    }
};

int main()
{
   Solution solution;
   string n = "13";
   string ans = solution.smallestGoodBase(n);
   cout << ans << endl;
   return 0;
}
