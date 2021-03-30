#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low, high, mid;//左闭右开
    //首先确定在哪一行
    low = 0;
    high = m;
    while(high - low > 1) {
        mid = (low + high) / 2;
        if(matrix[mid][0] == target) return true;
        else if(matrix[mid][0] > target) {
            //说明mid行及其之后不存在
            high = mid;
        }
        else {
            //说明至少mid行可能，mid之前没有
            low = mid;
        }
    }

    //此时数字只可能在mid行
    int row = low;
    low = 0;
    high = n;
    while(low < high) {
        mid = (low + high) / 2;
        if(matrix[row][mid] == target) return true;
        else if(matrix[row][mid] > target) {
            //说明mid列及其之后不存在
            high = mid;
        }
        else {
            //说明mid列之后可能，mid之前没有
            low = mid + 1;
        }

    }
    return false;
}

int main() {
    int target = 16;
    vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    bool ans = searchMatrix(matrix, target);
    cout << ans << endl;

    return 0;
}