/*
 * @lc app=leetcode.cn id=209 lang=javascript
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
/**
 * @param {number} s
 * @param {number[]} nums
 * @return {number}
 */

//TODO:使用滑动窗口，重点
var minSubArrayLen = function(s, nums) {
    let minLen = Number.MAX_SAFE_INTEGER;//需要设置一个很大的值
    let i = 0;
    let j;//窗口起点,终点
    let curLen;//当前窗口长度
    let sum = 0;//窗口内的和
    for(j = 0; j < nums.length; j++) {
        sum += nums[j];
        if(sum >= s) {
            //窗口内的和已经符合要求，试图缩小窗口。
            //显然窗口的终点j已经不能再变大了，变小也没意义,试图变大起点i来缩小窗口
            //缩小窗口的前提是，窗口的和符合条件
            while(sum >= s) {
                curLen = j - i + 1;
                minLen = minLen < curLen ? minLen : curLen;
                sum -= nums[i];
                i++;
            }

        }
    }
    //有可能没有找到，需要返回0
    return minLen == Number.MAX_SAFE_INTEGER ? 0 : minLen;
}


//TODO:暴力，最后一个样例超时不通过
/*
function curWin(wid, s, nums){
    //输入当前窗口的宽度，返回最小长度curmin
    let len = nums.length;
    let curmin = 0;
    let sum;
    for(let i = 0; i < len - wid + 1; i++) {
        sum = nums.slice(i, wid + i).reduce((pri,cur)=>pri+cur);
        if (sum >= s) {
            curmin = wid;
            break; 
        }
    }
    return curmin;
}

var minSubArrayLen = function(s, nums) {
    let i;//窗口大小
    let res = 0;//最终结果
    for(i = 1; i < nums.length + 1; i++) {
        res = curWin(i, s, nums);
        if(res) {
            return res;
        }
    }
    return 0;//最终没找到
};


*/
// @lc code=end


// @after-stub-for-debug-begin
module.exports = minSubArrayLen;
// @after-stub-for-debug-end