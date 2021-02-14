#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
vector<string> result;
string letterMap[10] = {"",//0
                      "",//1
                      "abc",//2
                      "def",//3
                      "ghi",//4
                      "jkl",//5
                      "mno",//6
                      "pqrs",//7
                      "tuv",//8
                      "wxyz",//9                
                    };

void backtracking(string input, int index) {
    //index指的是输入的数字字符串的 当前字符位置，也是树的层次
    if(index == input.size()) {
        result.push_back(s);
        return;
    }

    int digit = input[index] - '0';
    string cur = letterMap[digit];

    for(int i = 0; i < cur.size(); i++) {
        s.push_back(cur[i]);
        backtracking(input,index + 1);
        s.pop_back();
    }

}

vector<string> letterCombinations(string digits) {
    if(digits.empty()) { 
        return result;
    }
    
    backtracking(digits, 0);
    return result;
}

int main() {
    string digits = "";

    letterCombinations(digits);

    for(auto item : result) {       
        cout << item << endl;
    }

    system("pause");
    return 0;
}