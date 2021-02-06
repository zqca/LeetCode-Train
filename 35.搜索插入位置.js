/*
 * @lc app=leetcode.cn id=35 lang=javascript
 *
 * [35] 搜索插入位置
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    //1、暴力比较，直到找到合适位置；2、二分法（重点）
    //情况1:直接找到
    //情况2：夹在中间
    //情况3：插在最前面
    //情况4：插在最后面
    let min = 0, max = nums.length - 1;
    //最大以及最小索引位置，max一定要注意减1
    let mid;

    while (min <= max){
        mid = Math.floor(min + ((max - min) >> 1));//除以2

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    //情况2：【1,3】，2；最后索引min=1,max=0, 需要返回min=max+1
    //情况3：【1,3】，0；最后索引min=0,max=-1,需要返回min=max+1
    //情况4：【1,3】，4；最后索引min=2,max=1, 需要返回min=max+1
    return max + 1;

};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = searchInsert;
// @after-stub-for-debug-end