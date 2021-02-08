#include <iostream>
#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> InStack, OutStack;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        InStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (OutStack.empty()) {
            //如果是空的,把InStack的元素全部倒入
            while(!InStack.empty()) {
                OutStack.push(InStack.top());
                InStack.pop();
            }
        }
        int tmp = OutStack.top();
        OutStack.pop();
        return tmp;

    }
    
    /** Get the front element. */
    int peek() {
        int tmp = this->pop();
        //重新放回
        OutStack.push(tmp);
        return tmp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return InStack.empty() && OutStack.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);

    int param_1 = obj->pop();
    cout << param_1 << endl;

    int param_2 = obj->peek();//取队列第一个元素的值
    cout << param_2 << endl;

    int param_3 = obj->pop();
    cout << param_3 << endl;

    bool param_4 = obj->empty();
    cout << param_4 << endl;

    system("pause");
    return 0;
}

