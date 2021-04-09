#include <iostream>
#include <vector>

using namespace std;


int findMin(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    int n = nums.size() - 1;
    int left, right, mid;
    left = 0;
    right = n;//闭区间

    while(left < right){
        //首先，需要去重！！,left,right都需要指向最后一个重复的值
        while(left + 1 <= n && nums[left] == nums[left + 1]){
            left++;
        }
        while(right - 1 >= 0 && nums[right] == nums[right - 1]){
            right--;
        }

        mid = left + (right - left) / 2;
        //首先，mid会在左右边界之内，不会越界，
        //由于地板除，mid会偏左，导致[left]>[mid]<[right]的时候，全局最小值偏左，收缩右边界
        
        //讨论收缩左边界还是收缩右边界

        //收缩右边界，有两种情形，3-4-5、5-3-4，都是mid<right
        if(nums[mid] < nums[right]){
            right = mid;//mid可能是最小值
        }
        else if(nums[mid] > nums[right]){
            left = mid + 1;//mid绝对不会是最小值，所以＋1
        }
    }
    //循环退出,找到了全局最小值，并且left/right都指向它

    return nums[left];
    
}

int main() {
    vector<int> nums = {2,2,2,0,1};
    int ans = findMin(nums);
    cout << ans << endl;

    return 0;

}