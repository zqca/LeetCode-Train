#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int tmp = 0;
    for (int i = 2; i <= n; i++) {
        
        //在上一个结果的基础上插入i
        //以i为root，插入上一个结果
        //把i插在上一个结果的中间。看最终结果可以分为【j个元素】i【i-1-j个元素】 
        for(int j = 1; j <= i - 2; j++) {
            tmp += dp[j] * dp[i - 1 - j];
        }
        dp[i] = 2 * dp[i - 1] + tmp;
        tmp = 0;
    }
    return dp[n];

}

int main() {
    int n = 5;

    cout << numTrees(n);

    return 0;
}

