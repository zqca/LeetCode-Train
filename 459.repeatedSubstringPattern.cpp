#include <iostream>
#include <string>

using namespace std;

void getNext(int* next, string s) {
     int len = s.size();
     int j = -1, i;
     next[0] = -1;
     for(i = 1; i < len; i++) {
         while(j >=0 && s[i] != s[j + 1]) {
             j = next[j];
         }
         if (s[i] == s[j + 1]) {
             j++;
         }
         next[i] = j;
     }
     return;
}




bool repeatedSubstringPattern(string s) {
    //判断一个字符串能否可以由他的子串重复，使用kmp。网上流行双倍字符串的方法

    //如果一个长度为len的字符串s是符合要求的，假设他的最长相同前后缀的长度maxSame，
    //那么，len %（len-maxSame）=0;而maxSame为next数组的最后一位+1；
    //next数组，从重复子串出现开始变成0，并递增。例如ababab的next数组-1，-1, 0,1,2,3
    int len = s.size();
    int* next = new int[len];
    getNext(next, s);
    int maxlen = next[len - 1] + 1;
    if (next[len - 1] == -1) {
        return false;//不是循环串
    }
    return !(len % (len - maxlen));

}

int main() {
    string s1 = "abac";//True
    string s2 = "abaa";//false

    bool flag = repeatedSubstringPattern(s1);
    cout << flag << endl;
    system("pause");
    return 0;

}