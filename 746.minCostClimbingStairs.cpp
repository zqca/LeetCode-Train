#include <iostream>
#include <vector>

using namespace std;
//TODO:关键在于理解dp
int minCostClimbingStairs(vector<int>& cost) {

    //1.理解dp数组的含义，包括下标的含义
    //2.理解转移公式
    //3.正确初始化dp
    //4.确定遍历顺序
    //5.举例推导dp数组
    int len = cost.size();
    if(len == 1) return cost[0];
    if(len == 2) return min(cost[0],cost[1]);
    vector<int> dp(len + 1);//记录到达i需要的最小体力
    dp[0] = 0; dp[1] = 0;
    for(int i = 2; i <= len; i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    return dp[len];

}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost);

    return 0;
}