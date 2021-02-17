#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool validPosition(vector<vector<char>>& board, int i, int j, char val){
    //在（I，j）放置val，返回是否合法
    int n = 9;//size of board
    
    //行检查，检查本行
    for(int k = 0; k < n; ++k) {
        if(board[i][k] == val) return false;
    }
    //列检查
    for(int k = 0; k < n; ++k) {
        if(board[k][j] == val) return false;
    }

    int row, col;
    //小方块检查
    //先确定所在的方块
    row = (int)(i / 3);
    col = (int)(j / 3);
    for(int k1 = 3 * row; k1 < 3 * row + 3; k1++) {
        for(int k2 = 3 * col; k2 < 3 * col + 3; k2++) {
 
            if(board[k1][k2] == val) {
                return false;
            }
        }
    }
    return true; 
}

bool backtracking(vector<vector<char>>& board) {
    
    int n = 9;
    for(int row = 0; row < n; ++row) {
        for(int col = 0; col < n; ++col) {
            //寻找到填入的位置
            if(board[row][col] != '.') continue;

            for(char ch = '1'; ch <= '9'; ch++) {
                if(validPosition(board,row,col,ch)) {
                    board[row][col] = ch;
                    if(backtracking(board)) 
                        return true;// 如果找到合适一组立刻返回
                    board[row][col] = '.';//当前位置放这个数字行不行，不行换一个数字
                }
            }
            return false;//当前格子没有数字可以填充,说明上一层填的数字不合适，需要回溯
        }
    }

    return true;//遍历完所有格子，发现找不到需要填充的位置。没有返回false，说明找到了合适棋盘位置了
}

void solveSudoku(vector<vector<char>>& board) {
    backtracking(board);
        
}
int main() {
    
    vector<vector<char> > board =
       {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};


    
    solveSudoku(board);

    for(auto i : board) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}

