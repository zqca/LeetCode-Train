#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    //完全背包
    vector<int> dp(amount + 1, INT32_MAX);//凑成总额为i的最小硬币个数方法
    dp[0] = 0;

    for(int j = 0; j <= amount; j++) {
        for(int i = 0; i < coins.size(); i++) {
            if(j - coins[i] >= 0) {

                if(dp[j - coins[i]] == INT32_MAX) {
                    //什么也不做，保持不变
                }
                else {
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
                
            }
        }
    }

    return dp[amount] == INT32_MAX ? -1 : dp[amount];

}

int main() {
    vector<int> coins = {2,5,10,1};
    int amount = 27;
    int ans = coinChange(coins, amount);//4
    cout << ans << endl;

    return 0;

}