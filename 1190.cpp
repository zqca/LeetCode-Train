#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for(auto& ch : s)
        {
            if(ch == '(')
            {
                stk.push(str);
                str = "";
            }
            else if(ch == ')')
            {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            }
            else
                str += ch;
        }
        return str;
    }
//链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/solution/zhan-dong-tu-yan-shi-by-xiaohu9527-hua8/


int main()
{
   string s = "(ed(et(oc))el)";
   string ans = reverseParentheses(s);
   cout << ans << endl;
   return 0;
}
