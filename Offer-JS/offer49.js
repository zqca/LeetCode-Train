/**
 * @param {number} n
 * @return {number}
 * 每一个数最终都需要*2,*3,*5。因此用3个变量(next_x_i)保存下一个需要*i的index
 */
var nthUglyNumber = function(n) {
    let dp = [];
    dp[1] = 1;

    let next_x_2 = 1;
    let next_x_3 = 1;
    let next_x_5 = 1;
    for(let i = 2; i <= n; ++i){
        let tmp2 = dp[next_x_2] * 2;
        let tmp3 = dp[next_x_3] * 3;
        let tmp5 = dp[next_x_5] * 5;
        dp[i] = Math.min(tmp2, tmp3, tmp5);

        //如果最小值和某个计算值一样，需要前进一步；
        //如果有多个计算值相同，都需要前进，因为要求dp内的数字递增，这几个用过的位置都不能继续使用了
        if(dp[i] === tmp2) ++next_x_2;
        if(dp[i] === tmp3) ++next_x_3;
        if(dp[i] === tmp5) ++next_x_5;
    }
    return dp[n];
};

//debug
let n = 10;
console.log(nthUglyNumber(n))