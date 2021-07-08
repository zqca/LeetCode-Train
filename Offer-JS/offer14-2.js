/**
 * @param {number} n
 * @return {number}
 * @在14-1的基础上，使用BigInt完成大数计算。
 * @因为Math.max不能求BigInt类型的最值，所以我们要自己写一个max函数判断最值。
 */

let max = function (a, b){
    return a > b ? a : b;
}
var cuttingRope = function(n) {
    if(n === 2) return 1;
    let dp = new Array(1 + n).fill(BigInt(1));
    dp[2] = BigInt(2);//初始化
    for(let i = 3; i <= n; ++i){
        dp[i] = dp[i - 1];
        for(let j = 2; j < i; ++j){
            //前面长度j的绳子也可以不划分，作为一个整体进行使用。
            dp[i] = max(dp[i], max(dp[j] * BigInt(i - j), BigInt(j) * BigInt(i - j)));
        }
    }
    return dp[n] % BigInt(1e9 + 7);
};

console.log(cuttingRope(1000))