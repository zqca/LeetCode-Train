#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    //在nums中寻找两类数，Positive ,Negative,满足:
    //P - N = target; P + N = sum(nums);
    //因此 P = (target + sum) / 2;找到和为P的数字即可，剩下的数字作为N
    int sum = 0;
    for(auto x : nums){
        sum += x;
    }
    if((sum + target) % 2){
        return 0;//不能整除，结束
    }
    int P = (int)(sum + target) / 2;
    int len = nums.size();
    //定义dp[i][j]是考虑前i个数，和为j的方法数
    vector<vector<int> > dp(1 + len, vector<int>(P + 1, 0));
    dp[0][0] = 1;//初始化
    for(int i = 1; i <= len; ++i){
        int num = nums[i - 1];//细节！！
        for(int j = 0; j <= P; ++j){
            dp[i][j] = dp[i - 1][j];//不选现在的这个数

            if(j - num >= 0){
                dp[i][j] += dp[i - 1][j - num]; 
            }
        }
    }

    return dp[len][P];
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int S = 3;
    int ans = findTargetSumWays(nums, S);//ans = 5;

    cout << ans;

    return 0;
}