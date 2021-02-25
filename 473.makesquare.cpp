#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool backtracking(vector<int> nums, int startIndex, int target, vector<int>& side){
    if(startIndex >= nums.size()) {
        return side[0] == target && side[1] == target && side[2] == target;
    }
    for(int i = 0; i < 4; ++i) {
        if(side[i] + nums[startIndex] > target) {
            continue;//放在下一个边
        }
        side[i] += nums[startIndex];
        if(backtracking(nums, startIndex + 1, target, side)) {
            return true;
        }
        side[i] -= nums[startIndex];
    } 

    return false;//四条边都结束了还没有返回，说明不符合要求

}

bool cmp(int a, int b) {
    return a > b;
}
bool makesquare(vector<int>& nums) {

    sort(nums.begin(), nums.end(),cmp);//从大到小排序
    //答案只要回答能不能.
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    if (sum % 4 || sum == 0) return false;//总长度不是4的倍数，不能

    vector<int> side(4,0);//存放当前边长

    return backtracking(nums, 0, sum/4, side);

}

int main() {
    vector<int> nums = {2,2,2,2,2,6};
    cout << makesquare(nums);

    return 0;
}

