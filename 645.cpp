#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> count;
        int len = nums.size();
        for(int i = 0; i < len; ++i){
            count[nums[i]]++;
        }

        vector<int> ans(2, 0);
        int flag = 2;
        for(int i = 1; i <= len; ++i){
            if(flag == 0){
                break;
            }
            if(count[i] == 2){
                ans[0] = i;
                --flag;
            }
            if(count[i] == 0){
                ans[1] = i;
                --flag;
            }
        }
        return ans;

    }
};

int main()
{
   Solution solution;
   vector<int> nums = {1,2,2,4};

   int ans = 0;
   cout << ans << endl;
   return 0;
}
