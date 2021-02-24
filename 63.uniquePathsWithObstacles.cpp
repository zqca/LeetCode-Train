#include <iostream>
#include <vector>

using namespace std;
//TODO:关键在于理解dp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //1.理解dp数组的含义，包括下标的含义
    //2.理解转移公式
    //3.正确初始化dp
    //4.确定遍历顺序
    //5.举例推导dp数组
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int> > dp(m, vector<int>(n, 0));
    //全部初始化为1；其实主要的是初始化第一行第一列为1;障碍物初始化0
    for(int i = 0; i < m; i++) {
        //把第一列初始化,如果遇到障碍后面的元素不能访问
        if(obstacleGrid[i][0] != 1) {
            dp[i][0] = 1;
        }
        else {
            break;
        }
    }
    for(int j = 0; j < n; j++) {
        //把第一列初始化,如果遇到障碍后面的元素不能访问
        if(obstacleGrid[0][j] != 1) {
            dp[0][j] = 1;
        }
        else {
            break;
        }
    }

    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            if(obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1];

}

int main() {
    vector<vector<int> > obstacleGrid ={{0,0,0},{0,1,0},{0,0,0}};

    cout << uniquePathsWithObstacles(obstacleGrid);

    return 0;
}