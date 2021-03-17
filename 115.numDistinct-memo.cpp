#include <iostream>
#include <vector>
#include <string>

using namespace std;

long dfs(vector<vector<long> >& memo, int i, int j, string s, string t) {
    //memo边界
    if(j == 0 && i != 0) return memo[i][j] = 0;//第一列为0
    if(i == 0) return memo[i][j] = 1;//第一行为1

    if(memo[i][j] != -1) return memo[i][j];

    if(s[j - 1] == t[i - 1]) {//这里的i,j对应着memo中的索引，会比s,t的索引大1
        memo[i][j] = dfs(memo, i, j - 1, s, t) + dfs(memo, i - 1, j - 1, s, t);
    }
    else {
        memo[i][j] = dfs(memo, i, j - 1, s, t);
    }

    return memo[i][j];
}

int numDistinct(string s, string t) {

    if(s.length() == 0 || t.length() == 0) return 0;
    //在s中找t

    int m = s.length();
    int n = t.length();
    vector<vector<long> > memo = vector<vector<long> >(n + 1, vector<long>(m + 1, -1));//相加会溢出

    int ans = dfs(memo, n, m, s, t);
    return ans;
}

int main() {
    string s = "babgbag";
    string t = "bag";
    int ans = numDistinct(s, t);

    cout << ans << endl;
    return 0;
}