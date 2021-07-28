/**
 * @param {number[]} nums
 * @return {number[]}
 * 计算z=x ^ y，找到z中最低哪一位m是1（说明x与y在这一位上有区别）
 * 根据第m位为0或1，将原数组划分为两类。因此x,y就分开了
 */
var singleNumbers = function(nums) {
    let z = 0;
    for (let i = 0; i < nums.length; ++i){
        z = z ^ nums[i];
    }
    let m = 1;
    while((z & m) === 0){
        m = m << 1;
    }
    let a = 0, b = 0;
    for (let i = 0; i < nums.length; ++i){
        if(nums[i] & m){
            a = a ^ nums[i];
        }
        else{
            b = b ^ nums[i];
        }
    }

    return [a, b];

};