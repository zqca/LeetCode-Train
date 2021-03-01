#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);//从头开始，长度为i的子串能不能break
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    dp[0] = true;//初始化，没有实际含义
    string word;
    for(int j = 1; j <= s.size(); ++j) {//遍历背包
        for(int i = 0; i < j; ++i) {
            //前方子串的长度为i，如果dp[i]=true && s[i+1,j]在字典里，dp[j]=true
            word = s.substr(i, j - i);
            if(dp[i] && wordSet.find(word) != wordSet.end()) {
                dp[j] = true;
                break;
            }

        }

    }

    return dp[s.size()];
    

}

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    bool ans = wordBreak(s, wordDict);
    cout << ans << endl;

    return 0;

}