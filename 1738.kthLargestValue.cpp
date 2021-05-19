#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> vec(m * n);
    int count = 0;
    vector<vector<int> > dp(m, vector<int>(n));
    dp[0][0] = matrix[0][0];
    vec[count++] = dp[0][0];

    for(int j = 1; j < n; j++) {
        dp[0][j] = (dp[0][j - 1] ^ matrix[0][j]);
        vec[count++] = dp[0][j];
    }

    for(int i = 1; i < m; i++) {
        dp[i][0] = (dp[i - 1][0] ^ matrix[i][0]);
        vec[count++] = dp[i][0];
    }

    for(int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++){
            dp[i][j] = (dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j]);
            vec[count++] = dp[i][j];
        }  
    }
    sort(vec.begin(), vec.end());
    return vec[m * n - k];
}

int main()
{
   vector<vector<int> > matrix = {{5,2},{1,6}};
   int k = 2;
   int ans = kthLargestValue(matrix, k);
   cout << ans << endl;
   return 0;
}
