#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string curStr;
vector<string> result;

bool isValid(string raw, int start, int end) {
    //返回 输入字符串是不是0-254;左闭右开
    string str(raw.begin() + start, raw.begin() + end);

    int len = str.length();
    if(len == 0 || len > 3) return false;

    int num = stoi(str);

    if(len == 1) return true;
    if(len == 2 && num >= 10 && num <= 99) return true;
    if(len == 3 && num >= 100 && num <= 255) return true;

    return false;
}

void backtracking(string s, int headStart, int times) {
    //times指的是已经完成的网段，headStart指的是当前网段开始的数字的索引

    if (times == 4 ) {
        if(headStart == s.length()) {
            //删除ip地址最后一个点
            curStr.pop_back();
            result.push_back(curStr);
        }
            
        return;   
    }

    for (int i = 1; headStart + i <= s.size() && i < 4; i++) {
        //i指的是每个网段数字的长度；
        //从headStart开始，取i个字符作为一个网段

        //剪枝1：剩下的数字的长度len大于3*剩下的网段数目
        if(s.length() - headStart > 3*(4 - times)) return;

        if(isValid(s, headStart, headStart + i)) {
            string part = s.substr(headStart,i);
            int tmpLen = curStr.size();
            curStr = curStr + part + ".";

            backtracking(s, headStart + i, times + 1);
            curStr.resize(tmpLen);
        }
        else break;//有一个网段不符合要求，后续也不需要查找了
      
    }

}


vector<string> restoreIpAddresses(string s) {
    if(s.length() < 4 || s.length() > 12) return result;

    backtracking(s, 0, 0);

    return result;
}

int main() {
    string s = "101023";
    vector<string> result = restoreIpAddresses(s);

    for(auto item : result) {
        cout << item << endl;
    }

    //system("pause");
    return 0;
}