#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculate(string s) {
    int ans = 0;
    //step1:去除空格
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            s.erase(i, 1);
            i = i - 1;
        }
    }
    //step2: 为每一个正数加上+号，结尾加上+
    if(s[0] != '-') s = '+' + s;//如果以括号，正数开头，为他们加上符号

    for(int i = 1; i < s.length(); i++) {
        if(s[i - 1] == '(' && '0' <= s[i] && s[i] <= '9') {
            s.insert(i, 1, '+');
        }
    }

    s += '+';//统一下面的计算逻辑
    stack<int> isPostive;
    isPostive.push(1);
    //初始化为正
    string num = "0";
    int abs = 0;//无符号数字
    
    for(int i = 0; i < s.length(); i++) {
        if( i > 0 && '0' <= s[i - 1 ] && s[i - 1] <= '9' && (s[i] == '+' || s[i] == '-' || s[i] == ')')) {
            //数字结束
            abs = stoi(num);
            ans += isPostive.top() * abs;
            isPostive.pop();
            num = "0";

        }

        if(s[i] == '+') {
            isPostive.push(isPostive.top());
            continue;
        }

        if(s[i] == '-') {
            isPostive.push(-isPostive.top()); 
            continue;
        }

        if(s[i] == ')') {
            isPostive.pop();
            continue;
        }

        if('0' <= s[i] && s[i] <= '9') {
            //遇到数字
            num += s[i];
        }
    }      

    return ans;
}

int main() {
    string s = "5   ";//
    cout << calculate(s) << endl;

    return 0;
}