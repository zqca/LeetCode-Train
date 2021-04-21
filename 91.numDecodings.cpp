#include <iostream>
#include <vector>
#include <string>

using namespace std;


//TODO:DFS超时
int dfs(string s, int start) {
    int tmp = 0, count = 0;
    //当前字符串s,开始的位置
    if(start > s.size() - 1) {
        return 1;    
    }
    string curStr;
    int curNum;
    for(int i = 1; i + start <= s.size() && i < 3; i++){
        curStr = s.substr(start,i);
        curNum = stoi(curStr);
        if(i == 1){
            if(curNum == 0){
                
                continue;
            }
            else{
                tmp = dfs(s, start + i);
            }
        }
        else{
            if(curNum < 10 || curNum > 26){
                continue;
            }
            else{
                tmp = dfs(s, start + i);
            }
        } 

        count += tmp;

    }
    return count;
}

int numDecodings1(string s) {
    return dfs(s,0);
}

//TODO:DP 

bool isValid(string tmp){
    int num = stoi(tmp);
    if(tmp.size() == 1 && num >= 1 && num <=9) return true;
    if(tmp.size() == 2 && num >= 10 && num <=26) return true;
    return false;
}

int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(1+n,1);//初始化1！！！！！！！！！

    if(s[0] == '0') return 0;
    
    bool flag1, flag2;
    for(int i = 2; i < n + 1; ++i){
        //如果单个、双个同时不能划分，返回0；比如 110能划分为1,10；100不能划分
        flag1 = isValid(s.substr(i-1,1));
        flag2 = isValid(s.substr(i-2,2));
        if(flag1 && flag2) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        else if(flag1 && !flag2){
            dp[i] = dp[i-1];
        }
        else if(!flag1 && flag2){
            dp[i] = dp[i-2];
        }
        else{
            return 0;
        }

    }
    return dp[n];

}

int main()
{
    string s = "204";
    int ans = numDecodings(s) ;

    cout << ans << endl;
    
    system("pause");
    return 0;
}
