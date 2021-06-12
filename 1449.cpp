#include <iostream>
#include <vector>
#include <string>

using namespace std;

string cmp(string s1, string s2){
    int l1 = s1.size(), l2 = s2.size();
    if(l1 > l2){
        return s1;
    }
    if(l1 < l2){
        return s2;
    }
    return s1 > s2 ? s1 : s2;
}

string largestNumber(vector<int>& cost, int target) {
    vector<vector<string> > dp(10, vector<string>(1 + target));
    // dp[i][j]表示前i个元素, 恰好构成成本为j时, 构成的最大的整数(整数用字符串表示)
    // 无效状态用'#'表示
    for (int j = 0; j <= target; ++j) {
       dp[0][j] = '#';
    }
    
    dp[0][0] = "";
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j <= target; ++j) {
        string a, b;
        // 不选第i个
        a = dp[i - 1][j];
        // 加选一个
        if (j - cost[i - 1] >= 0 && dp[i][j - cost[i - 1]] != "#")
            b = std::to_string(i) + dp[i][j - cost[i - 1]];
            dp[i][j] = cmp(a, b);
        }
    }

    if (dp[9][target] == "#") return "0";
    else return dp[9][target];
}

int main()
{
   vector<int> cost = {4,3,2,5,6,7,2,5,5}; 
   int target = 9;
   string ans = largestNumber(cost, target);
   cout << ans << endl;
   return 0;
}
