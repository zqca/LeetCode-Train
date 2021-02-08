#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char,int> record;
    bool flag = true;
    for (char c : magazine) {
        ++record[c];
    }
    for(char c : ransomNote) {
        if(record[c]) {
            //如果字符c还剩下
            --record[c];
        }
        else {
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){
    string ransomNote = "aa";
    string magazine = "aab";
    bool result = canConstruct(ransomNote, magazine);
    cout << result << endl;
    system("pause");
    return 0;
}