#include <iostream>
#include <vector>


using namespace std;

vector<int> curVec;
vector<vector<int> > result;

bool hasEle(vector<int> level, int num) {
    if(level.size() == 0) return false;

    for(int i=0; i < level.size(); i++) {
        if(level[i] == num) {
            return true;
        }
    }
    return false;
}

void backtracking(vector<int> nums, int startIndex) {
    
    if(startIndex >= nums.size()) return;
    
    vector<int> level;//存储当前层的已遍历元素

    for (int i = startIndex; i < nums.size(); i++) {
       
        if (i > 0 && !curVec.empty() && nums[i] < curVec.back()) {
            continue;
        }


        if(!hasEle(level, nums[i])) {
            level.push_back(nums[i]);
        }
        else {
            continue;
        }
        curVec.push_back(nums[i]);

        if(curVec.size() > 1) {
            result.push_back(curVec);
        }

        backtracking(nums, i + 1);

        curVec.pop_back();

    }

}

vector<vector<int>> findSubsequences(vector<int>& nums) {

    if(nums.size() == 0) return result;

    backtracking(nums, 0);

    return result;

}


int main() {
    vector<int> nums = {3,2,1,2,3};
    vector<vector<int> > result = findSubsequences(nums);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}
