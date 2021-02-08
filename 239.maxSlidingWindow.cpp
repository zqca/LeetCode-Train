#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class DecreaseQue{
    private:
    deque<int> que;

    public:

    void push(int item) {
        while (!que.empty() && item > que.back()) {//非增序列
            que.pop_back();
        }
        que.push_back(item);  
    }

    void pop(int value) {
        //如果移出窗口的元素不是非增序列的第一个，不动
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
    }

    int front() {

        return que.front();
    }

};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int i;
    DecreaseQue Que;
    vector<int> result;

    for (i = 0; i < k; ++i) {
        Que.push(nums[i]);
    }
    result.push_back(Que.front());

    for (i = k; i < nums.size(); ++i) {
        //i指向的是即将加入窗口的元素
        Que.pop(nums[i - k]);//将窗口第一个元素移除，会判断是否影响非增序列
        Que.push(nums[i]);
        result.push_back(Que.front());

    }

    return result;

}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    
    system("pause");
    return 0;
}