#include <iostream>
#include <vector>
#include <set>

using namespace std;
/*
2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
*/
bool canCross(vector<int>& stones) {
    int len = stones.size();
    vector<bool> dp(len,false);
    dp[0] = true;
    vector<set<int> > jump(len, set<int>());
    jump[0].insert(1);

    int maxstep = 1;
    int needstep,curstep;
    for(int i = 1; i < len; i++){
        //循环石头
        for(int j = i - 1;j >= 0 && stones[j] + maxstep >= stones[i]; --j){
            //遍历可能的上一步
            needstep = stones[i] - stones[j];
            auto pos = jump[j].find(needstep);
            if(pos != jump[j].end()){
                //找到了
                dp[i] = true;
                curstep = *pos;
                maxstep = max(maxstep, curstep + 1);

                if(curstep - 1 > 0)
                    jump[i].insert(curstep - 1);
                jump[i].insert(curstep);
                jump[i].insert(curstep + 1);
            }

        }
    }
    return dp[len - 1];

}

int main()
{
   vector<int> stones = {0,1,2,3,4,8,9,11};
   bool ans = canCross(stones);
   cout << ans << endl;
   return 0;
}
