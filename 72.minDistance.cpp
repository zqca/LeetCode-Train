#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j]表示从Word1[i-1]变化到word2[j - 1]的次数，增加了一行一列空字符串
    for(int i = 1; i < n + 1; ++i){
        dp[0][i] = i;
    }
    for(int i = 1; i < m + 1; ++i){
        dp[i][0] = i;
    }

    for(int i = 1; i < m + 1; ++i){
        for(int j = 1; j < n + 1; j++){
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2);
    return 0;
}
