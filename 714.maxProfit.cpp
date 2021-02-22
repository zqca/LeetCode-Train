#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int ans = 0;
    int minprice = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        //最小价格买入
        if(prices[i] < minprice) minprice = prices[i];

        if(prices[i] >= minprice && prices[i] <= minprice + fee) {
            //买卖都不合适
            continue;
        }

        if(prices[i] > minprice + fee) {
            //有赚，先卖，如果后面有更高价格再补回来
            ans += prices[i] - minprice - fee;
            minprice = prices[i] - fee;
            //重要！会后面发现更高价格，补回之前卖掉的做准备。
            //发现更高价格的时候，在原来ans的基础上＋两个卖出价的差
            //如果后面出现了低价，相当于在这里就卖出了
        }

    }

    return ans;

}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int ans = maxProfit(prices, fee);
    cout << ans << endl;
    return 0;

}