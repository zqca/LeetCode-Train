#include <iostream>
#include <vector>

using namespace std;


int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    vector<int> num0(len, 0);//m
    vector<int> num1(len, 0);//n
    
    for(int i = 0; i < len; ++i) {//i是每一个字符串
        for(int k = 0; k < strs[i].length(); ++k) {
            if(strs[i][k] == '0') num0[i]++;
            else num1[i]++;
        }
    }

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    //dp[i][j]存放 0最多为i个，1最多j个的子集的大小
    for(int k = 0; k < len; k++) {
        //考虑当前元素，更新数组
        for(int i = m; i >=  num0[k]; i--) {
            for(int j = n; j >= num1[k]; j--) {
                dp[i][j] = max(dp[i][j], dp[i - num0[k]][j - num1[k]] + 1);
            }
        }
    }

    return dp[m][n];

}

int main() {
    vector<string> strs = {"10","0001","111001","1","0"};
    int m = 5;
    int n = 3;
    int ans = findMaxForm(strs, m, n);

    cout << ans;

    return 0;
}