#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    if(intervals.size() < 2) return intervals;

    sort(intervals.begin(), intervals.end(), cmp);

    int start = intervals[0][0], end = intervals[0][1];
    vector<int> tmp = {-1, -1};//用任意值初始化

    for(int i = 1; i < intervals.size(); i++) { 
        if(intervals[i][0] > end) {
            //不能合并,将前一个区间加入答案
            tmp[0] = start;
            tmp[1] = end;
            ans.push_back(tmp);
            start = intervals[i][0];
            end = intervals[i][1];
        }
        else {
            //能合并，考虑当前区间为上一个区间的子集，考虑拼接两个区间
            end = max(end,intervals[i][1]);//这里先不放入ans
        }
    }
    
    //将最后一个区间加入
    tmp[0] = start;
    tmp[1] = end;
    ans.push_back(tmp);

    return ans;
}

int main() {
    vector<vector<int> > intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > ans = merge(intervals);

    for(auto item : ans) {
        cout << item[0] << " " << item[1] << endl;
    }

    return 0;
}