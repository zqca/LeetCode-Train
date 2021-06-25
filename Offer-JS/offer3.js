/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let hash = new Map();
    for(let i of nums){
        if(hash.has(i)){
            return i;
        }
        else {
            hash.set(i,0);
        }
    }
};

let nums = [0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
let ans = findRepeatNumber(nums);
console.log(ans)