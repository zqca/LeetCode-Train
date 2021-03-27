#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() == 1) {
        return nums[0] == target ? 0 : -1;
    }

    int left = 0;
    int right = nums.size();//左开右闭
    int mid;
    mid = (left + right) / 2;
    while(left < right) {
        if(nums[mid] == target) return mid;
        //左边全部有序
        if(nums[left] <= nums[mid - 1]) {
            //target在左边
            if(nums[left] <= target && target <= nums[mid - 1]) {
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        else {
            //右边全部有序
            //target在右边
            if(nums[mid + 1] <= target && target <= nums[right - 1]) {
                left = mid + 1;
            }
            else{
                right = mid;
            }

        }
        mid = (left + right) / 2;

    }

    return -1;

}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 3;

    int ans = search(nums, target);
    cout << ans << endl;

    return 0;
}

