#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return false;
    
    int right = n - 1;
    int left = 0;
    int mid;
    //左bi右闭
    while(left < right){
        
        //去除重复的数字
        while(left + 1 < n && nums[left] == nums[left + 1]){
            ++left;
        }
        while(right - 1 >= 0 && nums[right] == nums[right - 1]){
            --right;
        }

        mid = left + ((right - left) >> 1);

        if(nums[mid] == target) return true;

        if(nums[left] <= nums[mid]){
            //左边有序
            if(nums[left] <= target && target <= nums[mid]){
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
            if(nums[mid] <= target && target <= nums[right]){
                //在这个范围内
                left = mid + 1;
            }
            else{
                //不在这个范围内
                right = mid;
            }

        }
    }

    return nums[left] == target ? true : false;

}
int main() {
    vector<int> nums = {1};
    int target = 1;
    bool ans = search(nums, target);
    cout << ans;
    return 0;
}