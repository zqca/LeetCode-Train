#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int ans = 0;
    if(prices.size() == 0) return ans;

    vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
    //dp[i][0] 当天是持有状态；dp[i][1] 当天不持有

    dp[0][0] = - prices[0];

    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }

    return dp[prices.size() - 1][1];

}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int ans = maxProfit(prices, fee);
    cout << ans << endl;
    return 0;

}