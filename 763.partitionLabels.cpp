#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findLast(string s, int pos) {
    //输入待查找字符的下标，返回该字符最后出现的索引
    int ans = pos;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == s[pos]) {
            ans = i;
            break;
        }
    }
    return ans;
}

vector<int> partitionLabels(string S) {
    vector<int> ans;
    if(S.length() == 0) return ans;
    if(S.length() == 1) {
        ans.push_back(1);
        return ans;
    } 

    int start = 0;
    int end = 0; 
    int i, tmp;//tmp存放每个字符最后出现的索引
    vector<bool> visited(26,0);//该字符是否查询过
    for(i = 0; i < S.length(); ++i) {
        if(visited[S[i] - 'a'] == false) {
            tmp = findLast(S, i);
            if(tmp > end) end = tmp;
            visited[S[i] - 'a'] = true;
        }
        
        if(i == end) {
            ans.push_back(end - start + 1);
            start = end + 1;

        }
    }
    return ans;

}

int main() {
    string S = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(S);

    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}