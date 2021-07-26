/**
 * @param {string} s
 * @return {number}
 * dp[i]表示以当前元素结尾的最长不重复子串的长度
 * mp记录某个元素最后出现的index
 */
var lengthOfLongestSubstring = function(s) {
    let len = s.length;
    let ans = 1;//最终答案
    if(len < 2) return len;
    let dp = Array(len);
    let mp = new Map();
    mp[s[0]] = 0;
    dp[0] = 1;
    let last;//最后出现的位置
    for(let i = 1; i < len; ++i){
        last = mp[s[i]];
        if(last === undefined || last < i - dp[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = i - last;
        }
        ans = Math.max(ans, dp[i]);
        mp[s[i]] = i;//更新记录字符最后出现的index
    }
    return ans;
};

//方法2，双指针
/**
 * @param {string} s
 * @return {number}
 * 闭区间的双指针
 */
var lengthOfLongestSubstring = function(s) {
    let len = s.length;
    let ans = 1;//最终答案
    if(len < 2) return len;
    let mp = new Map();
    mp[s[0]] = 0;
    let last;//最后出现的位置
    let left = 0, right = 0;
    let tmp;//区间长度

    while(right + 1 < len){
        ++right;//扩大区间
        last = mp[s[right]];
        if(last === undefined || last < left){
            tmp = right - left + 1;
            ans = Math.max(ans,tmp);
        }
        else{
            left = last + 1;
        }

        mp[s[right]] = right;
    }
    return ans;
};

//debug

let s = "bbb";
console.log(lengthOfLongestSubstring(s))

