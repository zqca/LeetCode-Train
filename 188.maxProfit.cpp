#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    if(prices.size() < 2) return 0;
    vector <vector<int> > dp(prices.size(), vector<int>(2 * k + 1, 0));
    //dp[i][0] 表示当天不操作

    //dp[i][1] 表示第i天第1次持有股票(买入状态)
    //dp[i][2] 表示第i天第1次不持有股票(卖出状态)
    //dp[i][3] 表示第i天第2次持有股票(买入状态)
    //dp[i][4] 表示第i天第2次不持有股票(卖出状态)

    //dp[i][2k-1] 表示第i天第k次持有股票(买入状态)
    //dp[i][2k] 表示第i天第k次不持有股票(卖出状态)

    //初始化
    for(int i = 1; i <= k; i++) {
        dp[0][2 * i - 1] = - prices[0];
    }

    int flag = 1;

    for(int i = 1; i < prices.size(); i++) {//i是天数
        
        //截止到今天都是没有交易，因此沿用前一天的无交易状态
        dp[i][0] = dp[i - 1][0];

        for(int j = 1; j <= 2 * k; j++) {//j是当天的状态
            flag *= -1;
            //维持昨天的状态，或者今天进行操作
            //flag = -1表示买入，等于1表示卖出
            dp[i][j] = max(dp[i - 1][j - 1] + flag * prices[i], dp[i - 1][j]);
        }  

    }
    return dp[prices.size() - 1][2 * k];
    //最后一天只有是不持有的状态（不一定最后一天卖出）才能获利

}


int main() {
    vector<int> prices = {3,2,6,5,0,3};//
    int k = 2;
    int ans = maxProfit(k, prices);//7
    cout << ans << endl;

    return 0;
}