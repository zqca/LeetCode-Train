/**
 * @param {number} n
 * @return {number}
 * @在14-1的基础上，使用BigInt完成大数计算。
 * @因为Math.max不能求BigInt类型的最值，所以我们要自己写一个max函数判断最值。
 */

let max = function (a, b){
    return a > b ? a : b;
}
var cuttingRope_bad = function(n) {
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


/**
 * 使用数学的方法，尽可能使每段绳子的长度为3（涉及到求导的驻点e）
 * 如果剩下的绳子长度为4，拆成2+2而不是3+1,
 * 如果剩下的绳子长度是1，借一个3，拆成2+2
 * @param n
 */

var cuttingRope_pro = function(n){
    if(n == 2) return 1;
    if(n == 3) return 2;

    let ans = 1;

    let md = 1e9 + 7;

    while(n > 4){
        ans = (3 * ans) % md;
        n = n - 3;
    }
    if (n == 2){
        ans = (2 * ans) % md;
    }
    if(n == 3){
        ans = (3 * ans) % md;
    }
    if (n == 4){
        ans = (4 * ans) % md;
    }

    return  ans;
}

console.log(cuttingRope_bad(1000))
console.log(cuttingRope_pro(1000))