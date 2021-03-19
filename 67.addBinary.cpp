#include <iostream>
#include <string>
#include <stack>

using namespace std;

string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();

    char val_a,val_b;
    int sum;

    stack<char> stack_a, stack_b, stack_c;

    for(int i = 0; i < len_a; i++) {
        stack_a.push(a[i]);
    }
    for(int i = 0; i < len_b; i++) {
        stack_b.push(b[i]);
    }

    int val_add = 0;//进位初始化
    while(stack_a.empty() == false || stack_b.empty() == false) {
        //只要有一个非空
        if(stack_a.empty() == false) {
            val_a = stack_a.top();
            stack_a.pop();
        }
        else {
            val_a = '0';
        }

        if(stack_b.empty() == false) {
            val_b = stack_b.top();
            stack_b.pop();
        }
        else {
            val_b = '0';
        }
    //设置下一次的进位，保存本次计算结果
        sum = val_a - '0' + val_b - '0' + val_add;
        if(sum >= 2) val_add = 1;
        else val_add = 0;

        if(sum == 1 || sum == 3 ) {
            stack_c.push('1');
        }
        else {
            stack_c.push('0');
        }   
    }

    if(val_add) {
        //若最后还剩下进位1
        stack_c.push('1');
    }
    //取出最终结果

    string ans = "";
    while(!stack_c.empty()) {
        ans = ans + stack_c.top();//注意stack_c中，栈顶是高位
        stack_c.pop();
    }

    return ans;

}

int main() {
    string a = "11";
    string b = "1";
    string ans = addBinary(a, b);
    cout << ans << endl;

    return 0;
}
