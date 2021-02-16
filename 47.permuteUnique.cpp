#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > result;

bool hasUsed(vector<int> level, int num) {
    if(level.size() == 0) return 0;
    for(int i = 0; i < level.size(); ++i) {
        if(level[i] == num) return 1;
    }

    return 0;
}

void backtracking(vector<int> nums, vector<bool>& used) {
    vector<int> level;

    if(path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(used[i]) {
            continue;
        }
        else {
            if(hasUsed(level, nums[i])) {
                continue;//这一层已经出现过当前元素
            }

            path.push_back(nums[i]);
            used[i] = true;
            level.push_back(nums[i]);

            backtracking(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums,used);

    return result;
}

int main() {
    vector<int> nums = {1,1,2};
    result = permuteUnique(nums);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}