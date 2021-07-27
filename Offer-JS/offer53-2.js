/**
 * @param {number[]} nums
 * @return {number}
 * 找到第一个index和值不对应的index,返回index
 */
var missingNumber = function(nums) {
    let l = 0, r = nums.length - 1, mid;
    while (l < r){
        mid = Math.floor(l + (r - l) / 2);
        if(nums[mid] === mid){
            //目标在后面
            l = mid + 1;
        }
        else{
            //目标在前面
            r = mid;
        }
    }
    if(nums[r] === r){
        return r + 1;
    }
    return r;
};