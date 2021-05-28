#include <iostream>
#include <vector>

using namespace std;

int totalHammingDistance(vector<int> &nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int c = 0;//所有数字中，第i位是1的数字个数
            for (int val : nums) {
                c += (val >> i) & 1;
            }
            ans += c * (n - c);//所有数字在第i位的汉明距离
        }
        return ans;
    }

int main()
{
   vector<int> nums = {4,14,2};
   int ans = totalHammingDistance(nums);
   cout << ans << endl;
   return 0;
}
