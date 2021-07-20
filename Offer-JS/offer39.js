/**
 * @param {number[]} nums
 * @return {number}
 * 排序后取中间
 */
var majorityElement = function(nums) {
    nums.sort();
    return nums[Math.floor(nums.length / 2)];
};