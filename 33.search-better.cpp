#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() == 1) {
        return nums[0] == target ? 0 : -1;
    }

    int left = 0;
    int right = nums.size() - 1;//左闭右闭
    int mid;
    
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;

        if(mid - 1 >= left && nums[left] <= nums[mid - 1]){
            //左边存在，并且左有序
            if(nums[left] <= target && target <= nums[mid - 1]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else if(mid + 1 <= right && nums[mid + 1] <= nums[right]){
            //右边存在，并且右边有序
            if(nums[mid + 1] <= target && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            //左右都不存在
            return nums[mid] == target ? mid : -1;
        }
    }

    return -1;

}

int main() {
    vector<int> nums = {3,1};
    int target = 1;

    int ans = search(nums, target);
    cout << ans << endl;

    return 0;
}

