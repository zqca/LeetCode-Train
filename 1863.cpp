#include <iostream>
#include <vector>

using namespace std;

int ans1 = 0;

void dfs(int curans, int pos, vector<int>& nums){
    if(pos == nums.size()){
        ans1 += curans;
        return;
    }
    //当前位置的元素不选取
    dfs(curans, pos + 1, nums);
    //当前位置的元素选取，计算新的结果
    dfs(curans ^ nums[pos], pos + 1, nums);
}

int subsetXORSum(vector<int>& nums) {
    //使用回溯法
    int n = nums.size();
    dfs(0, 0, nums);

    return ans1;
}

int subsetXORSum_1(vector<int>& nums) {
    //使用二进制表示
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < (1 << n); i++){
        //i是集合的代号
        int tmpsum = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                tmpsum ^= nums[j];
            }
        }
        sum += tmpsum;
    }
    return sum;
}

int main()
{
   vector<int> nums = {1,3};
   int ans = subsetXORSum_1(nums);
   cout << ans << endl;
   return 0;
}
