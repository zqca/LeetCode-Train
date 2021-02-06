/*
 * @lc app=leetcode.cn id=349 lang=javascript
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let set1 = new Set(nums1);//集合初始化
    let set2 = new Set(nums2);
    let result = new Array();

    for (let item of set1){//注意是of,集合不能通过索引访问
        if(set2.has(item)){
            result.push(item);
        }
    }
    return result;

};
// @lc code=end

