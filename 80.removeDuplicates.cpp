#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    unordered_map<int,int> counts;
    for(int i = 0; i < nums.size(); i++){
        auto it = counts.find(nums[i]);
        if(it != counts.end() && it->second >= 2) {
            //删除当前数组中的元素
            nums.erase(nums.begin() + i);
            //有序数组，删除一个元素后i要减小，和i++对冲
            --i;
            continue;
        }
        counts[nums[i]]++;
    }

    return nums.size();
}

int main() {
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int ans = removeDuplicates(nums);
    cout << ans;
    return 0;
}