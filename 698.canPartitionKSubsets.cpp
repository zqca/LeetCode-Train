#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool backtracking(int k, vector<int> nums, int startIndex, int target, vector<int>& side){
    if(startIndex >= nums.size()) {
        for(int i = 0; i < k; i++) {
            if(side[i] != target) {
                return false;
            }
        }
        return true;
    }
    for(int i = 0; i < k; ++i) {
        if(side[i] + nums[startIndex] > target) {
            continue;//放在下一个边
        }
        side[i] += nums[startIndex];
        if(backtracking(k, nums, startIndex + 1, target, side)) {
            return true;
        }
        side[i] -= nums[startIndex];
    } 

    return false;//四条边都结束了还没有返回，说明不符合要求

}

bool cmp(int a, int b) {
    return a > b;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end(), cmp);//从大到小排序
    //答案只要回答能不能.
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    if (sum % k || nums.size() < k) return false;//总长度不是k的倍数，不能

    vector<int> side(k,0);//存放当前边长

    return backtracking(k, nums, 0, sum/k, side);
}

int main() {
    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;
    cout << canPartitionKSubsets(nums, k);

    return 0;
}

