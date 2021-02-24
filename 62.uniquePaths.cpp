#include <iostream>
#include <vector>

using namespace std;
//TODO:关键在于理解dp
int uniquePaths(int m, int n) {

    //1.理解dp数组的含义，包括下标的含义
    //2.理解转移公式
    //3.正确初始化dp
    //4.确定遍历顺序
    //5.举例推导dp数组
    vector<vector<int> > dp(m, vector<int>(n, 1));//全部初始化为1；其实主要的是初始化第一行第一列为1
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    

    return dp[m - 1][n - 1];

}

int main() {
    int m = 1, n = 1;

    cout << uniquePaths(m, n);

    return 0;
}