#include <iostream>
#include <vector>

using namespace std;


int lastStoneWeightII(vector<int>& stones) {
    //目标是将石头分成大小相似的两堆
    int sum = 0;
    for(int i : stones) sum += i;
    int target = sum / 2;//只取一半,背包的最大容量
    vector<int> dp(target + 1, 0);
    //背包的容量是sum,物品的质量和价值都是石头的质量
    for(int i = 0; i < stones.size(); i++) {
        for(int j = target; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    int weight = dp[target];//给定能装sum的背包，最大装了这么多块石头

    return abs(weight - sum + weight);

}

int main() {
    vector<int> stones = {1};
    cout << lastStoneWeightII(stones);

    return 0;
}