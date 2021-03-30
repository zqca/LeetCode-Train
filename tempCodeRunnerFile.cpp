
bool searchMatrix(vector<vector<int>>& matrix, int target) {
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