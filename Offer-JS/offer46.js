/**
 * @param {number} num
 * @return {number}
 * dp[i] = dp[i-1] + dp[i-2],如果0<=num[i-1]num[i]<=25
 *       = dp[i-1]          ,默认
 */
var translateNum = function(num) {
    let str = String(num);
    let len = str.length;
    let dp = Array( len + 1);
    str = '#' + str;
    dp[0] = 1;
    dp[1] = 1;//第一个数字
    for(let i = 2; i <= len; ++i){
        dp[i] = dp[i - 1];
        let tmp = parseInt(str[i - 1] + str[i]);//默认两位数
        if(tmp >= 10 && tmp <= 25){
            dp[i] += dp[i - 2];
        }
    }
    return dp[len];

};

//debug
let num = 12258;
console.log(translateNum(num))