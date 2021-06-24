#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        for(int i = 0; i < points.size(); i ++){
            unordered_map<long long, int> map;
            for(int j = i + 1; j < points.size(); j ++){    
                // 计算deltaX deltaY
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];

                if(x == 0){ // 斜率不存在的情况
                    map[1e18 + points[j][0]] ++;   // 1e18 = 1e9 * 1e9
                }else{
                    double k = (double) y / x;
                    double b = points[j][1] - k * points[j][0];
                    long long tmp = k * 1e9 + b;    // 合成新的哈希值
                    ++ map[tmp];
                }
            }
            // 统计答案
            for(auto &[i, j] : map)
                ans = max(ans, j + 1);
        }
        return ans;
    }
};
/*
作者：Raymond_YP
链接：https://leetcode-cn.com/problems/max-points-on-a-line/solution/c-zhi-xian-shang-zui-duo-de-dian-shu-by-wvol4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
