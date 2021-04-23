#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int> > dp(n, vector<int>());
    int maxpos, maxnum, tmpnum;
    for(int i = 0; i < n; i++){
        dp[i].push_back(nums[i]);//加入自身
        maxpos = -1;//能整除的，集合长度最长的index
        maxnum = -1;//能整除的，集合长度最大值
        for(int j = 0; j < i; ++j){
            //找到能整除的，集合长度最长的
            tmpnum = dp[j].size();
            //tmpnum = dp[j].size(); maxnum < tmpnum
            //maxnum < dp[j].size()
            if(nums[i] % nums[j] == 0 && maxnum < tmpnum){
                maxpos = j;
                maxnum = tmpnum;
            }
        }

        if(maxpos == -1){
            //前面没有能被整除的数
            continue;
        }
        else{
            dp[i].insert(dp[i].begin(),dp[maxpos].begin(), dp[maxpos].end());
        }
    }

    //找出集合数目最多的
    maxnum = 1;
    maxpos = 0;
    for(int i = 0; i < n; i++){
        tmpnum = dp[i].size();
        if(tmpnum > maxnum){
            maxpos = i;
            maxnum = tmpnum;
        }
    }

    return dp[maxpos];
}

int main()
{
   vector<int> nums = {1,3,6,8,12};

   vector<int> ans = largestDivisibleSubset(nums);

   return 0;
}
