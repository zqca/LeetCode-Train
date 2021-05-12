#include <iostream>
#include <vector>

using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int len = arr.size();
    int tmp = 0;
    vector<int> pre(len);//长度和arr相同

    for(int i = 0; i < len; i++){
        tmp = tmp ^ arr[i];
        pre[i] = tmp;
    }

    int n = queries.size();
    vector<int> ans(n, 0);
    int sum1, sum2, sum3;

    for(int i = 0; i < n; i++){
        sum1 = pre[queries[i][0]];
        sum2 = pre[queries[i][1]];
        sum3 = ((sum1 ^ sum2) ^ arr[queries[i][0]]);
        ans[i] = sum3;
    }
    return ans;

}

int main()
{
   vector<int> arr = {1,3,4,8};
   vector<vector<int> > queries = {{0,1},{1,2},{0,3},{3,3}};
   vector<int> ans = xorQueries(arr, queries);
   //cout << ans << endl;
   return 0;
}
