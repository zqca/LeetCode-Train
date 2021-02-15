#include <iostream>
#include <vector>

using namespace std;

vector<int> curVec;
vector<vector<int> > result;

void backtracking(vector<int> nums, int startIndex) {
    if (startIndex == nums.size()) {
        return;
    }

    for (int i = startIndex; i < nums.size(); i++) {
       
        curVec.push_back(nums[i]);
        result.push_back(curVec);//先加入每一层的本身

        backtracking(nums, i + 1);

        curVec.pop_back();
    }

}

vector<vector<int>> subsets(vector<int>& nums) {
    result.push_back(curVec);//先加入空集
    if(nums.size() == 0) return result;

    backtracking(nums, 0);

    return result;

}


int main() {
    vector<int> nums = {2,1,3};
    vector<vector<int> > result = subsets(nums);
    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}
