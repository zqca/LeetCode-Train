/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {

    if(nums.length === 0) return 0;

    let binary_search = function (nums, target){
        let l = 0, r = nums.length - 1, mid;
        //找target左边界,如果不存在返回的是应该插入的位置
        while (l < r){
            mid = Math.floor(l + (r - l) / 2);
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        if(r === nums.length - 1 && nums[r] < target){
            return r + 1;//已经到末尾了，如果最后一个元素还小于target
        }
        return r;
    }
    let a = binary_search(nums, target);
    let b = binary_search(nums, target + 1);

    return b - a;
};

//debug
let nums = [5,7,7,8,8,10], target = 8;
console.log(search(nums, target))