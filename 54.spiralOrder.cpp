#include <iostream>
#include <vector>

using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //尝试向 右下左上 走，走不了表示结束
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0, j = 0;
    vector<vector<bool> > visited(m, vector<bool>(n, false));


    vector<int> result;
  
    int direction = 0;
    int count = 0;

    while(count != m*n) {
        //计划向右走
        if(direction%4 == 0 && j < n) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            count++;
            //下一次
            j++;
            if(j == n || visited[i][j]) {//向右走不了，该向下
                direction ++;
                j--;
                i++;
            } 
            continue;
        }

        //计划向下走
        if(direction%4 == 1 && i < m) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            count++;
            i++;
            if(i == m || visited[i][j]) {//向下走不了，该向左
                direction ++;
                i--;
                j--;
            }
            continue;
        }
     
        //计划向左走
        if(direction%4 == 2 && j >= 0) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            count++;
            j--;
            if(j == -1 || visited[i][j]) {//向左走不了，该向上
                direction ++;
                j++;
                i--;
            }   
            continue;
        }

        //计划向上走
        if(direction%4 == 3 && i >= 0) {
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            count++;
            i--;
            if(i == -1 || visited[i][j]) {//向上走不了，该向右
                direction ++;
                i++;
                j++;
            }          
            continue;
        }            
    }        
    return result;
}

int main() {
    vector<vector<int> > matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> ans = spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;

}
