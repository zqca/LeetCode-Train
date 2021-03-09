#include <iostream>
#include <string>

using namespace std;

string strConstruct(string input) {
    int count = 0;
    string output = "";
    int i, j;

    for(i = 0; i < input.length(); ) {
        count = 0;
        for(j = i; j < input.size(); j++) {
            if(input[j] != input[i]) {       
                break;
            }
            count++;
        }
        output += to_string(count) + input[i];
        i = j;
    }

    return output;

}


string countAndSay(int n) {
    string ans = "1";
    for(int i = 1; i < n; i++) {
        ans = strConstruct(ans);
    }

    return ans;
}

int main() {
    int n = 5;
    cout << countAndSay(n) << endl;

    return 0;
}