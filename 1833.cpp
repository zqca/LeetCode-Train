#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        int used = 0;
        for(int i = 0; i < costs.size(); i++){
            if(used > coins){
                break;//没钱了
            }
            if(costs[i] <= coins - used){
                ++ans;
                used += costs[i];
            }
            else{
                break;//后面都买不起
            }
        }
        return ans;

    }
};

int main()
{
   vector<int> costs = {1,3,2,4,1}; 
   int coins = 7;
   Solution solution;
   int ans = solution.maxIceCream(costs, coins);
   cout << ans << endl;
   return 0;
}
