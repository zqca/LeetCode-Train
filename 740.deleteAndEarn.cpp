#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    int max_num = *max_element(nums.begin(), nums.end());//获取最大元素
    vector<int> count(max_num + 1, 0);//开固定长度的数组统计出现次数
    for ( int num : nums ) {
        count[num] += num;//如果需要删除当前数字，先把当前数字全部删除来获得点数
    }

    vector<int> dp(max_num + 1, 0);//考虑数字i后的最大收益
    dp[1] = count[1];//按照题意，数字大于1，设置dp[0]方便操作
    for ( int i = 2; i <= max_num; ++i ) {
        dp[i] = max(dp[i - 1], dp[i - 2] + count[i]);
    }
    return dp[max_num];
}

int main()
{
   vector<int> nums = {2,3,3,3,4};
   int ans = deleteAndEarn(nums);
   cout << ans << endl;
   return 0;
}



