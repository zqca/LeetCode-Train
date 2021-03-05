#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    
    if(prices.size() == 0) return 0;

    vector<vector<int> > dp(prices.size(), vector<int>(3,0));
    //dp[i][0、1、2] 表示当天（第i天）是持有的状态、不持有且处于冷冻期、不持有且不处于冷冻期的盈亏
    dp[0][0] = - prices[0];

    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        dp[i][1] = dp[i - 1][0] + prices[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }

    return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
}

int main() {
    vector<int> prices = {};
    cout << maxProfit(prices) << endl;

    return 0;
}