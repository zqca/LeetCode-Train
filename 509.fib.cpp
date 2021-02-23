#include <iostream>
#include <vector>

using namespace std;
//TODO:关键在于理解dp
int fib(int n) {
    if(n < 2) return n;
    vector<int> dp(n + 1);
    //1.理解dp数组的含义，包括下标的含义@下标是i,存放的是结果fib(i)
    //2.理解转移公式@dp[i]=dp[i-1]+dp[i-2]
    //3.正确初始化dp
    //4.确定遍历顺序@从前到后
    //5.举例推导dp数组@0,1,1,2,3,5,8,13
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << fib(n);

    return 0;
}