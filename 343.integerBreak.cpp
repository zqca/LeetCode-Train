#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1);//使得下标和对应的数字匹配
    //dp[i] = max(dp[i],max(j*(i-j), j*dp[i-j])),j=1...i-1
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }

    }
    return dp[n];

}

int main() {
    int n = 10;

    cout << integerBreak(n);

    return 0;
}