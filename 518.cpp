#include <iostream>
#include <vector>

using namespace std;

int change(int amount, vector<int>& coins) {
    if(amount == 0) return 1;
    int len = coins.size();
    if(len == 0) return 0;
    vector<vector<int> > dp(1 + len, vector<int>(amount + 1, 0));
    dp[0][0] = 1;//总存在构成0的方法

    for(int i = 1; i <= len; ++i){
        for(int j = 0; j <= amount; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - coins[i - 1] >= 0){
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    return dp[len][amount];
    
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int ans = change(amount, coins);

    cout << ans;

    return 0;
}