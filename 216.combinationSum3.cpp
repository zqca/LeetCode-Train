#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > result;

void backtracking(int k, int startVal, int wantSum) {
    if (path.size() == k && wantSum == 0) {
        result.push_back(path);
        return;
    }

    for (int i = startVal; i <= 9; i++) {

        path.push_back(i);
        backtracking(k, i + 1, wantSum - i);
        path.pop_back();
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    path.clear();
    result.clear();
    backtracking(k,1,n);
    
    return result;

}


int main() {
    int n = 9;
    int k = 3;

    combinationSum3(k,n);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}