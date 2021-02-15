#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> path;
vector<vector<int> > result;

void backtracking(vector<int> candidates, int target, int curSum, int startIndex, vector<bool>& hasUsed) {
    if(curSum > target) return;
    
    if (curSum == target) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {
        //剪枝，候选元素是不减的，如果加上当前的元素已经大于target后面都不要访问了
        if(curSum + candidates[i] > target) break;

        if(i > 0 && candidates[i] == candidates[i - 1] && hasUsed[i - 1] == false) {
            //跳过每一层中重复的，相当于剪枝，毕竟即使向下找到符合要求的，他也是重复的答案；实例：【1,1,1,1】@2
            continue;
        }

        path.push_back(candidates[i]);
        hasUsed[i] = true;
        curSum += candidates[i];
        backtracking(candidates, target, curSum, i + 1, hasUsed);
        hasUsed[i] = false;

        curSum -= candidates[i];
        path.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if(candidates.size() == 0) return result;
    path.clear();
    result.clear();
    vector<bool> hasUsed(candidates.size(), false);
    //判断同一层有没有使用过。
    //一开始false，往下的时候为true，回溯回来以后变成false；
    //如果在这一层遇到相同的元素,并且前一个的状态为false，跳过

    sort(candidates.begin(), candidates.end());

    backtracking(candidates, target, 0, 0, hasUsed);
 
    return result;

}


int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    combinationSum2(candidates,target);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}