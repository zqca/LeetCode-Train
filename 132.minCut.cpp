#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minCut(string s) {
    //首先确定一个数组g[i][j]判断s[i,j]是否是回文
    int n = s.length();
    vector<vector<bool> > g(n, vector<bool>(n, true));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            // g[i][j]中，i>=j的部分为true
            g[i][j] = g[i + 1][j - 1] && s[i] == s[j];
        }
    }

    vector<int> dp(n, INT32_MAX);//将长度为i的字符串切割为回文的次数

    for(int i = 0; i < n; ++i) {
        if(g[0][i] == true) {
            //已经是回文
            dp[i] = 0;
        }
        else {
            for(int j = i - 1; j >= 0; j--) {
                if(g[j + 1][i] == true) {
                    //如果s[j+1,i] 是回文的，dp[i]=min(dp[i], 1 + dp[j])
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
    }

    return dp[n - 1];

    
}

int main() {
    string s = "cabababcbc";
    cout << minCut(s) << endl;

    return 0;
}
