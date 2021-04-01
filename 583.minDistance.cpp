#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    //求最长公共子序列
    int m = word1.size();
    int n = word2.size();
    vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));

    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; ++j) {
            if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return m + n- 2 * dp[m][n];


}

int main() {
    string word1 = "sea";
    string word2 = "";
    int ans = minDistance(word1, word2);
    cout << ans << endl;

    return 0;
}