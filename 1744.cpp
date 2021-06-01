#include <iostream>
#include <vector>

using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    int qn = queries.size();
    vector<bool> ans(qn, true);
    int n = candiesCount.size();
    vector<long long> sum(n);
    sum[0] = candiesCount[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i - 1] + candiesCount[i];
    }

    for(int j = 0; j < qn; j++){
        auto query = queries[j];
        long long favoriteType = query[0];
        long long favoriteDay = query[1];//当天，序号从0开始
        long long dailyCap = query[2];
        //区间1：当天结束，我们累计吃的糖果的数量落在区间
        long long x1 = favoriteDay + 1;
        long long y1 = (favoriteDay + 1) * dailyCap;

        //区间2：第i种类型的糖果对应的编号范围为：
        long long x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
        long long y2 = sum[favoriteType];
            
        ans[j] = (!(x1 > y2 || y1 < x2)); 
    }

    return ans;

}

int main()
{
    vector<int> candiesCount = {7,4,5,3,8};
    vector<vector<int> > queries = {{0,2,2},{4,2,4},{2,13,1000000000}};
    vector<bool> ans = canEat(candiesCount, queries);
    //cout << ans << endl;
    return 0;
}
