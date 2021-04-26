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
    
    while(left < right) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;

        if(nums[left] <= nums[mid]){
            //左边有序
            if(nums[left] <= target && target <= nums[mid]){
                //target在左边
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            //右边有序
            if(nums[mid] <= target && target <= nums[right]){
                //target在右边
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
    }

    //最后退出循环，判断当前是不是target
    if(nums[left] == target) return left;
    
    return -1;

}
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 3;

    int ans = search(nums, target);
    cout << ans << endl;

    return 0;
}

