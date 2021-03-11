#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findRange(string s, char ch) {
    vector<int> ans(3, -1);//【符号位置，数字开始位置，数字结束位置】

    int pos = s.find(ch);
    if(pos == s.npos) return ans;

    int start, end;//含有ch表达式的开始 结束位置
    for(start = pos - 1; start >= 0; start--) {
            //停在第一个数字上面
            if('9' < s[start] || s[start] < '0') {
                start++;
                break;
            }
        }
    for(end = pos + 1; end < s.length(); end++) {
        //停在最后一个数字后面
        if('9' < s[end] || s[end] < '0') {
            break;
        }
    }

    ans[0] = pos;
    ans[1] = start;
    ans[2] = end;

    return ans;
}

vector<int> findOp(string s, char ch1, char ch2, int & flag) {
    //查找包含ch1或者ch2的算式，返回i表示找到了包含chi的算式
    vector<int> res1 = findRange(s, ch1);
    vector<int> res2 = findRange(s, ch2);
    
    if(res1[0] == -1 && res2[0] == -1) {
        flag = 0;
        return res2;
    }
    else if(res1[0] == -1 && res2[0] != -1) {
        flag = 2;
        return res2;
    }
    else if(res1[0] != -1 && res2[0] == -1) {
        flag = 1;
        return res1;
    }
    else if(res1[0] != -1 && res2[0] != -1) {
        if(res1[0] < res2[0]) {
            flag = 1;
            return res1;
        }
        else{
            flag = 2;
            return res2;
        }
        
    }

    return vector<int>(3,0);
}

void op_first(string &s) {
    long num1,num2, num;
    int flag = 1;//默认先找到*
    //计算乘除法，并将结果写入原字符串
    vector<int> tmp = findOp(s,'*','/',flag);
    while(flag != 0) {
        //存在*
        num1 = stoi(s.substr(tmp[1], tmp[0] - tmp[1]));
        num2 = stoi(s.substr(tmp[0] + 1, tmp[2] - tmp[0] + 1));
        if(flag == 1) {
            num = num1*num2;
        }
        else {
            num = num1/num2;
        }
        

        s.replace(tmp[1], tmp[2] - tmp[1], to_string(num));

        tmp = findOp(s,'*','/',flag);  
    }

}

int op_second(string s) {
    //计算加减法
    //先在最后添加+
    s += "+";
    int flag = 1;
    long num = 0;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '+' || s[i] == '-') {
            ans += flag * num;
            if(s[i] == '-') {
                flag = -1;
            }
            else {
                flag = 1;
            }
            num = 0;
        }
        else {
            num = num*10 + s[i] - '0';
        }

    }

    return ans;
}

int calculate(string s) {
    //step1:去除空格
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            s.erase(i, 1);
            i = i - 1;
        }
    }

    if(s[0] == '-') {
        s = '0' + s;
    }
    else {
        s = "0+" + s;
    }

    op_first(s);
    int ans = op_second(s);

    return ans;
}

int main() {
    string s = "14/3*2";//整数除法仅保留整数部分
    cout << calculate(s) << endl;

    return 0;
}