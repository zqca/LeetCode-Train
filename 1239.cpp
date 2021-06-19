#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxLength(vector<string>& arr) {
    //对于每一个字符串，使用二进制表示每个字母是否出现过
    vector<int> masks = {0};//存放已有的结果
    int ans = 0;
    for(auto str : arr) {
        //检查当前字符串是否合法
        int mask = 0;//当前字符串的字母出现情况，默认为0
        for(char ch : str) {
            int cur = ch - 'a';
            if((mask >> cur) & 1){
                //同一字符串内有重复的字母
                mask = 0;
                break;
            }
            mask = (mask | (1 << cur));
        }

        if(mask == 0){
            continue;//下一个字符串
        }

        //尝试连接
        int len = masks.size();
        for(int i = 0; i < len; ++i){
            int m = masks[i];
            if ((m & mask) == 0) { // m 和 mask 无公共元素
                masks.push_back(m | mask);
                ans = max(ans, __builtin_popcount(m | mask));
                //__builtin_popcount可以精确的计算1的个数
            }
        }
    }
    return ans;

}

int main()
{
   vector<string> arr = {"un","iq","ue"};
   int ans = maxLength(arr);
   cout << ans << endl;
   return 0;
}
