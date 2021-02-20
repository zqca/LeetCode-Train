#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    if(a[0] == b[0] && a[1] < b[1]) return true;
    return false;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<int> tmp = {INT32_MAX, -1};
    vector<vector<int> > ans(people.size(), tmp);
    int rank;

    for(int k = 0; k < people.size(); ++k) {
        //放置第k个属性到ans
        rank = people[k][1] + 1;
        for(int i = 0; i < ans.size(); ++i) {
            //在ans中寻找合适的位置
            if(ans[i][0] >= people[k][0]) {
                rank--;
            }
            if(rank == 0) {
                ans[i] = people[k];
                break;
            }
        }
    }
    return ans;



}

int main() {
    vector<vector<int> > people = {{7,0}};
    vector<vector<int> > ans = reconstructQueue(people);

    for(int i = 0; i < ans.size();i++) {
        for(int j = 0; j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}