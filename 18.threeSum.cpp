#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());//这是算法头文件的方法
    //双指针i,left,right
    int i, left, right;
    int len = nums.size();
    

    for(i = 0; i < len - 2; ++i) {

        if (nums[i] > 0) return ans;//排除特例:最小的数已经大于0

        if (i > 0 && nums[i] == nums[i - 1]) {//会漏-1，-1，-1,0,2这种情况
            continue;//也可以将这个if放在最后写
        }

        left = i + 1;
        right = len - 1;
        while(left < right) {
            //固定i的情况下找不同的left+right
            //比如找到一组之后再去重

            int tmp = nums[i] + nums[left] + nums[right];
            if (tmp == 0) {
                ans.push_back(vector<int> {nums[i], nums[left], nums[right]});
                //已经找到了一组，接下来剔除用过的数字
                while(left < right && nums[left] == nums[left + 1]) {
                    ++left;//找到最后一个重复的数字b
                }
                //停在了最后一个用过的left

                while(left < right && nums[right] == nums[right - 1]) {
                    --right;//找到最后一个重复的数字c
                }
                //停在了最后一个用过的right

                ++left;//为下一次做准备
                --right;
            }
            else if(tmp < 0) {
                ++left;
            }
            else {
                --right;
            }

        }
      
    }


    return ans;

}

int main() {
   vector<int> nums = {-1,0,1,2,-1,-4};
   vector<vector<int>> ans = threeSum(nums);
   for(auto item : ans) {
       for(int i = 0; i < item.size(); i++) {
           cout << item[i] <<" ";
       }
       cout << endl;
   }
}