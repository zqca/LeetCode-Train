#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
queue <int> MainQueue, SubQueue;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        MainQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = MainQueue.size(), tmp;
        while (len > 1) {
            //除了最后一个元素之外全部倒入SubQueue
            tmp = MainQueue.front();
            SubQueue.push(tmp);
            MainQueue.pop();
            len--;
        }

        int result = MainQueue.front();
        MainQueue.pop();

        //将剩下的重新装回,并清空
        MainQueue = SubQueue;

        while(!SubQueue.empty()) {
            SubQueue.pop();
        }

        return result;
    }
    
    /** Get the top element. */
    int top() {
        int tmp = this -> pop();
        MainQueue.push(tmp);
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return MainQueue.empty();
    }
};

int main() {
    MyStack* obj = new MyStack();

    obj->push(1);
    obj->push(2);
    obj->push(3);

    int param_1 = obj->top();
    cout << param_1 << endl;//3

    int param_2 = obj->pop();
    cout << param_2 << endl;//3

    int param_3 = obj->top();
    cout << param_3 << endl;//2

    obj->pop();    
    obj->pop();
    bool param_4 = obj->empty();
    cout << param_4 << endl;//true



    return 0;
}

