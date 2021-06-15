#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        int mid;
        //保证输入长度至少为3
        while(high - low >= 2){
            mid = low + (high - low) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid;
            }
            if(arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid]){
                //上升阶段
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        //剩下俩元素
        return arr[low] > arr[high] ? low : high;
    }
};

int main()
{
   Solution s;
   vector<int> arr = {3,4,5,1};
   int ans = s.peakIndexInMountainArray(arr);
   cout << ans << endl;
   return 0;
}
