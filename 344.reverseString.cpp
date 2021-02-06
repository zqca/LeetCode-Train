#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int j = s.size() - 1;
    for(int i = 0; i < j;) {
        // swap(&s[i++], &s[j--]);
        swap(s[i++], s[j--]);//std的库函数，不需要自己写
    }
        
}
int main() {
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for(char c : s) {
        cout << c << endl;
    }
    return 1;

}