#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    
    vector<int> dp(nums.size(),0);//以nums[i]结尾的子序列的和,防止溢出
    dp[0] = nums[0];
    int result = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(dp[i - 1] < 0) {
            dp[i] = nums[i];
        }
        else {
            dp[i] = nums[i] + dp[i - 1];
        }
        result = max(result,dp[i]);
    }
    return result;
}

int main() {
    vector<int> nums = {-2}; //-2,1,-3,4,-1,2,1,-5,4

    int ans = maxSubArray(nums);
    cout << ans << endl;

    return 0;
}
  