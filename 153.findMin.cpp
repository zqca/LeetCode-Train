#include <iostream>
#include <vector>
//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
using namespace std;

/*
使用闭区间
while里面建议统一写 left < right
建议画图 左中右 四种状态，有个高低的图就行了，只用三个元素3 4 5模拟

    中   
左
      右

*/
int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;                /* 左闭右闭区间，如果用右开区间则不方便判断右值 */ 
        while (left < right) {                      /* 循环不变式，如果left == right，则循环结束 */
            int mid = left + (right - left) / 2;    /* 地板除，mid更靠近left */
            if (nums[mid] > nums[right]) {          /* 中值 > 右值，最小值在右半边，收缩左边界 */ 
                left = mid + 1;                     /* 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid */ 
            } else if (nums[mid] < nums[right]) {   /* 明确中值 < 右值，最小值在左半边，收缩右边界 */ 
                right = mid;                        /* 因为中值 < 右值，中值也可能是最小值，右边界只能取到mid处 */ 
            }
        }
        return nums[left];    /* 循环结束，left == right，最小值输出nums[left]或nums[right]均可 */     
}

int main() {
    vector<int> nums = {11,13,15,17};
    int ans = findMin(nums);
    cout << ans << endl;

    return 0;

}