#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//TODO:暴力超时
int numSubmatrixSumTarget_1(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > presum(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            presum[i][j] = presum[i][j - 1] - presum[i - 1][j - 1] + presum[i - 1][j] + matrix[i - 1][j - 1];
        }
    }
    int cur, cnt = 0;

    for(int row = 1; row <= m; row++){//最大的行，矩阵下边界
        for(int col = 1; col <= n; col++){//右边界
            for(int i = 1; i <= row; i++){//上边界
                for(int j = 1; j <= col; j++){//左边界
                    cur = presum[row][col] - presum[row][j - 1] + presum[i - 1][j - 1] - presum[i - 1][col];
                    if(cur == target){
                        ++cnt;
                    }

                }
            }
        }
    }
    return cnt;


}

//TODO:前缀和＋Hash表
int preHash(vector<int> arr, int target){
    unordered_map<int,int> count;//前缀和为key,出现次数为value

    count[0] = 1;//关键的一步，现在的前缀和刚好是target,按照下面写的会去查找前缀和0出现的次数，应该初始化为1；
    int sum = 0;
    int ans = 0;
    for(int x : arr){
        sum += x;
        if(count.find(sum - target) != count.end()){
            //当前的前缀和为sum，如果之前出现过前缀和sum-target，那么二者中间的和为target
            ans += count[sum - target];
        }
        count[sum]++;
    }
    return ans;

}

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target){
    int result = 0;
    int m = matrix.size(), n = matrix[0].size();
    for(int i = 0; i < m; ++i){
        vector<int> sum(n);
        for(int j = i; j < m; j++){
            for(int k = 0; k < n; ++k){
                //更新当前每一列的和
                sum[k] += matrix[j][k];
            }
            result += preHash(sum, target);
        }
    }
    return result;
}

int main()
{
vector<vector<int> > matrix = {{0,1,0},{1,1,1},{0,1,0}};
   int target = 0;
   int ans = numSubmatrixSumTarget(matrix, target);
   cout << ans << endl;
   return 0;
}
