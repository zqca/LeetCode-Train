/**
 * @param {number} n
 * @return {number}
 * 动态规划，dp[i]表示绳子总长度为i的结果
 */
var cuttingRope = function(n) {
    if(n === 2) return 1;

    let dp = Array(1 + n);
    dp[1] = 1;
    dp[2] = 2;//初始化
    for(let i = 3; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(let j = 2; j < i; ++j){
            //前面长度为j的绳子也可以不划分，作为一个整体进行使用。
            dp[i] = Math.max(dp[i], Math.max(dp[j] * (i - j), j * (i - j)));
        }
    }
    return dp[n];
};

console.log(cuttingRope(10))