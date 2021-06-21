#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getNum(int bits, int max, bool ismin){
        //输入指定的位数,是否是分钟,返回不超过max的数字集合,
        vector<string> ans;
        for(int i = 0; i <= max; ++i){
            if(__builtin_popcount(i) == bits){
                if(ismin && i < 10){   
                    ans.push_back("0" + to_string(i));
                }
                else{
                    ans.push_back(to_string(i));
                }  
            }

        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> minute, hour, ans;
        int len_m, len_h;

        for(int i = 0; i <= turnedOn; ++i){
            //优先考虑分钟亮的个数
            minute = getNum(i, 59, true);
            hour = getNum(turnedOn - i, 11, false);

            len_m = minute.size();
            len_h = hour.size();

            if(len_m == 0 || len_h == 0) {
                minute.clear();
                hour.clear();
                continue;
            }
            else{
                //拼接字符串加入到ans
                for(int j = 0; j < len_h; ++j){
                    for(int k = 0; k < len_m; ++k){
                        ans.push_back(hour[j] + ":" + minute[k]);
                    }
                }
                minute.clear();
                hour.clear();
            }
        }
        return ans;

    }
};
//官方解答，更加简洁！！！
class Solution1 {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/binary-watch/solution/er-jin-zhi-shou-biao-by-leetcode-solutio-3559/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int main()
{
   Solution solution;

   int turnedOn = 1;
   vector<string> ans = solution.readBinaryWatch(turnedOn);
   //cout << ans << endl;
   return 0;
}
