#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);//实现和为i的排列种类数
    dp[0] = 1;
    for(int j = 0; j <= target; j++) {
        //先遍历背包
        for(int i = 0; i < nums.size(); i++) {
            //再遍历物品
            if(j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) {//防止溢出，题意保证最终结果不溢出
                dp[j] += dp[j - nums[i]];
            }
            
        }
    }

    return dp[target];

}

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;
    int ans = combinationSum4(nums, target);

    cout << ans;

    return 0;
}