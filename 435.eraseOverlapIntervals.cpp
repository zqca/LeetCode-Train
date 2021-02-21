#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    return false;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() < 2) return 0;
    int ans = 0;
    sort(intervals.begin(), intervals.end(), cmp);//按照开始位置排序
    int pos = intervals[0][1];
    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i][0] < pos) {
            //当前区间和上一个重叠，一定要删除一个
            ans++;
            if(intervals[i][1] < pos) {
                //现在这个区间在上一个区间之中，应该去除上一个区间
                pos = intervals[i][1];
            }
        }
        else {
            pos = intervals[i][1];
        }

    }

    return ans;

}


int main() {
    vector<vector<int> > intervals = {{1,2},{2,3},{3,4},{1,3}};
    int ans = eraseOverlapIntervals(intervals);

    cout << ans;
    return 0;
}