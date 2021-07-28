/**
 * @param {number[]} nums
 * @return {number}
 * 所有数字相同位上的数字之和%3，即为ans在这一位上的数字
 */
var singleNumber = function(nums) {
    let res = 0;
    for (let i = 0; i < 32; i++) {
        let cnt = 0;
        let bit = 1 << i;//第i位是1的数
        for (let j = 0; j < nums.length; j++) {
            if (nums[j] & bit) cnt++;
        }
        if (cnt % 3 !== 0){
            //不用考虑cnt % 3 = 0的情况
            res = res | bit;
        }
    }
    return res;
};