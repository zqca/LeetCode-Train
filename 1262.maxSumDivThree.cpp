#include <iostream>
#include <vector>

using namespace std;

int getPair(int cur, int target, int mod) {
    return (target - cur + mod) % mod;
}

int maxSumDivThree(vector<int>& nums) {
    int mod = 3;
    int pre;//上一层互补的数
    int len = nums.size();
    vector<vector<int> > dp(len, vector<int>(mod, INT32_MIN));
    //使用前i个数能够构成的和%mod = j 的最大和

    dp[0][0] = 0;//可以不选第一个元素构成0
    dp[0][nums[0] % mod] = nums[0];//第一行初始化

    for(int i = 1; i < len; i++){
        for(int j = 0; j < mod; ++j) {
            pre = getPair(nums[i] % mod, j, mod);
            dp[i][j] = dp[i - 1][j];//这是一定满足的

            dp[i][j] = max(dp[i][j], dp[i - 1][pre] + nums[i]);
            
        }
    }

    return dp[nums.size() - 1][0];

}

int main() {
    vector<int> nums = {2,19,6,16,5,10,7,4,11,6};
    int ans = maxSumDivThree(nums);
    
    cout << ans << endl;

    return 0;

}