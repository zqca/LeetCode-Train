#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> visited;
    visited.insert(deadends.begin(), deadends.end());//加入所有不允许的节点
    if(visited.count("0000")){
        return -1;
    }
    int step = 0;
    queue<string> que;
    que.push("0000");
    while(!que.empty()){
        int len = que.size();
        for(int i = 0; i < len; ++i){
            string cur = que.front();
            que.pop();
            //如果当前元素是target,返回当前层数
            if(cur == target)
                return step;
            //处理四个轮盘
            for(int j = 0; j < 4; ++j){
                //当前轮盘的数字+1或-1
                for(int k = -1; k < 2; k += 2){
                    char tmp = (cur[j] - '0' + 10 + k) % 10 + '0';
                    string newStr = cur;
                    newStr[j] = tmp;
                    if(!visited.count(newStr)){
                        //变换后的数字没有遇到过,入队为下一层做准备，入visited
                        visited.insert(newStr);
                        que.push(newStr);
                    }
                }    
            }
        }
        //当前层次处理结束
        ++step;
    }
    return -1;//如果可以开锁，会在上面返回

}

int main()
{
   vector<string> deadends = {"0201","0101","0102","1212","2002"};
   string target = "0202";
   int ans = openLock(deadends, target);
   cout << ans << endl;
   return 0;
}
