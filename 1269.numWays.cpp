#include <iostream>
#include <vector>

using namespace std;

int numWays(int steps, int arrLen) {
    int M = 7 + 1000000000;
    int Len = min(steps/2 + 1, arrLen) ;
    //优化：可能能走的步数很小，这时候最多走到steps/2才可能回到原点；可能步数很多，数组长度很小
    vector<int> dp(Len + 2, 0);
    vector<int> dp_pre(Len + 2, 0);
    //为数组添加了边界，
    dp[1] = 1;
    int tmp1, tmp2, tmp3;

    for(int i = 1; i < steps + 1; i++){
        dp_pre = dp;
        for(int j = 1; j < Len + 1; ++j){
            tmp1 = dp_pre[j - 1] % M;
            tmp2 = dp_pre[j] % M;
            tmp3 = dp_pre[j + 1] % M; 

            dp[j] = (((tmp1 + tmp2) % M + tmp3) % M);
              
        }
    }
     
    return dp[1];

}
int main()
{
   int steps = 27;
   int arrLen = 7;
   int ans = numWays(steps, arrLen);//4
   cout << ans << endl;
   return 0;
}
