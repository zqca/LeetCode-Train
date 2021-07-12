/**
 * @param {number[]} nums
 * @return {number[]}
 * 需要额外的空间
 */
var exchange0 = function(nums) {
    let ans = [];
    for(let i = 0; i < nums.length; ++i){
        if(nums[i] % 2){
            ans.unshift(nums[i]);
        }
        else{
            ans.push(nums[i]);
        }
    }
    return ans;

};

/**
 * @param {number[]} nums
 * @return {number[]}
 * 快慢指针，原地改造；慢指针确定填入的位置，快指针寻找奇数
 */
var exchange = function(nums) {
    let len = nums.length;
    let slow = 0, fast = 0;
    let tmp;
    while(fast < len){
        if(nums[fast] % 2){
            tmp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = tmp;
            ++slow;
        }
        ++fast;
    }

    return nums;
};