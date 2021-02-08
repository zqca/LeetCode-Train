#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseLeftWords(string s, int n) {
    reverse(s.begin(), s.end());
    reverse(s.begin() + s.length() - n, s.end());
    reverse(s.begin(), s.end() - n);
    return s;

}

int main() {
    string s = "abcdefg";
    int n =2;
    s = reverseLeftWords(s, n);
    cout << s << endl;

    system("pause");
    return 0;
}