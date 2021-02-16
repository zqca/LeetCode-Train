#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> curVec;
vector<vector<int> > result;

void backtracking(vector<int> nums, int startIndex, vector<bool>& hasUsed) {
    if (startIndex == nums.size()) {
        return;
    }

    for (int i = startIndex; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i - 1] && hasUsed[i - 1] == false) {
            continue;
        }
       
        curVec.push_back(nums[i]);
        hasUsed[i] = true;
        result.push_back(curVec);//先加入每一层的本身

        backtracking(nums, i + 1, hasUsed);

        curVec.pop_back();
        hasUsed[i] = false;
    }

}



vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<bool> hasUsed(nums.size(), false);
    result.push_back(curVec);//先加入空集
    if(nums.size() == 0) return result;

    sort(nums.begin(), nums.end());
    backtracking(nums, 0, hasUsed);

    return result;

}

int main() {
    vector<int> nums = {1,2};
    vector<vector<int> > result = subsetsWithDup(nums);
    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}
