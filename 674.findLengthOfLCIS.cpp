#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int ans = 1;
    if(nums.size() < 2) return nums.size();

    vector<int> dp(nums.size(), 1);//到i为止，连续增序列的长度

    for (int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            ans = max(ans, dp[i]);
        }
    } 

    return ans;
}

int main() {
    vector<int> nums = {2,2,2};
    int ans = findLengthOfLCIS(nums);
    cout << ans << endl;
    return 0;
}