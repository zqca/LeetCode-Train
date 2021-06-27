#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<int, int> mp;//从出发的格子开始，到当前格子需要走的步数
    queue<int> que;
    vector<vector<int>> BOARD;//棋盘数组
    int SIZE;
public:
    pair<int, int> index2pos(int index){
        //输入棋盘尺寸，棋格编号，返回它在棋盘中的坐标
        int k, x, y, r;
        k = (index - 1) / SIZE;//向下取整
        r = (index - 1) % SIZE;//向下取整
        x = SIZE - k - 1;
        y = r;
        if(k % 2){
            //奇数k
            y = SIZE - r - 1;
        }
        return {x, y};
    }

    int bfs(vector<vector<int>>& board){
        int startIndex = 1, endIndex = SIZE * SIZE;
        que.push(startIndex);
        mp[startIndex] = 0;

        while(!que.empty()){
            int len = que.size();
            for(int i = 0; i < len; ++i){
                int curIndex = que.front();
                que.pop();
                //处理下一步可能到的位置
                for(int i = 1; i <= 6; ++i){
                    int nextIndex = curIndex + i;//下一个位置的编号
                    if(nextIndex > endIndex){
                        break;//超出索引
                    } 

                    pair<int,int> tmpPos = index2pos(nextIndex);//下一个位置的坐标
                    int tmpIndex = BOARD[tmpPos.first][tmpPos.second];//临时变量

                    if(tmpIndex != -1){
                        nextIndex = tmpIndex;//可以跳一次
                    }
                    if(mp.count(nextIndex)){
                        continue;//当前hash表已经有到达tmpIndex的路径
                    }

                    if(nextIndex == endIndex){
                        return 1 + mp[curIndex];
                    }

                    mp[nextIndex] = 1 + mp[curIndex];
                    que.push(nextIndex);
                }
            }
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        BOARD = board;
        SIZE = board.size();
        int ans = bfs(BOARD);
        return ans;
    }
};

int main()
{
   Solution solution;

   vector<vector<int> > board = {{-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,35,-1,-1,13,-1},
                                 {-1,-1,-1,-1,-1,-1},
                                 {-1,15,-1,-1,-1,-1}};

//    vector<vector<int> > board = {{-1,-1},{-1,3}};
   int ans = solution.snakesAndLadders(board);
   cout << ans << endl;
   return 0;
}
