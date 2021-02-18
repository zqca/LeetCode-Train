#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int result = INT32_MIN;
    int sum = 0;
    //遇到负数就放弃
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sum > result) result = sum;

        if(sum <= 0) {//说明加了一个负数，得放弃
            sum = 0;
        }
    }
    return result;
}
/*
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    //尝试先找到第一个正数
    //然后开始查找，遇到正数停下，判断现在的sum是不是更小了。如果更小了，从现在的位置重新查找
    int start, maxsum = nums[0], cursum;

    for(start = 0; start < n; ++start)
        if(nums[start] > 0) break;
    //没有正数
    if(start == n ) {
        auto num = max_element(nums.begin(),nums.end());
        return *num;

    }
    maxsum = nums[start];
    cursum = nums[start];


    for(start = start + 1; start < n; ++start) {
        cursum += nums[start];
        if(nums[start] > 0) {
            //遇到下一个正数
            if(maxsum < cursum) {
                maxsum = cursum;
            }
            if(maxsum < nums[start]) {
                maxsum = nums[start];
            }
            if(cursum < nums[start]) {//重置
                cursum = nums[start];
            }    
        }
    }
    return maxsum;
}
*/
int main() {
    vector<int> nums = {-3,1,-2,2}; 

    int ans = maxSubArray(nums);
    cout << ans << endl;

    return 0;
}
    
