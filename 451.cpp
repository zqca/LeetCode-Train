#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {  
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;//统计每一个字符出现的次数
        for(int i = 0; i < s.size(); ++i){
            count[s[i]]++;
        }
        
        vector<vector<char> > record(s.size() + 1, vector<char>());//出现次数，字符
        for(auto item : count){
            record[item.second].emplace_back(item.first);
        }

        string ans = "";
        for(int cnt = s.size(); cnt > 0; cnt--){
            if(record[cnt].size() > 0){
                for(int i = 0; i < record[cnt].size(); ++i){
                    //当前字符record[cnt][i]
                    for(int j = 0; j < cnt; ++j){
                        //次数
                        ans.push_back(record[cnt][i]);
                    }
                }
            }
        }
        
        return ans;
    }
};

class Solution {  
private:
    static bool cmp(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;//return想要的顺序
    }
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;//统计每一个字符出现的次数
        for(int i = 0; i < s.size(); ++i){
            count[s[i]]++;
        }
        vector<pair<char, int> > vec(count.begin(), count.end());//把map的内容放在vec中再排序，map不支持自己排序
        sort(vec.begin(), vec.end(), cmp);

        string ans = "";
        for(auto [ch, times] : vec){
            for(int i = 0; i < times; ++i){
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};

int main()
{
   Solution solution;
   string s = "tree";
   string ans = solution.frequencySort(s);
   cout << ans << endl;
   return 0;
}
