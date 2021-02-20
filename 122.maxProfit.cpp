#include <iostream>
#include <vector>

using namespace std;
//TODO:体会贪心，对于【1,5,10】可以贪心为：5-1 + 10 -5 = 10-1，先求出每天的利润，累加每天的正利润
int maxProfit(vector<int>& prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        result += max(prices[i] - prices[i - 1], 0);
    }
    return result;
}
/*
int maxProfit(vector<int>& prices) {
    int ans = 0;
    prices.insert(prices.begin(), INT32_MAX);
    prices.push_back(INT32_MIN);

    int buyPrice, soldPrice;

    for(int i = 1; i < prices.size() - 1; i++) {//只访问原有数组中的元素
        if(prices[i] < prices[i - 1] && prices[i] <= prices[i + 1]) {
            //低谷，买入
            buyPrice = prices[i];
            continue;
        }
        if(prices[i] >= prices[i - 1] && prices[i] > prices[i + 1]) {
            //高价，卖出
            soldPrice = prices[i];
            ans += soldPrice - buyPrice;
        }
    }
    return ans;


}
*/
int main() {
    vector<int> nums = {1,2}; 

    int ans = maxProfit(nums);
    cout << ans << endl;

    return 0;
}


