#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string removeDuplicates(string S) {
    stack <char> myStack;
    int len = S.size(), i;

    for (i = 0; i < len; ++i) {
        if (myStack.empty() || myStack.top() != S[i]) {//巧妙使用逻辑短路
            myStack.push(S[i]);
        }
        else {
            myStack.pop();
        }
    }

    string result;
    while(!myStack.empty()) {
        result += myStack.top();
        myStack.pop();
    }
    reverse(result.begin(),result.end());
    return result;

}


int main() {
    string s = "abbaca";
    string result = removeDuplicates(s);
    cout << result;

    return 0;
}
