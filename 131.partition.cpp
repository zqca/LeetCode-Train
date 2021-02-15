#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string curStr;
vector<string> tmpSolution;
vector<vector<string> > result;

bool isValid(string str) {
    if (str.length() == 0) 
        return false;

    string tmp = str;
    reverse(str.begin(),str.end());
    return tmp == str;

}

void backtracking(string s, int headStart, vector<string>& tmpSolution) {

    if (headStart == s.size()) {
        //最后一个已经检查过了
        if(tmpSolution.size() != 0) {
            //空的方案不应该加入结果
            result.push_back(tmpSolution);
        } 
        return;
        
    }

    for (int i = 1; headStart + i <= s.size(); i++) {
        string head = s.substr(headStart, i);//从headStart开始，取i个字符
    
        if(isValid(head)) {
            tmpSolution.push_back(head);
            backtracking(s, headStart + i, tmpSolution);
            tmpSolution.pop_back();
        }
        else {
            continue;
        }
    }

}



vector<vector<string>> partition(string s) {
    if(s.length() == 0) return result;

    backtracking(s,0,tmpSolution);
    return result;
}

int main() {
    string s = "aa";
    vector<vector<string> > result = partition(s);

    for(auto item : result) {
        for(int i = 0; i < item.size(); i++) {
            cout << item[i] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}