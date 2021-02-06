#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int evalRPN(vector<string>& tokens) {
    stack<int> container;
    int len = tokens.size();
    //多少个操作,token中的每一个数字都会入栈1次，每个运算符都会将计算结果入栈1次
    int i, result, num1, num2;
    string tmp;
    for (i = 0; i < len; ++i) {
        tmp = tokens[i];
        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
            num2 = container.top();container.pop();
            num1 = container.top();container.pop();
            if (tmp == "+") {
                container.push(num1 + num2);
            }
            else if (tmp == "-") {
                container.push(num1 - num2);
            }
            else if (tmp == "*") {
                container.push(num1 * num2);
            }
            else if (tmp == "/") {
                container.push((int)(num1 / num2));
            }
        }
        else {
            container.push(stoi(tmp));
        }
    }

    result = container.top();
    return result;


}

int main() {
    vector <string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result = evalRPN(tokens);
    cout << result;

    return 0;
}
