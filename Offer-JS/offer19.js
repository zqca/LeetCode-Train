/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let m = s.length;
    let n = p.length;
    let dp = [];
    for(let i = 0; i < m + 1; ++i){
        dp[i] = [];
        for(let j = 0; j < n + 1; ++j){
            dp[i][j] = 0;
        }
    }
    //初始化
    dp[0][0] = 1;
    for(let j = 2; j < n + 1; j = j + 2){
        dp[0][j] = (p[j - 1] === "*") && dp[0][j - 2];
    }
    for(let i = 1; i < m + 1; ++i){
        for(let j = 1; j < n + 1; ++j){
            //如果p[j-1]="*",考虑一下3种情况
            //忽视最后两个字符，让*前面的字母出现一次，*前面的是.
            if(p[j - 1] === "*"){
                //正常的输入不会p[0]="*"
                dp[i][j] = (dp[i][j - 2]) || (dp[i - 1][j] && (p[j - 2] === s[i - 1] || p[j - 2] === "."));
            }
            else{
                dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] === s[i - 1] || p[j - 1] === ".");
            }
        }
    }
    return dp[m][n];
};

let s = "aab"
let p = "c*a*b";
console.log(isMatch(s, p));