#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    vector<vector<bool> > dp(s.length() + 1,vector<bool>(t.length() + 1,false));
    int m = s.size();
    int n = t.size();
    if(n == 0 && m != 0) return false;
    if(m == 0 && n == 0) return true;
    
    for(int j = 0; j <= n; ++j) {
        dp[0][j] = true;//初始化
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(dp[i][j - 1]) {
                dp[i][j] = true;
                continue;
            }

            if(dp[i - 1][j - 1] && s[i - 1] == t[j - 1]) {
                //TODO:切记，索引有改变！！！不是s[i]
                dp[i][j] = true;
            }
        }
    }

    return dp[m][n];

}

int main() {
    string s = "b";
    string t = "c";

    cout << isSubsequence(s,t);

    return 0;
}