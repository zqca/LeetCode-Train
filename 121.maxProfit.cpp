#include <iostream>
#include <vector>

using namespace std;

//贪心
int maxProfit1(vector<int>& prices) {
    
    if(prices.size() < 2) return 0;
    int ans = 0;
    int min;
    int i;
    for( i = 1; i < prices.size(); i++) {
        //目的是找到一个买入点和可能的卖出点
        if(prices[i] > prices[i - 1]) {
            min = prices[i - 1];//买入价
            ans = prices[i] - prices[i - 1];
            break;//最后i停留在max处
        }
    }

    for(i = i + 1; i < prices.size(); i++) {
        if(prices[i] > min) {//有利
            //遇到了更高的价
            if(prices[i] - min > ans) {
                ans = prices[i] - min;
            }  
        }
        else {
            min = prices[i];
        }
    }

    return ans;

}

int maxProfit2(vector<int>& prices) {
    if(prices.size() < 2) return 0;
    vector <vector<int> > dp(prices.size(), vector<int>{0,0});
    //dp[i][0] 表示第i天持有股票收益，dp[i][1]表示第i天不持有股票收益
    dp[0][0] = - prices[0];
    dp[0][1] = 0;
    for(int i = 1; i < prices.size(); i++) {
        // i天持有股票，说明还没有卖 @ 前一天持有股票； 或者，前一天不持有，今天买入
        dp[i][0] = max(dp[i - 1][0], - prices[i]);
        // i天不持有股票的收益 @ 前一天持有，今日卖了； 或者，前一天不持有，今天不动
        dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
    }
    return dp[prices.size() - 1][1];
    //最后一天只有是不持有的状态（不一定最后一天卖出）才能获利
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit2(prices);
    cout << ans << endl;

    return 0;
}