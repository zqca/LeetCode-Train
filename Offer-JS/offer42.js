/**
 * dp[i]表示以当前元素的结尾的子数组的最大值
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let dp = Array(nums.length);
    dp[0] = nums[0];
    let ans = dp[0];
    for(let i = 1; i < nums.length; ++i){
        dp[i] = Math.max(nums[i], nums[i] + dp[i - 1]);
        ans = Math.max(ans, dp[i]);
    }
    return ans;
};