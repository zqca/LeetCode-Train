#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return false;
    int right = n;
    int left = 0;
    int mid;
    //左开右闭
    while(left < right){
        
        //去除重复的数字
        while(left + 1 < n && nums[left] == nums[left + 1]){
            ++left;
        }
        while(right - 2 > 0 && nums[right - 1] == nums[right - 2]){
            --right;
        }

        mid = (left + right) / 2;

        if(nums[mid] == target) return true;

        if(mid - 1 >= 0 && nums[left] <= nums[mid - 1]){
            //左边有序
            if(nums[left] <= target && target <= nums[mid - 1]){
                //在这个范围内
                right = mid;
            }
            else{
                //不在这个范围内
                left = mid + 1;
            }
        }
        else {
            //右边有序
            if(right - 1 >= 0 && mid + 1 < n && nums[mid + 1] <= target && target <= nums[right - 1]){
                //在这个范围内
                left = mid + 1;
            }
            else{
                //不在这个范围内
                right = mid;
            }

        }
    }
    return false;

}

int main() {
    vector<int> nums = {1};
    int target = 1;
    bool ans = search(nums, target);
    cout << ans;
    return 0;
}