#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    //dp[i][j]表示以A[i-1]、B[j-1]结尾的子串的长度
    vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1,0));
    int ans = 0;
    for(int i = 1; i <= A.size(); i++) {
        for(int j = 1; j <= B.size(); j++) {
            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            if(dp[i][j] > ans) ans = dp[i][j];
            
        }
    }

    return ans;
}

int main() {
    vector<int> A = {1,0,0,0,1,0,0,1,0,0};
    vector<int> B = {0,1,1,1,0,1,1,1,0,0};
    int ans = findLength(A, B);
    cout << ans << endl;

    return 0;
}