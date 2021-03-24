#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if(n < 3) return false;
    //首先维护包含当元素在内的左侧最小值数组,这个数组里面的数字作为“1”
    vector<int> minVec(n, 0);
    int minVal = nums[0];
    for(int i = 0; i < n; ++i) {
        minVal= min(minVal, nums[i]);
        minVec[i] = minVal;
    }

    stack<int> myStack;//栈顶是最小的，因为栈中的元素始终保持比“1”大

    for(int j = n - 1; j > 0; --j) {
        //nums[j]作为“3”，最大的
        if(nums[j] > minVec[j - 1]) {
            //当前的“3”必须比左边的最小值要大
            //首先去除栈里面比“1”小的元素
            while(myStack.size() && myStack.top() <= minVec[j - 1]) {
                myStack.pop();
            }
            //如果当前栈顶的元素比“3”小，就是找到了答案
            if(myStack.size() && myStack.top() < nums[j]) 
                return true;

            //此时，栈为空或者栈顶元素会大于等于“3”,加入
            myStack.push(nums[j]);
        }
    }

    return false;
}

int main() {
    vector<int> nums = {-2,1,-1};
    bool ans = find132pattern(nums);
    cout << ans << endl;

    return 0;

}