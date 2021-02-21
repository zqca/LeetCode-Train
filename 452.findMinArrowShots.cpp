#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0] < b[0]) return true;
    return false;
}
/*TODO:方便理解
int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() < 2) return points.size();
    int ans = 1;//至少需要一次
    sort(points.begin(), points.end(), cmp);//按照开始位置排序
    for(int i = 1; i < points.size(); ++i) {
        if(points[i][0] > points[i - 1][1]) {
            //气球的开始比上一个气球的结尾要大，前面需要一键
            ans++;
        }
        else {
            //修改当前气球的结尾，确保一键可以射到前面堆在一起的气球
            points[i][1] = min(points[i][1], points[i - 1][1]);
        }
    }
    return ans;

}

*/

int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() < 2) return points.size();
    int ans = 1;//至少需要一次
    sort(points.begin(), points.end(), cmp);//按照开始位置排序
    int pos = points[points.size() - 1][0];//射出位置为最左边
    for(int i = points.size() - 2; i >= 0 ; --i) {
        if(points[i][1] < pos) {
            //现在这个气球不能和之前的一起射，也就是说在pos处射不到当前气球
            ans++;
            pos = points[i][0];
        }
    }
    return ans;

}

int main() {
    vector<vector<int> > points = {{10,16},{2,8},{1,6},{7,12}};
    int ans = findMinArrowShots(points);

    cout << ans;
    return 0;
}