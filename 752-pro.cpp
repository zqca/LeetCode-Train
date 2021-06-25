#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<string,int> dead;//所有不允许的节点
    unordered_map<string, int> depth1, depth2;
    //depth1:起点0000出发，到当前数字 "1234" 所需要的转换次数xx
    //depth2:终点target出发，到当前数字 "1234" 所需要的转换次数xx
public:
    int bfs(string start, string target){
        queue<string> que1, que2;
        que1.push(start); depth1[start] = 0;
        que2.push(target); depth2[target] = 0;
        //只有两个方向的队列都不空才循环。如果有一个为空，说明某个方向已经搜索结束但是还没有发现答案
        while(!que1.empty() && !que2.empty()){
            int tmp = -1;//表示当前这一轮层次搜索有没有找到最终的答案，初始化为没有找到
            if(que1.size() <= que2.size()){
                //为了均衡，选一个短的que拓展
                tmp = update(que1, depth1, depth2);
            }
            else{
                tmp = update(que2, depth2, depth1);
            }
            if(tmp != -1){
                return tmp;
            }
        }
        return -1;//全部搜索结束，不存在答案
    }

    int update(queue<string> & que, unordered_map<string, int>& curdepth, unordered_map<string, int>& other){
        //遍历当前的树，更新ta对应的Hash表
        string curStr = que.front();
        int curStep = curdepth[curStr];
        que.pop();
        //处理四个轮盘
        for(int j = 0; j < 4; ++j){
            //当前轮盘的数字+1或-1
            for(int k = -1; k < 2; k += 2){
                char tmp = (curStr[j] - '0' + 10 + k) % 10 + '0';
                string newStr = curStr;
                newStr[j] = tmp;//派生出来的下一层结果
                if(dead.count(newStr) || curdepth.count(newStr)){
                    //如果构造出来的结果会导致锁死；或者这个结果在当前方向曾经访问过（有一条更短的路径）
                    continue;
                }

                if(!other.count(newStr)){
                    //变换后的数字在另外一个方向上没有遇到过,把这个数字加入当前方向的队列
                    que.push(newStr);
                    curdepth[newStr] = 1 + curStep;
                }
                else{
                    //找到了最终的答案，可以把两个方向的路径进行连接
                    return other[newStr] + curStep + 1;//从起点到curStr的次数 + 从curStr到newStr的次数 + 从终点到newStr的次数
                }
            }    
        }
        return -1;//本层搜索没有找到答案    
    }

    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        //双向BFS
        for(auto x : deadends){
            dead[x] = 0;//加入所有不允许的节点
        }
        if(dead.count("0000") || dead.count(target)){
            return -1;
        }
        int ans = bfs("0000", target);
        return ans;
    }
};

int main()
{
   vector<string> deadends = {"0201","0101","0102","1212","2002"};
   string target = "0202";
   Solution solution;
   int ans = solution.openLock(deadends, target);
   cout << ans << endl;
   return 0;
}
