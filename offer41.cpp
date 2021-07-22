#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int> > left;//大根堆，左侧，放较小的数
    priority_queue<int, vector<int>, greater<int> > right;//小根堆，右侧，放较大的数

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.empty() || num < left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
        //调节平衡,左侧最多比右侧多一个元素
        if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        if(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return double(left.top() + right.top()) / 2;
        }
        else{
            //左多右少，或者左少右多，取多的那一侧
            return left.size() > right.size() ? left.top() : right.top();
        }
    }
};

int main()
{
   
   int ans = 0;
   cout << ans << endl;
   return 0;
}
