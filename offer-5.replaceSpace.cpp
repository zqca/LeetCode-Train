#include<iostream>
#include<string>
using namespace std;

string replaceSpace(string s) {
    int oldSize = s.size();
    int countSpace = 0, head, tail, i;
    for(i = 0; i < oldSize; ++i) {
        if(s[i] == ' ') {
            ++countSpace;
        }
    }
    int newSize = oldSize + countSpace * 2;//TODO:每一个空格需要增加2个长度

    s.resize(newSize);//TODO:改变字符串的长度

    for(head = oldSize - 1, tail = newSize - 1; head < tail; --head, --tail) {
        if(s[head] != ' ') {
            s[tail] = s[head];
        }
        else {
            s[tail] = '0';
            s[tail - 1] = '2';
            s[tail - 2] = '%';
            tail -= 2;//TODO:退2个，有一个是本来就要退的
        }
    }
    return s;


}

int main() {
    string s = "We are happy.";
    string result = replaceSpace(s);
    cout << result << endl;
    return 0;

}