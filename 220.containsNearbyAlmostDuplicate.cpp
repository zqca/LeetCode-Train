#include <iostream>
#include <vector>
#include <set>//有序的集合

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> rec;
    for (int i = 0; i < nums.size(); ++i) {
            // 指针定位比 long(nums[i])-t 大的数的位置
            auto pos = rec.lower_bound(long(nums[i]) - t);
            // 如果存在 且 该数字也比 long(nums[i]) + t 小，说明存在我们想要的结果
            if (pos!=rec.end() && *pos <= long(nums[i]) + t) return true;
            rec.insert(nums[i]);
            if (rec.size() > k) rec.erase(nums[i-k]); // 维护滑动窗口的大小为k
    }
    return false;
}

int main() {
    vector<int> nums = {-2147483648,2147483647};
    int k = 1;
    int t = 1;
    cout << containsNearbyAlmostDuplicate(nums, k, t);
    return 0;

}