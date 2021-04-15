#include <iostream>
#include <vector>

using namespace std;

int robRange(int start, int end, vector<int>& nums){
    if(start > end) return 0;
    //只在闭区间里考虑，首尾无关
    int len = end - start + 1;
    vector<vector<int> > dp(len, vector<int>(2, 0));//第一行不抢，第二行抢
    dp[0][1] = nums[start];
    for(int i = 1; i < len; i++){
        dp[i][0] =  max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + nums[start + i];
    }
    return max(dp[len-1][0], dp[len-1][1]);
}

int rob(vector<int>& nums) {
    int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];

    vector<int> dp(len, 0);//抢当前，能获利
    int ans = 0, left, right;

    for(int i = 0; i < len; ++i){
        if(i == 0){
            right = robRange(i + 2, len - 2, nums);
            ans = max(ans, max(0, right) + nums[i]);
        }
        else if(i == len - 1){
            left = robRange(1, i - 2, nums);
            ans = max(ans, max(left, 0) + nums[i]);
        }
        else{
            left = robRange(0, i - 2, nums);
            right = robRange(i + 2, len - 1, nums);
            ans = max(ans, max(left, right) + nums[i]);
        }
  
    }

    return ans;
    
}

int main() {
    vector<int> nums = {3,2,5,9};
    
    cout << rob(nums) << endl;//4

    return 0;

}