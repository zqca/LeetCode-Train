#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int numDifferentIntegers(string word) {
    unordered_set<string> result;

    string tmp;
    bool flag;

    for(int i = 0; i < word.length(); i++) {

        if(word[i] - '0' >= 0 && word[i] - '0' <= 9) {
            tmp = "0";
            flag = true;
            
            while(i < word.length() && word[i] - '0' >= 0 && word[i] - '0' <= 9) {
                if(flag && word[i] - '0' == 0) {
                    i++;
                    continue;
                }
                else{
                    flag = false;
                }

                tmp += word[i];
                ++i;
            }
            --i;
            result.insert(tmp);
        }
    }
    return result.size();
}

int main() {
    string word = "00000";
    int ans = numDifferentIntegers(word);

    cout << ans << endl;

    return 0;

}