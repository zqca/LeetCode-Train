/**
 * @param {number[]} nums
 * @return {boolean}
 * 需要统计0的数量
 */
var isStraight = function (nums) {
    let arr = Array(14).fill(0);//0,1,2...13
    let min = 999, max = -999;
    for (let x of nums) {
        if (x !== 0 && arr[x]) return false;//有非0的重复
        if (x !== 0) {
            min = min > x ? x : min;
            max = max > x ? max : x;
        }
        ++arr[x];
    }

    for (let i = min + 1; i < max; ++i) {
        if (arr[i] === 0) {
            if (arr[0] > 0) {
                --arr[0];
            } else {
                return false;
            }
        }
    }
    return true;
};

//debug
let nums = [0, 12, 11, 11, 0]
console.log(isStraight(nums));