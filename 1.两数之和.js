/*
 * @lc app=leetcode.cn id=1 lang=javascript
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let maps=new Map();
    for (let i=0;i<nums.length;i++){ 
        if (maps.has(target-nums[i])){     
        //说明已有对应元素在maps中，应该先返回小的索引
            return [maps.get(target-nums[i]),i];
        }
        //不存在则保存数值+下标
        maps.set(nums[i],i);
        //test16:33
    }
};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = twoSum;
// @after-stub-for-debug-end