/*
 * @lc app=leetcode.cn id=18 lang=javascript
 *
 * [18] 四数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */

var threeSum = function(nums, target) {
    nums.sort((a,b) => a-b); //升序
    let len = nums.length;
    let ans = new Array();//存放最终的答案

   
    let i, left, right, cur;

    for (i = 0; i < len; i++) {

        left = i + 1;
        right = len -1;
        while (left < right) {
            cur =  nums[i] + nums[left] + nums[right];
            if (cur == target) {
                ans.push([nums[i], nums[left], nums[right]]);

                //在同一个i下，left要跳过同样的元素
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;//只动一个，让另一个被动地改变
                }
                left++;
            }
            else if (cur > target) {
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

var fourSum = function(nums, target) {
    nums.sort((a,b) => a-b); 
    let len = nums.length;
    let newans = new Array();//存放最终的答案
    //优化：去除两种极端
    if (nums[0] > 0 || nums[len] < 0) return newans;
    let i;

    for(i = 0;i < len - 3; i++) {
        //例如[0,1,2,3,4,5,6]，i=0开始取，直到3；在剩下的数组里面寻找三数之和
        let oldans=threeSum(nums.slice(i + 1, len), target - nums[i]);
        for(let index = 0; index < oldans.length; index++) {
            newans.push([nums[i]].concat(oldans[index]));
        }

        //在一个i固定时找到了所有的元组，接下来应该跳到不同的i
        while (nums[i] == nums[i + 1]) {
            i++;
        }//此时停留在最后一个重复的i上，由for循环更新到下一个没计算过的i    
            //可以写成 while (nums[i] == nums[++i])            
    }
    return newans;



   
    


};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = fourSum;
// @after-stub-for-debug-end