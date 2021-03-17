#include <iostream>
#include <vector>
#include <string>

using namespace std;


int numDistinct(string s, string t) {
    if(s.length() == 0 || t.length() == 0) return 0;
    //在s中找t

    int m = s.length();
    int n = t.length();
    vector<vector<long> > dp(n, vector<long>(m, 0));//相加会溢出
    //dp[i][j]表示t[0-i]在s[0-j]中出现次数；
    int count = 0;//用于初始化第一行
    for(int j = 0; j < m; ++j) {
        if(t[0] == s[j]) {
            ++count;
        }
        dp[0][j] = count;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1 ; j < m; ++j) {
            dp[i][j] = dp[i][j - 1];//至少等于左边
            if(s[j] == t[i]) {
                //如果加入的字符满足，t[i]=s[j],还需要加上左上方的值
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];


}

int main() {
    string s = "babgbag";
    string t = "bag";
    int ans = numDistinct(s, t);

    cout << ans << endl;
    return 0;
}