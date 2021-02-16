#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > result;


void backtracking(vector<int> nums, vector<bool>& used) {
    if(path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(used[i]) {
            continue;
        }
        else {
            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums,used);

    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    result = permute(nums);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}