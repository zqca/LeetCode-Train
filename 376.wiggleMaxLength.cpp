#include <iostream>
#include <vector>


using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    //假设最前面有一个节点，他的值和第一个元素相同

    int n = nums.size();
    if(n < 2) return n;
    
    int ans = 1;//任何一种情况，这是最小值
    
    int preDiff = 0, curDiff = 0;
    for(int i = 1; i < n; ++i) {
        curDiff = nums[i] - nums[i - 1];
        if(preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
            //等号是为了应对只有两个元素的情况，比如【2,5】
            ans++;
            preDiff = curDiff;
        }
    }
    return ans;   
}

int main() {
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8}; 

    int ans = wiggleMaxLength(nums);
    cout << ans << endl;

    return 0;
}