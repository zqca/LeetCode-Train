#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();

    vector<vector<int> > dp(nums.size(), {1, 1});//dp[i][0]当前元素参与子序列，dp[i][1]当前元素不参与@所构成的最大长度

    //初始化为1
    for(int i = 1; i < nums.size(); i++) {
        
        for(int j = i - 1; j >= 0; j--) {
            if(nums[j] < nums[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);//构成了更长的子序列
            }
        }
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);

}

int main() {
    vector<int> nums = {1,3,6,7,9,4,10,5,6};//ans = 6 1,3,6,7,9,4,10,5,6
    int ans = lengthOfLIS(nums);

    cout << ans << endl;
    return 0;
}