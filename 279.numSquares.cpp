#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n) {
    //不是组合，完全背包，
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;

    for(int i = 0; i < 101; ++i) {//最多使用到的平方数是100^2
        if(i * i > n) break;

        for(int j = 0; j <= n; ++j) {
            if(j - i * i >= 0 && dp[j - i * i] != INT32_MAX) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
    }

    return dp[n];
}


int main() {
    int n = 12;
    int ans = numSquares(n);//3,12=4+4+4
    cout << ans << endl;

    return 0;

}