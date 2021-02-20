#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int ans = -1, start, end, left = 0;
    vector<int> vec;
    for (int i = 0; i < gas.size(); i++) {
        vec.push_back(gas[i] - cost[i]);
    }
    for(start = 0; start < gas.size(); ++start) {
        if(vec[start] < 0) continue;

        left = vec[start];//初始化当前剩余
        for(end = start + 1; end != start; end++) {
            if(end == gas.size()) {
                end = -1;
                continue;//之后还会执行for的加1.所以上面设置为-1
            }
            left += vec[end];
            if(left < 0) break;//到达下一节点的时候剩的
            
        }
        //如果找到了一个答案
        if(end == start) break;
    }

    if(start != gas.size()) {
        ans = start;
    }
    
    return ans;
}

int main() {
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};
    int ans = canCompleteCircuit(gas, cost);
    cout << ans << endl;

    return 0;
}