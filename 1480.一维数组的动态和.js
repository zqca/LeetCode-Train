/*
 * @lc app=leetcode.cn id=1480 lang=javascript
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let res=new Array();
    res[0]=nums[0];
    for (let i=1; i<nums.length; i++) {
        res[i]=res[i-1]+nums[i];
        // temp+=nums[i];
        // res.push(temp);
    }
    return res;

};
// @lc code=end

