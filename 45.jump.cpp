#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    if(nums.size() <= 2) return nums.size() - 1; 

    int cur = 0, next = 0, i, step = 0;//当前覆盖，下一次覆盖到的下标
    for (i = 0; i < nums.size(); i++) {
        next = max(i + nums[i], next);
        if(i == cur) {
            //走到了当前最远
            if(cur != nums.size() - 1) {
                step++;
                cur = next;
                if(next >= nums.size() - 1) break;
            }
            else {
                break;
            }
        }
    }

    return step;

}

int main() {
    vector<int> nums = {2,3,1,1,4};
    int ans = jump(nums);
    cout << ans << endl;

    return 0;
}