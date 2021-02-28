#include <iostream>
#include <vector>

using namespace std;

int change1(int amount, vector<int>& coins) {
    if(amount == 0) return 1;
    if(coins.size() == 0) return 0;

    //dp[i][j]凑出总价i的方法数
    vector<vector<int> > dp(coins.size(), vector<int>(amount + 1, 0));

    dp[0][0] = 1;//使用coin[0]构造出0只有一种方法
    dp[0][coins[0]] = 1;//使用coin[0]构造出coin[0]只有一种方法

    for(int j = coins[0] + 1; j <= amount; j++ ) {
        dp[0][j] = dp[0][j - coins[0]];//
    }
    //初始化结束
    for(int i = 1; i < coins.size(); i++) {
        for(int j = 0; j <= amount; j++) {
            if(j < coins[i]) {
                dp[i][j] = dp[i - 1][j];
                //不能使用当前物品的方法，维持上一次的结果
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                //相比上一次，添加了"使用当前物品得到j-coins[i]之后，再使用COINS[i]"的方法
            }
            
        }
    }

    return dp[coins.size() - 1][amount];

}

int change(int amount, vector<int>& coins) {
    if(amount == 0) return 1;
    if(coins.size() == 0) return 0;
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;//和为0有1中方法
    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1};
    int amount = 0;
    int ans = change(amount, coins);

    cout << ans;

    return 0;
}