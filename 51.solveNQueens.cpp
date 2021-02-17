#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > result;
vector<string> table;

void tableIni(vector<string>& table, int n) {
    string s;
    s.assign(n,'.');
    table.assign(n,s);
}

bool validPosition(vector<string>& table, int i, int j){
    //在（I，j）放置，返回是否合法
    int n = table.size();
    //行检查，不需要
  
    //列检查
    for(int k = 0; k < n; ++k) {
        if(k == i) continue;
        if(table[k][j] == 'Q') return false;
    }

    int row, col;
    //对角线检查1
    for(row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
        if(table[row][col] == 'Q') return false;
    }
    //对角线检查2
    for(row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++) {
        if(table[row][col] == 'Q') return false;
    }
    //对角线检查3
    for(row = i + 1, col = j + 1; row < n && col < n; row++, col++) {
        if(table[row][col] == 'Q') return false;
    }
    //对角线检查4
    for(row = i + 1, col = j - 1; row < n && col >= 0; row++, col--) {
        if(table[row][col] == 'Q') return false;
    }

    return true; 
}


void backtracking(vector<string>& table, int row, int n) {
    //显然一行只能放一个

    //row是当前尝试的行
    if(row == n) {//row是索引，开始table以外的行时，收割
        result.push_back(table);
        return;
    }
    for(int pos = 0; pos < n; ++pos) {
        //pos是尝试填充的列
        table[row][pos] = 'Q';
        if(validPosition(table, row, pos) == false) { 
            table[row][pos] = '.';//撤销本层上一次尝试
            continue;
        }
        
        backtracking(table, row + 1, n);
        table[row][pos] = '.';
        
    }

}


vector<vector<string>> solveNQueens(int n) {
    tableIni(table,n);
    backtracking(table, 0, n);

    return result;  
}

int main() {
    int n = 1;
    vector<vector<string> > ans = solveNQueens(n);

    for(auto i : ans) {
        for(auto j : i) {
            cout << j <<endl;
        }
        cout <<"Next solution:"<< endl;
    }
    return 0;
}