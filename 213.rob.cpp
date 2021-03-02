#include <iostream>
#include <vector>

using namespace std;

int robRange(vector<int>& nums) {

    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];

    vector<int> dp(nums.size(), 0);//考虑过i后最大收益
    vector<int> visited(nums.size());

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[nums.size() - 1];
}

int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    //不考虑第一个元素，或者不考虑最后一个元素 
    vector<int> tmp1(nums.begin(), nums.end() - 1);
    vector<int> tmp2(nums.begin() + 1, nums.end());
    return max(robRange(tmp1), robRange(tmp2));
}

int main() {
    vector<int> nums = {2};
    
    cout << rob(nums) << endl;//3

    return 0;

}