/**
 * @param {number[]} prices
 * @return {number}
 * dp[i][0]当晚不持有，dp[i][1]当晚持有所得到的利润。
 * 优化后只需要两个变量即可
 */

var maxProfit = function (prices) {
    // if(prices.length < 2){
    //     return 0;
    // }
    //第一天结束
    let have = -prices[0];//可能是NaN，无所谓
    let notHave = 0;

    for (let i = 1; i < prices.length; ++i) {
        have = Math.max(have, -prices[i]);//当天不买，或者当天买入
        notHave = Math.max(notHave, have + prices[i]);//当天不卖，或者当天卖掉
    }

    return notHave;
};