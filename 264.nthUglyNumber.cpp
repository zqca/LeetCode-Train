#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    int index2 = 1, index3 = 1, index5 = 1;
    vector<int> dp(1 + n);
    dp[1] = 1;//第一个丑数
    int minVal;
    for(int i = 2; i < n + 1; ++i){
        minVal = min(dp[index2]*2, min(dp[index3]*3, dp[index5]*5));
        dp[i] = minVal;
        if(minVal == dp[index2]*2) ++index2;
        if(minVal == dp[index3]*3) ++index3;
        if(minVal == dp[index5]*5) ++index5;
    }


    return dp[n];
}

int main() {
    int n;
    int ans;
    while(cin >> n){
        ans = nthUglyNumber(n);
        cout << ans << endl;
    }
    return 0;
}