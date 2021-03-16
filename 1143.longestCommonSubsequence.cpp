#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    //dp[i][j]以text1[i]、text2[j]结尾的子串的最长公共子序列
    if(text1.length() == 0 || text2.length() == 0) return 0;
    vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), 0));
    int i, j;
    //初始化第一行第一列
    for(i = 0; i < text2.length(); ++i) {
        if(text2[i] == text1[0]) break;
    }
    for(j = i; j < text2.length(); ++j) dp[0][j] = 1;

    for(i = 0; i < text1.length(); ++i) {
        if(text1[i] == text2[0]) break;
    }
    for(j = i; j < text1.length(); ++j) dp[j][0] = 1;

    for(i = 1; i < text1.length(); ++i) {
        for(j = 1; j < text2.length(); ++j) {
            if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    return dp[text1.length() - 1][text2.length() - 1];
}

int main() {
    string text2 = "abcde", text1 = "fce";
    int ans = longestCommonSubsequence(text1, text2);
    cout << ans << endl;

    return 0;
}