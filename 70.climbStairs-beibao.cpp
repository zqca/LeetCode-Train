#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    //现在每次可以爬[1，m]级,这就变成了完全背包
    int m = 2;
    
    vector<int> dp(n + 1);
    //1.理解dp数组的含义，包括下标的含义@下标i是当前高度,存放的是结果有几种方法
    //2.理解转移公式
    //3.正确初始化dp
    //4.确定遍历顺序
    //5.举例推导dp数组
    dp[0] = 1;

    for(int j = 1; j <= n; ++j) {//外层遍历背包
        for(int i = 1; i <= m; i++) {
            if(j - i >= 0) {
                dp[j] += dp[j - i]; 
            }
        }
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << climbStairs(n);

    return 0;
}