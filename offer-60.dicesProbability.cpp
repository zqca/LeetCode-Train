#include <iostream>
#include <vector>

using namespace std;



vector<double> dicesProbability(int n) {
    //结果只能是n~6n

    //求解n个骰子的和为target的方案数
    vector<vector<int> >dp(n + 1, vector<int> (6*n + 1, 0));//dp[i][j]表示用I个骰子结果为j的方法数
    dp[0][0] = 1;//重要的初始化


    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= 6*n; ++j) {
            for(int cur = 1; cur <= 6; cur++) {
                //当前一个骰子的结果
                if(j - cur >= 0) {
                    dp[i][j] += dp[i - 1][j - cur];
                }
                else {
                    //优化，当前骰子的结果不加了
                    break;
                }
            }

        }
    }


    //开始查表计算
    vector<double> ans(5*n + 1, 0.0);//先存放方案数，最后求概率
    int index = 0, sum = 0, tmp;
    for(int target = n; target <= 6*n; ++target) {   
        tmp = dp[n][target];
        ans[index++] = tmp;
        sum += tmp;
    }

    for(int i = 0; i < 5*n + 1; ++i) {
        ans[i] /= sum;
    }

    return ans;

}

int main() {
    int n = 2;
    vector<double> ans = dicesProbability(n);
    for(auto item: ans) {
        cout << item << " ";
    }

    return 0;
}