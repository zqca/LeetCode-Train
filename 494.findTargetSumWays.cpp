#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    //目标和S是正数和负数没有区别，因此考虑正数
    int sum = 0;
    for(int i : nums) sum += i;
    if( S < 0) S *= -1;

    if(S > sum) return 0;

    vector<int> row(sum + 1, 0);
    vector<vector<int> > dp(nums.size(), row);
    //dp[i][j]表示前i个数实现目标j的方法数

    int tmp;

    //初始化,需要区分
    if(nums[0] == 0) {
        dp[0][nums[0]] = 2;
    }
    else {
        dp[0][nums[0]] = 1;
    }
    
    for(int i = 1; i < nums.size(); i++) {
        
        tmp = nums[i];
        if(tmp == 0) {
            for(int j = sum; j >= 0; j--) {
                dp[i][j] = dp[i - 1][j] *2;
            }
        }
        else {
            for(int j = sum; j >= 0; j--) {
                if(j + tmp <= sum) dp[i][j] += dp[i - 1][j + tmp];
                if(abs(j - tmp) <= sum) dp[i][j] += dp[i - 1][abs(j - tmp)];
            }
        }  
    }

    return dp[nums.size() - 1][S];

}

int main() {
    vector<int> nums = {0,0,1};
    int S = 1;
    int ans = findTargetSumWays(nums, S);//ans = 5;

    cout << ans;

    return 0;
}