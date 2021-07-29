/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 * hash表
 */
var twoSum = function(nums, target) {
    if(nums.length === 1) return [];
    let mp = new Map();
    for(let x of nums){
        if(mp.has(target - x)){
            return [x, target - x];
        }
        mp.set(x, x);
    }
};

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 * 有序的，可以使用双指针
 */
var twoSum = function(nums, target) {
    let i = 0, j = nums.length - 1;
    let ans = [];
    while(i < j){
        if(nums[i] + nums[j] === target){
            ans[0] = nums[i];
            ans[1] = nums[j];
            break;
        }
        if(nums[i] + nums[j] < target) {
            ++i;
        }
        else{
            --j;
        }
    }
    return ans;
};