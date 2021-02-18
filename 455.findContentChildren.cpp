#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
    
    if(s.size() == 0) return 0;
    int ans = 0, index = 0;
    //从小到大排序，想满足胃口小的child
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    for(int child = 0; child < g.size(); child++) {
        for(int i = index; i < s.size(); i++) {
            if(s[i] >= g[child]) {
                ans++;
                index = i + 1;
                break;
            }  
        }
         
    }
    return ans;
}

int main() {
    vector<int> g = {10,9,8,7}; 
    vector<int> s = {6};

    int ans = findContentChildren(g, s);
    cout << ans << endl;

    return 0;
}