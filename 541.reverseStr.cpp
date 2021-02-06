#include<iostream>
#include <algorithm>
#include<string>

using namespace std;
//TODO:逻辑清晰
/*
string reverseStr(string s, int k) {
    int len = s.size();//和length()没有区别
    int a = len % (2 * k);//没有成组的个数
    int times = len / (2 * k);//组数

    int i;
    string tmp;

    //先对每一组中的前k个进行反转
    for (i = 0; i < times; ++i) {
        tmp = s.substr(2 * k * i, 2 * k);//子串索引从2*k*i开始，长度为2k
        reverse(tmp.begin(), tmp.begin() + k);//只反转前面一半
        s.replace(2 * k * i, 2 * k, tmp);//将字符串s中，从索引2*k*i开始，长度为2*k的部分，用tmp替换
    }

    //如果剩下的个数小于k，全部反转
    if(a < k) {
        tmp = s.substr(2 * k * i, a);//子串索引从2*k*i开始，长度为a
        reverse(tmp.begin(), tmp.end());//全部反转
        s.replace(2 * k * i, a, tmp);//将字符串s中，从索引2*k*i开始，长度为a的部分，用tmp替换
    }
    else {
        tmp = s.substr(2 * k * i, k);//子串索引从2*k*i开始，长度为k
        reverse(tmp.begin(), tmp.end());
        s.replace(2 * k * i, k, tmp);//将字符串s中，从索引2*k*i开始，长度为k的部分，用tmp替换

    }
 

    return s;

}
*/

//高效
string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }

int main() {
    string s = "abcdefg";
    int k = 2;
    string result = reverseStr(s, k);
    for (char c : result) {
        cout << c << endl;
    }
    
}