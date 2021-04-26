#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while(low < high){
        mid = low + (high - low) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }

    if(nums[low] == target){
            return low;
    }
    return -1;

}

int main()
{
   vector<int> nums = {-1,0,3,5,9,12};
   int target = 8;
   int ans = search(nums, target);
   cout << ans << endl;

   return 0;
}
