#include <iostream>
#include <string>

using namespace std;



void getNext(string s, int* next) {
    int len = s.size();
    int j = -1, i;//TODO:注意j的初始值

    //初始化next数组，这里的数组在实际长度的基础上减1，避免字符串aa的next数组（0,1）进入死循环
    next[0] = j;

    for (i = 1; i < len; ++i) {//TODO:注意i的初始值
        while (j >= 0 && s[i] != s[j+1]) {
            ////TODO:注意j的范围
            j = next[j];
        }
        if (s[i] == s[j+1]) {
            j++;//i++在for循环中实现
        }
        next[i] = j;
    }
    return;
    
}

int KMP(string pattern, string target) {
    const int len_p = pattern.size();
    const int len_t = target.size();

    if (len_p == 0) return 0;

    int* next = new int[len_p];//将数组开在堆内存中，最后需要delete

    getNext(pattern, next);

    int i, j = -1;//i在target上面遍历，j在next数组上面
    //注意j的初始值也是-1；
    for (i = 0; i < len_t; ++i) {//TODO://TODO:注意i的初始值
        //如果不匹配
        while(j >= 0 && target[i] != pattern[j+1]) {
            j = next[j];
        }
        if (target[i] == pattern[j+1]) {
            j++;
        }

        if (j == len_p - 1) {
            //如果有一个完全匹配
            delete[] next;
            return (i - len_p + 1);
        }

    }
    
    delete[] next;
    return -1;

}



int main() {
    string target = "aabaabaaf";
    string pattern = "aa";
    //输出子串在原串中首次出现的位置，如果没有输出-1
    int pos = KMP(pattern, target);
    cout << pos;

    system("pause");
    return 0;

}