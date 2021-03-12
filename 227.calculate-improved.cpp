#include <iostream>
#include <string>
#include <stack>
#include <cmath>
//通用，不止针对这一题，对于所有二元运算（含小括号）适用

using namespace std;

//1.初始化

char table[8][8] = {   //算符优先级表,定义'#'优先级最低
//         +    -    *    /    ^    (    )    #    // 当前运算符

/* + */   '>', '>', '<', '<', '<', '<', '>', '>',
/* - */   '>', '>', '<', '<', '<', '<', '>', '>',
/* * */   '>', '>', '>', '>', '<', '<', '>', '>',
/* / */   '>', '>', '>', '>', '<', '<', '>', '>',
/* ^ */   '>', '>', '>', '>', '>', '<', '>', '>',
/* ( */   '<', '<', '<', '<', '<', '<', '=', ' ',
/* ) */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* # */   '<', '<', '<', '<', '<', '<', ' ', '='
//栈顶运算符
};

int getIndex(char a) {
	switch (a) {
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '^':
			return 4;
		case '(':
			return 5;
		case ')':
			return 6;
		case '#':
			return 7;
	}
	return -1;
}

bool isDigit(char ch) {
    if(ch >= '0' && ch <= '9') return true;
    return false;
}

long Compute(char ch, int a, int b) {
    //给定操作符ch,返回计算结果
    switch(ch) {
        case '+' :
            return a + b;
        case '-' :
            return a - b;
        case '*' :
            return a * b;
        case '/' :
            if(b == 0) return 0;
            return a / b;
        case '^' :
            return pow(a + 0.0,b);  
    }

    return 0;
        
}

int calculate(string s) {
    stack<long> nums;//数字栈
    stack<char> ops;//操作符栈

    s = s + "#";
    nums.push(0);//针对 -1这种情况
    ops.push('#');

    char ch;//当前字符
    int num;//即将入栈的数字
    int cur_index;//当前符号的索引
    int top_index;//当前符号栈顶元素的索引
    int num1, num2;//前后两个运算数

    //2.开始遍历
    bool flag = true;//当前字符串中，下一个数字是不是 首位。“123”,1是首位
    for(int i = 0; i < s.length(); i++) {
        ch = s[i];
        if(ch == ' ') continue;//跳过空格

        if(isDigit(ch)) {
            //数字
            if(flag) {
                nums.push(ch - '0');
                flag = false;
            }
            else {
                num = nums.top() * 10 + ch - '0';
                nums.pop();
                nums.push(num);
                
            }  
        }
        else {
            //符号
            cur_index = getIndex(ch);
            top_index = getIndex(ops.top());
            if(table[top_index][cur_index] == '<') {
                //现在的操作符比栈顶元素的优先级更高
                ops.push(ch);
            }
            else if (table[top_index][cur_index] == '>') {
                //栈顶元素的优先级更高,弹出两个数以及操作符开始计算
                while(table[top_index][cur_index] == '>') {
                    //栈顶元素优先级更高，开始计算.这里的操作符不会是括号，看优先级表table
                    num2 = nums.top();nums.pop();
                    num1 = nums.top();nums.pop();
                    num = Compute(ops.top(), num1, num2);
                    //放入刚才的计算结果
                    nums.push(num);
                    //下一个操作符
                    ops.pop();
                    top_index = getIndex(ops.top());
                }

                if(table[top_index][cur_index] == '=') {
                    //说明遇到了右括号与之前的左括号相等，出栈即可
                    ops.pop();
                }
                else {
                    //此时，栈顶元素的优先级会比当前元素的优先级低，放入当前元素
                    ops.push(ch);
                }    
            }
            else if(table[top_index][cur_index] == '=') {
                //如果当前元素和栈顶元素优先级相同，例如输入的表达式为"(1)"
                ops.pop();
            }
            

            flag = true;//下一个数字是首位
        }
    }

    return nums.top();

}

int main() {
    string s = "2 *7-4/3+(2^3/2)";//整数除法仅保留整数部分
    cout << calculate(s) << endl;

    return 0;
}