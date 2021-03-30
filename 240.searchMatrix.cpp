#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    //从右上角开始，小于target向下走，大于target向左走，超出边界false
    int m = matrix.size();
    int n = matrix[0].size();
    int j = n - 1, i = 0;
    while (i < m && j >= 0) {
        if(matrix[i][j] == target) return true;

        if(matrix[i][j] > target) {
            --j;
        }
        else{
            ++i;
        }
    }
    return false;
}

int main() {
    int target = 5;
    vector<vector<int> > matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    bool ans = searchMatrix(matrix, target);
    cout << ans << endl;

    return 0;
}