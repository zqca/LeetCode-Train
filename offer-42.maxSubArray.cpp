#include <iostream>
#include <vector>

using namespace std;


int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size(),INT32_MIN);
    //以i结尾的的数组中de 最大连续和
    dp[0] = nums[0];
    int ans = dp[0];

    for(int i = 1; i < nums.size(); i++) {
        if(dp[i - 1] > 0) {
            dp[i] = dp[i - 1] + nums[i];
        }
        else {//因为前面的和是负的，加上当前的数会比当前的数更小，所以重新开头
            dp[i] = nums[i];
        }
        ans = ans < dp[i] ? dp[i] : ans;
        
    }

    return ans;

}

int main () {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans =  maxSubArray(nums);

    cout << ans << endl;
    return 0;
}