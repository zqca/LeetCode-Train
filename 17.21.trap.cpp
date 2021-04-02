#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int res = 0;
    int l, r;

    for(int i = 1; i < height.size(); i++) {
        l = height[i];
        r = height[i];
        for(int j = i; j >= 0; j--) {l = max(height[j], l);}
        for(int j = i; j < height.size(); j++) {r = max(height[j], r);}
        //当前位置能接到的数字
        res += min(l,r) - height[i];
    }
    return res;

}

int main() {
    vector<int> height = {4,2,3};
    cout << trap(height) << endl;//6

    return 0;
}