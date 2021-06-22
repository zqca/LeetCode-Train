#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        //回溯法
        int len = s.size();
        visited.resize(len, 0);
        string cur = s;//可以像数组一样操作cur
        dfs(s, visited, cur, 0);
        return ans;
    }

    void dfs(string s, vector<int>& visited, string& cur, int depth){
        int len = s.size();
        if(depth == len){
            if(mp.find(cur) == mp.end()){
                ans.push_back(cur);
                mp[cur] = 1;
            }
            return; 
        }
        for(int i = 0; i < len; ++i){
            if(visited[i]){
                continue;
            }
            cur[depth] = s[i];
            visited[i] = 1;
            dfs(s, visited, cur, depth + 1);
            visited[i] = 0;
        }
    }

private:
    vector<string> ans;
    vector<int> visited;
    unordered_map<string, int> mp;
};

//使用全排列函数next_permutation
class Solution1 {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector <string> res;
        unordered_map<string, int> mp;
        do{
            if(mp.count(s) == 0){
                res.emplace_back(s);
                mp[s] = 1;
            }
            
        }while(next_permutation(s.begin(), s.end()));

        return res;
    }
};


int main()
{
   Solution1 solution;
   string s = "abc";
   vector<string> ans = solution.permutation(s);
   //cout << ans << endl;
   return 0;
}
