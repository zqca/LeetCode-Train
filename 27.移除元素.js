/*
 * @lc app=leetcode.cn id=27 lang=javascript
 *
 * [27] 移除元素
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */

/*方法1
var removeElement = function(nums, val) {
    let rawLen = nums.length;
    let i = 0, j = 0, k=0, count = 0 ;//count记录剩下的个数
    
    let flags = new Array(rawLen);
    for (k = 0; k < rawLen; k++) {
        flags[k] = 0;//表示没有被修改过
    }

    for (; i < rawLen; i ++) {
        if (nums[i] != val && !flags[i]) {
            count++;
            j++;
            continue;
        } 

        //此时位置i是需要删除的值，从i+1开始寻找不是val的位置
        j = j + 1;

        while ( j < rawLen ) {
            if (nums[j] != val) {
                //找到了下一个要保留的元素
                count++;
                nums[i] = nums[j];
                flags[j] = 1;
                //表示这个值已经被移到前面，下次访问到这要修改
                break;
            }
            else {
                j++;
            } 
        }
      
    }

    return count;


};
*/
/*方法2:双指针 重点*/ 
var removeElement = function(nums, val) {
    let slow = 0, fast = 0;//快慢两个指针
    let len = nums.length;
    while (fast < len) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast++];
        }
        else {
            while (fast < len) {
                if (nums[fast] != val) {
                    nums[slow++] = nums[fast++];
                    break;
                }
                else {
                    fast++;
                }
            }
        }
    }
    return slow;
}


// @lc code=end


// @after-stub-for-debug-begin
module.exports = removeElement;
// @after-stub-for-debug-end