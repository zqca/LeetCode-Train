#include <iostream>
#include <vector>

using namespace std;

//TODO:1.自己的想法，AC
vector<vector<int>> generateMatrix_1(int n) {
//尝试向 右下左上 走，走不了表示结束

    int i = 0, j = 0;
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    vector<vector<int> > ans(n, vector<int>(n, 0));

    int direction = 0;
    int count = 1;

    while(count <= n*n) {
        //计划向右走
        if(direction%4 == 0 && j < n) {
            ans[i][j] = count;
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
        if(direction%4 == 1 && i < n) {
            ans[i][j] = count;
            visited[i][j] = true;
            count++;
            i++;
            if(i == n || visited[i][j]) {//向下走不了，该向左
                direction ++;
                i--;
                j--;
            }
            continue;
        }
     
        //计划向左走
        if(direction%4 == 2 && j >= 0) {
            ans[i][j] = count;
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
            ans[i][j] = count;
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
    return ans;        

}


//TODO:2.简洁方法
vector<vector<int>> generateMatrix(int n) {
    
    int top = 0, right = n - 1;
    int bottom = n - 1, left = 0;
    //以上是访问边界
    vector<vector<int> > res(n, vector<int>(n, 0));
    int m = 1;
    while(left <= right && top <= bottom && m <= n * n){
            for(int i = left; i <= right; i++) {
                res[top][i] = m++;
            }
            for(int i = top + 1; i <= bottom; i++) {
                res[i][right] = m++;
            }
            for(int i = right - 1; i >= left; i--) {
                res[bottom][i] = m++;
            }
            for(int i = bottom-1; i > top; i--) {
                res[i][left] = m++;
            }
            left++;right--;
            top++;bottom--;
    }

    return res;

}


int main() {
    int n = 4;
    vector<vector<int> > ans = generateMatrix(n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }

    return 0;

}
