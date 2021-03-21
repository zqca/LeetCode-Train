#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.size() == 0) return;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> tmp(n, 0);

    vector<bool> clearRow(m, false);//某一行需不需要清零
    vector<bool> clearColumn(n, false);//某一列需不需要清零

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                clearColumn[j] = true;
                clearRow[i] = true;
            }
        }
        if(clearRow[i]) {
            matrix[i] = tmp;
        }//本行清空
    }

    for(int j = 0; j < n; j++) {
        if(clearColumn[j] == false) continue;//本列不需要清空

        for(int i = 0; i < m; ++i) {
            matrix[i][j] = 0;
        }
    }
     
}

int main() {
    vector<vector<int> > matrix = {
                            {0,1,2,0},
                            {3,4,5,2},
                            {1,3,1,5}
                        };
    setZeroes(matrix);

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}