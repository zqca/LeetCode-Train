#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

int memo[30][30][31];
//-1表示不和谐，1表示和谐，0表示没有判断
string s1 = "great";
string s2 = "rgeat";

bool isSimilar(string s1, string s2){
    //判断两个是不是相似，某个字符出现的次数是否一样多
    vector<int> count(26,0);
    for(int i = 0; i < 26; i++){
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    for(int i = 0; i < s1.size(); i++){
        if(count[i] != 0) return false;
    }
    return true;
}

bool dfs(int i1, int i2, int length){
    //判断s1从I开始，s2从i2开始，长度都为len的字符串是否和谐
    if(memo[i1][i2][length] != 0) return memo[i1][i2][length] == 1;

    if(s1.substr(i1,length) == s2.substr(i2, length)){
        memo[i1][i2][length] = 1;
        return true;
    }

    if(isSimilar(s1.substr(i1,length), s2.substr(i2, length)) == false){
        return false;
    }
    // 枚举分割位置
    for (int i = 1; i < length; ++i) {
        // 不交换的情况
        if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
        // 交换的情况;画图看具体开始和结束位置
        if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
    }

    memo[i1][i2][length] = -1;
    return false;

}

bool isScramble(string s1, string s2) {
    return dfs(0, 0, s1.size());
}

int main() {
    string s1 = "great";
    string s2 = "rgeat";

    cout << isScramble(s1, s2);

    return 0;
}