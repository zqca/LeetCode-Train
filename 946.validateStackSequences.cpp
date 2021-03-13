#include <iostream>
#include <vector>

using namespace std;

bool hasElement(vector<int> vec, int ele) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == ele) return 1;
    }
    return 0;
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    bool ans = true;
    int visitedPos = -1;//记录pushed数组中已经放入元素的位置，
    vector<int> vec;
    int i, j;
    for(i = 0; i < popped.size(); i++) {
        if(hasElement(vec,popped[i]) == false) {
            for(j = visitedPos + 1; j < pushed.size() && pushed[j] != popped[i]; j++) {
                vec.push_back(pushed[j]);
                visitedPos = j;
            }
            visitedPos ++;//指向最后插入的位置,会越界，但不影响
        }
        else {
            //存在
            if(vec[vec.size() - 1] != popped[i]) return false;
            vec.pop_back();//去除最后一个元素
        }
    }
    if (!vec.empty()) ans = false;
    return ans;

}

int main() {
    vector<int> pushed = {};
    vector<int> popped = {};
    bool ans = validateStackSequences(pushed, popped);
    cout << ans << endl;
    return 0;
}