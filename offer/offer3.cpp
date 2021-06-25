#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
   int findRepeatNumber(vector<int>& nums) {
      unordered_map<int,int> mp;
      for(auto x: nums){
         if(mp.count(x)){
            return x;
         }
         mp[x] = 0;
      }
      return -1;
   }
};

//优化
class Solution {
public:
   int findRepeatNumber(vector<int>& nums) {
      for(int i = 0; i < nums.size(); ++i){
         if(nums[i] == i){
            continue;
         }
         if(nums[nums[i]] == nums[i]){
            return nums[i];
         }
         swap(nums[i], nums[nums[i]]);
      }
      return -1;
   }
};

int main()
{
   Solution solution;
   vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
   int ans = solution.findRepeatNumber(nums);
   cout << ans << endl;
   return 0;
}
