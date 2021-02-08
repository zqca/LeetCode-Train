#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class comp{
    public:
    bool operator()(pair<int,int> left, pair<int,int> right) {
        //我想要小的元素在前面，返回true则交换两个参数的位置
        return left.second > right.second;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    //首先，建立一个哈希表<元素，出现次数>
    unordered_map<int,int> table;
    for(int i = 0; i < nums.size(); ++i) {
        table[nums[i]]++;
    }

    //建立一个优先权队列（小顶堆）
    priority_queue<pair<int,int>, vector<pair<int,int> >, comp> myQue;
    for (auto iter = table.begin(); iter != table.end(); iter++) {
        myQue.push(*iter);
        if(myQue.size() > k) {
            myQue.pop();
        }

    }

    vector<int> result;
    for(int i = 0; i < k; ++i) {
        int tmp = myQue.top().first;
        result.push_back(tmp);
        myQue.pop();
    }

    return result;


}

int main() {
    vector<int> nums = {1,1,1,2,2,3,3,3,3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    system("pause");
    return 0;

}