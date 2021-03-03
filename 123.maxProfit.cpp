#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) return 0;
    vector <vector<int> > dp(prices.size(), vector<int>(5,0));
    //dp[i][0] 表示当天不操作
    //dp[i][1] 表示第i天第1次持有股票(买入状态)
    //dp[i][2] 表示第i天第1次不持有股票(卖出状态)
    //dp[i][3] 表示第i天第2次持有股票(买入状态)
    //dp[i][4] 表示第i天第2次不持有股票(卖出状态)
    dp[0][0] = 0;
    dp[0][1] = - prices[0];
    dp[0][2] = 0;
    dp[0][3] = - prices[0];//不用管第几次，现在手头上没有现金，只要买入，现金就做相应的减少
    dp[0][4] = 0;


    for(int i = 1; i < prices.size(); i++) {
        
        //截止到今天都是没有交易，因此沿用前一天的无交易状态
        dp[i][0] = dp[i - 1][0];

        //1.之前都没操作，今天买入；2.维持昨天第1次买入的状态
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);

        //1.之前都没卖出，今天卖出；2.维持昨天第1次卖出的状态
        dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);

        //下面开始第二次交易

        //1.之前都没操作，今天买入；2.维持昨天第2次买入的状态
        dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);

        //1.之前都没卖出，今天卖出；2.维持昨天第2次卖出的状态
        dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);

    }
    return dp[prices.size() - 1][4];
    //最后一天只有是不持有的状态（不一定最后一天卖出）才能获利
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};//6
    int ans = maxProfit(prices);
    cout << ans << endl;

    return 0;
}