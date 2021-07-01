#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        //预处理
        unordered_map<int, vector<int> > memo;//能够到达当前点的所有来源
        for(int i = 0; i < relation.size(); ++i){
            memo[relation[i][1]].emplace_back(relation[i][0]);
        }
        vector<vector<int> > dp(k + 1, vector<int>(n, 0));//第i轮消息从A传递到j的方法数
        //初始化
        for(int i = 0; i < relation.size(); ++i){
            if(relation[i][0] == 0){
                dp[1][relation[i][1]] = 1;//第一轮
            }
        }

        for(int i = 2; i <= k; ++i){
            for(int j = 0; j < n; ++j){
                auto tmp = memo[j];//所有（x,j）的x
                for(int x = 0; x < tmp.size(); ++x){
                    dp[i][j] += dp[i - 1][tmp[x]];
                }
            }
        }
        return dp[k][n - 1];
    }
};

int main()
{
   vector<vector<int>> relation = {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};
   int k = 3;
   int n = 5; 

   Solution solution;


   int ans = solution.numWays(n, relation, k);
   cout << ans << endl;
   return 0;
}
