#include <iostream>
#include <vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //分成两堆，找不超过sum一半的情况下能放入的最重的石头
        int len = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int mid = sum / 2;
        vector<vector<int>> dp(len + 1, vector<int>(mid + 1));//考虑前I个石头，放入背包j的方法数
        for(int i = 1; i <= len; i ++) {
            for(int j = 0; j <= mid; j ++) {
                dp[i][j] = dp[i - 1][j];
                if(j >= stones[i - 1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        } 
        return sum - 2 * dp[len][mid];
    }
};


int main() {
    vector<int> stones = {1};
    Solution solution;
    cout << solution.lastStoneWeightII(stones);

    return 0;
}
