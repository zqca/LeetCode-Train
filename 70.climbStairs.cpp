#include <iostream>
#include <vector>

using namespace std;
//TODO:关键在于理解dp
int climbStairs(int n) {
    if(n < 3) return n;
    
    vector<int> dp(n + 1);
    //1.理解dp数组的含义，包括下标的含义@下标i是当前高度,存放的是结果有几种方法
    //2.理解转移公式
    //3.正确初始化dp
    //4.确定遍历顺序
    //5.举例推导dp数组
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];//当前位置可以由前一级跳一步，前二级跳二步到达。因此是他们的方法和
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << climbStairs(n);

    return 0;
}