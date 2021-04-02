#include <iostream>
#include <vector>

using namespace std;

int trap1(vector<int>& height) {
    //暴力
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

int trap(vector<int>& height) {
    //动态规划
    
    int res = 0;
    int len = height.size();
    if(len == 0) return 0;
    vector<int> maxleft(len), maxright(len);
    //本元素及其左侧、右侧的最大高度

    maxleft[0] = height[0];
    maxright[len - 1] = height[len - 1];

    for(int i = 1; i < len; i++){
        maxleft[i] = max(maxleft[i - 1], height[i]);
    }

    for(int i = len - 2; i >= 0; i--){
        maxright[i] = max(maxright[i + 1], height[i]);
    }

    for(int i = 1; i < height.size(); i++) {
        //当前位置能接到的数字
        res += min(maxleft[i], maxright[i]) - height[i];
    }
    return res;

}

int main() {
    vector<int> height = {4,2,3};
    cout << trap(height) << endl;//6

    return 0;
}