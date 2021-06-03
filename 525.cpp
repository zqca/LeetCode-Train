#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
前缀和+哈希表 屡试不爽 总结一下最近用到这个思想的的题目：

525连续数组

526连续的子数组和

527元素和为目标值的子矩阵数量

528和为k的子数组

529每个元音包含最长的子字符串

530统计「优美子数组」 LCP 19：秋叶收藏集

531矩形区域不超过 K 的最大数值和
*/
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    if(n < 2) return 0;
    unordered_map <int,int> pos;//key=前缀和，value=首次出现的位置
    int ans = 0;
    int sum = 0;
    pos[0] = -1;
    //当前元素为1则对sum+1,是0就-1，如果存在符合题意的子数组，子数组前后的前缀和是相同的
    for (int i = 0; i < n; i++){
        if(nums[i] == 1){
            sum += 1;
        }
        else{
            sum -= 1;
        }

        if(pos.count(sum)){
            int prepos = pos[sum];
            ans = max(ans, i - pos[sum]);
        }
        else{
            pos[sum] = i;
        }
    } 
    return ans;
}

int main()
{
   vector<int> nums = {0,1};
   int ans = findMaxLength(nums);
   cout << ans << endl;
   return 0;
}
