#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {

    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];

    vector<int> dp(nums.size(), 0);//考虑过i后最大收益
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    
    cout << rob(nums) << endl;//12

    return 0;

}