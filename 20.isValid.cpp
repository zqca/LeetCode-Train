#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool isValid(string s) {
    stack <char> myStack;
    //'('，')'，'{'，'}'，'['，']' 的字符串s
    int len = s.size(), i;
    char tmp;
    bool flag = 1;//1表示有效
    for (i = 0; i < len && flag; i++) {
        tmp = s[i];

        switch(tmp) {
            case '(':
                myStack.push(tmp);
                break; 
    
            case '{':
                myStack.push(tmp);
                break; 

            case '[':
                myStack.push(tmp);
                break; 
            //出栈，先测试栈是不是空的
            case ')':
                if(!myStack.empty() && myStack.top() == '(') {
                    myStack.pop();
                }
                else {
                    flag = 0;
                }
                break; 
            
            case '}':
                if(!myStack.empty() && myStack.top() == '{') {
                    myStack.pop();
                }
                else {
                    flag = 0;
                }
                break; 
            
            case ']':
               if(!myStack.empty() && myStack.top() == '[') {
                    myStack.pop();
                }
                else {
                    flag = 0;
                }
                break; 
        }
    }

    if (!myStack.empty()) {
        //非空，还剩下没有匹配的
        return false;
    }
    return flag;


}

int main() {
    string s = "()[]{}";
    cout << isValid(s) << endl;

    system("pause");
    return 0;
}