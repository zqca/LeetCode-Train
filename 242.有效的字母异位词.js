/*
 * @lc app=leetcode.cn id=242 lang=javascript
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length != t.length){
        return false;
    }

    let record = new Array(26);//现在全部是 undefined
    let i;
    for(i = 0; i < 26; i++){
        record[i] = 0;
    }
    for(i = 0; i < s.length; i++){
        record[s[i].charCodeAt() - 'a'.charCodeAt()]++;
        record[t[i].charCodeAt() - 'a'.charCodeAt()]--;
    }

    let flag = 1;//是否有效
    for(i = 0; i < 26; i++){
        if(record[i] != 0){
            //只要有一位不是0就不同
            return false; 
        }
    }

    return true;
    
};
// @lc code=end


// @after-stub-for-debug-begin
module.exports = isAnagram;
// @after-stub-for-debug-end