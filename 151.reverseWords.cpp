#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    //1 对s整体反转
    reverse(s.begin(), s.end());

    //2 反转单词，去除空格
    int wordStart, wordEnd;//单词的开始,结尾(空格)

    int index = 0;//新字符串中的索引,也是新字符串最终的长度

    int n = s.length();
    for (int i = 0; i < n; ++i) {
        //遍历原始字符串，当前是空格就继续for循环
        if (s[i] != ' ') {
            //找到了第一个字母
            if (index > 0) {
                s[index++] = ' ';//除了第一次之外，再找到新单词之前需要添加一个空格
            }
            wordStart = i;
            wordEnd = wordStart;
            while (wordEnd < n && s[wordEnd] != ' ') {
                s[index++] = s[wordEnd++];
            }
            //目前已经找到了一个单词（已反转），这个单词的结尾索引是index，已经存储在s头部。
            //需要把这个单词反转回去。注意，这个单词的开始位置
            reverse(s.begin() + index - (wordEnd - wordStart), s.begin() + index);
            i = wordEnd;//下一次查找单词的位置
        }
    }

    //3 去除多余的部分
    s.erase(s.begin() + index, s.end());

    return s;

}

int main() {
    string s = "a b";
    s = reverseWords(s);
    cout << s << endl;
    system("pause");
    return 0;

}