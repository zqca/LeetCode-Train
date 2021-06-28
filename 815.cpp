#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<int, unordered_set<int> > travel;//全局的路径映射，在站点能坐的线路集合
    queue<int> que;
    unordered_set<int> bus_vis;

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        //初始化travel
        for(int i = 0; i < routes.size(); ++i){
            for(auto r: routes[i]){
                travel[r].insert(i);
            }
        }

        int ans = 0;
        que.push(source);
        while(que.size()){
            ++ans;//做一次车
            int len = que.size();
            for(int i = 0; i < len; ++i){
                auto buses = travel[que.front()];//这一站点可以做的bus集合
                que.pop();
                for(auto bus : buses){
                    if(bus_vis.count(bus)){
                        continue;//如果之前做过这个bus
                    }
                    bus_vis.insert(bus);
                    //当前选择的bus能到达的station
                    for(auto station : routes[bus]){
                        if(station == target){
                            return ans;
                        }
                        que.push(station);
                    } 
                }
            }
        }

        return -1;
    }
};

int main()
{
   vector<vector<int> > routes = {{1,2,7},{3,6,7}}; 
   int source = 1; 
   int target = 6;
   Solution solution;

   int ans = solution.numBusesToDestination(routes,source,target);
   cout << ans << endl;
   return 0;
}
