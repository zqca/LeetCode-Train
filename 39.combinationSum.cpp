#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > result;

void backtracking(vector<int> candidates, int target, int curSum, int startIndex) {
    if(curSum > target) return;
    
    if (curSum == target) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {

        path.push_back(candidates[i]);
        curSum += candidates[i];
        backtracking(candidates, target, curSum, startIndex++);

        curSum -= candidates[i];
        path.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(candidates.size() == 0) return result;
    path.clear();
    result.clear();

    backtracking(candidates, target, 0, 0);
    return result;

}


int main() {
    vector<int> candidates = {2,3,5};
    int target = 8;

    combinationSum(candidates,target);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}