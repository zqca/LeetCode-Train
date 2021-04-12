#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubstrings(string s) {
    int len = s.size();
    if(len == 0) return 0;
    //dp[i][j]表示s[i:j]是否是回文
    int count = 0;
    vector<vector<bool> > dp(len, vector<bool>(len, false));

    for(int i = len - 1; i >= 0; i--){
        for(int j = i; j < len; j++){
            if(j - i < 2) {//一个元素或者两个元素
                if(s[i] == s[j]){
                    dp[i][j] = true;
                    count++;
                }
                else{
                    dp[i][j] = false;
                }
                continue;
            }

            if(s[i] == s[j] &&  i + 1 < len && j - 1 >=0 && dp[i + 1][j - 1]){
                dp[i][j] = true;
                count++;
            }
            else{
                dp[i][j] = false;
            }


        }
    }
    return count;

}

int main(){
    string s = "aaa";
    int ans = countSubstrings(s) ;

    cout << ans << endl;

    return 0;
}