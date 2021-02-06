/*
 * @lc app=leetcode.cn id=15 lang=javascript
 *
 * [15] 三数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

//先排序，再使用双指针
var threeSum = function(nums) {
    nums.sort((a,b) => a-b); 
    let len = nums.length;
    let ans = new Array();//存放最终的答案
    //优化：去除两种极端
    if (nums[0] > 0 || nums[len - 1] < 0) return ans;

   
    let i, left, right, cur;

    for (i = 0; i < len; i++) {
        //优化：排除第一个元素大于0,后续没有符合条件的
        if (nums[i] > 0) break;

        left = i + 1;
        right = len -1;
        while (left < right) {
            cur =  nums[i] + nums[left] + nums[right];
            if (cur == 0) {
                ans.push([nums[i], nums[left], nums[right]]);

                //在同一个i下，left要跳过同样的元素
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;//只动一个，让另一个被动地改变
                }
                left++;
            }
            else if (cur > 0) {
                //只能right向左移动，试图减小cur
                right--;
            }
            else {
                //只能left右移，试图增加cur
                left++;
            }
        }
        //在一个i固定时找到了所有的元组，接下来应该跳到不同的i
            while (nums[i] == nums[i + 1]) {
                i++;
            }//此时停留在最后一个重复的i上，由for循环更新到下一个没计算过的i    
            //可以写成 while (nums[i] == nums[++i])

    }

    return ans;

};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = threeSum;
// @after-stub-for-debug-end