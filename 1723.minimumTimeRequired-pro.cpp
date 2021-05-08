#include <iostream>
#include <vector>

using namespace std;

int minimumTimeRequired(vector<int>& jobs, int k) {
    //TODO:状态压缩
    int n = jobs.size();
    int numofsets = (1 << n);

    //step1:一个人计算完成集合i内所有工作需要的时间
    vector<int> total(numofsets, 0);//total[0]代表空集

    int tmp;
    for(int i = 1; i < numofsets; ++i){
        for(int j = 0; j < n; ++j){
            //j指的是某项工作
            tmp = (1 << j);
            if((i & tmp) == 0) continue;
            //如果数字i代表的集合与数字j代表的集合没有重复的部分，跳过
            int left = i - tmp;//集合i中去除集合j（具体来说只去除1个元素）后剩下的部分
            total[i] = total[left] + jobs[j];
            break;//当前集合i计算过了，后续可以跳过，否则剩下的j全部在continue处结束
        }
    }

    vector<vector<int> > dp(k, vector<int>(numofsets, 0));
    //dp[j][i]表示前j个人完成集合i需要的时间

    //step2:初始化dp数组，第1个人完成集合i需要的时间
    for(int i = 0; i < (numofsets); ++i){
        dp[0][i] = total[i];
    }
    
    //TODO:
    for(int j = 1; j < k; ++j){
        for(int i = 0; i < numofsets; ++i){
            int mintime = INT32_MAX;
            //枚举集合i的子集s
            for(int s = i; s; s = ((s - 1) & i)){
                int val = max(dp[j - 1][i - s], total[s]);
                //前j-1个人完成集合i-s需要的时间，第j个人单独完成集合s需要的时间，二者取最大值

                mintime = min(mintime, val);
                //记录集合i的不同子集s，需要的最短时间
            }
            dp[j][i] = mintime;
        }
    }

    return dp[k - 1][numofsets - 1];

}

int main()
{
   vector<int> jobs = {1,2,4,7,8}; 
   int k = 2;

   int ans = minimumTimeRequired(jobs, k);
   cout << ans << endl;
   return 0;
}
