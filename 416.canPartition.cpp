#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    //答案只要回答能不能
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    if (sum % 2) return false;//奇数不能

    //转化为 给定容量为nums.size()/2的背包，每个数字都是物品，物品的质量为对应的数字，价值为对应的数字
    //问，这个背包装满之后的价值是不是等于sum/2
    vector<int> dp(sum + 1, 0);//背包为0,1,2,...sum/2
    for(int i = 0; i < nums.size(); i++) {
        //i是物品
        for(int j = dp.size() - 1; j >= nums[i]; j--) {
            //j是背包容量
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    
    return dp[sum/2] == sum/2;

}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums);

    return 0;
}