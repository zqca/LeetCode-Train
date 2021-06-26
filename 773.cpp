#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<string, int> mp1, mp2;
//board对应的字符串,需要从起点出发 走多少步 才能到达当前状态
public:
    string toStr(vector<vector<int> > cur){
        //将数组形式的Board转换为字符串
        string ans = "";
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                ans += to_string(cur[i][j]);
            }
        }
        return ans;
    }
    
    string genBoard(string curBoard, int direction){
        //输入：当前board，更新方向；输出：修改后的board
        int i, j, pos;
        string ans = "#";
        //默认当前方向不能产生新的Board，返回#。否则返回新board对应的字符串。

        pos = curBoard.find('0');

        if(direction == 1 && pos >= 3 && pos <= 5){
            swap(curBoard[pos], curBoard[pos - 3]);
            ans = curBoard;
        }
        else if(direction == 3 && pos >= 0 && pos <= 2){
            swap(curBoard[pos], curBoard[pos + 3]);
            ans = curBoard;
        }
        else if(direction == 2 && (pos == 0 || pos == 1 || pos == 3 || pos == 4)){
            swap(curBoard[pos], curBoard[pos + 1]);
            ans = curBoard;
        }
        else if(direction == 4 && (pos == 1 || pos == 2 || pos == 4 || pos == 5)){
            swap(curBoard[pos], curBoard[pos - 1]);
            ans = curBoard;
        }

        return ans;
    }

    int update(queue<string>& que,unordered_map<string, int>& cur, unordered_map<string, int>& other){
        string curBoard = que.front();
        que.pop();
        //更新Board，尝试4个方向：上1、右2、下3、左4
        for(int direction = 1; direction <= 4; ++direction){
            string newBoard = genBoard(curBoard, direction);
            //如果不能执行这个方向的移动，会newBoard = “#”，
            if(newBoard.size() != 1){
                if(cur.count(newBoard)){
                    //新的board曾经在当前hash表出现过
                    continue;
                }
                if(other.count(newBoard) == 0){
                    //另一个hash表没有出现过
                    que.push(newBoard);
                    cur[newBoard] = 1 + cur[curBoard]; 
                }
                else{
                    //找到了最短路径，拼接 “起点->curBoard，curBoard->newBoard, 终点->newBoard”的长度
                    return 1 + cur[curBoard] + other[newBoard];
                }
            }
        }
        return -1;
    }

    int bfs(vector<vector<int> >& start){
        queue<string> que1, que2;
        string str1, str2;
        str1 = toStr(start); str2 = "123450";
        if(str1 == str2){
            //如果起点和终点一样，不需要移动
            return 0;
        }

        que1.push(str1); mp1[str1] = 0;
        que2.push(str2); mp2[str2] = 0;
        while(!que1.empty() && !que2.empty()) {
            int tmp = -1;
            if(que1.size() <= que2.size()){
                tmp = update(que1, mp1, mp2);
            }
            else{
                tmp = update(que2, mp2, mp1);
            }
            if(tmp != -1){
                return tmp;
            }
        }
        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = bfs(board);
        return ans;
    }
};

int main()
{
   vector<vector<int> > board = {{4,1,2}, {5,0,3}};
   Solution solution;

   int ans = solution.slidingPuzzle(board);
   cout << ans << endl;
   return 0;
}
