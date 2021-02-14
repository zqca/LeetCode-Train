#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int> > result;

void backtracking(int n, int k, int startVal) {
    if (path.size() == k) {
        result.push_back(path);
        return;
    }

    for (int i = startVal; i <= n; i++) {
        if(startVal + k - path.size() - 1 > n) {
            break;//剩下的元素数量不够
        }
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }

}

vector<vector<int>> combine(int n, int k) {

    path.clear();
    result.clear();
    backtracking(n, k, 1);
    return result;

}


int main() {
    int n = 5;
    int k = 3;

    combine(n,k);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}