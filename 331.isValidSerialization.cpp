#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
/*TODO:
如输入： "9,3,4,#,#,1,#,#,2,#,6,#,#" ，当遇到 x # # 的时候，就把它变为 #。

模拟一遍过程：

9,3,4,#,# => 9,3,#，继续
9,3,#,1,#,# => 9,3,#,# => 9,# ，继续
9,#2,#,6,#,# => 9,#,2,#,# => 9,#,# => #，结束

//TODO:尝试递归，超时
void str2vec(string s, vector<string>& vec) {
    //将字符串存入
    s = ',' + s + ',';
    string tmp;
    int left = 0, right = 0;//左右逗号的位置

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == ',') {
            right = i;
            tmp = s.substr(left + 1, right - left - 1);
            vec.push_back(tmp);
            left = right;
        }
    }
}

bool backtracking(vector<string> order, int start, int end) {
    //左闭右开,for循环保证这个区间里元素的个数是奇数
    if(order[start] == "#" && end - start != 1) return false;//“#,...,...,”
    if(order[start] == "#" && end - start == 1) return true;//"#"
    if(order[start] != "#" && end - start == 1) return false;//“1”
    //如果当前节点是空，这个子树的长度是能是1
    
    if(end - start == 3) {//每一颗子树上至少有3个元素
        //叶子结点
        return true;//只要头节点不是空，左右孩子无所谓, 收割
    }

    for(int i = start + 2; i < order.size(); i += 2) {
        //i指向右孩子的头节点，当前节点已经排除了 #的可能
        if(order[i - 1] != "#") continue;
        bool leftIsOk = backtracking(order, start + 1, i);
        if(leftIsOk == false) continue;
        bool rightIsOk = backtracking(order, i, end);
        if(rightIsOk) return true;
    }

    return false;

}


bool isValidSerialization(string preorder) {
    vector<string> order;
    
    str2vec(preorder, order);//将每个节点存在order数组中
    if(order.size() % 2 == 0) return false;
    //有效的前序遍历，节点个数不应该是偶数
    
    bool ans = false;
    ans = backtracking(order, 0, order.size());//左闭右开

    return ans;
}
*/

void str2vec(string s, vector<string>& vec) {
    //将字符串存入
    s = ',' + s + ',';
    string tmp;
    int left = 0, right = 0;//左右逗号的位置

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == ',') {
            right = i;
            tmp = s.substr(left + 1, right - left - 1);
            vec.push_back(tmp);
            left = right;
        }
    }
}

bool isValidSerialization(string preorder) {
    //如输入： "9,3,4,#,#,1,#,#,2,#,6,#,#" ，当遇到 x # # 的时候，就把它变为 #。
    vector<string> order;
    
    str2vec(preorder, order);//将每个节点存在order数组中
    if(order.size() % 2 == 0) return false;
    //有效的前序遍历，节点个数不应该是偶数

    stack<int> myStack;//
    myStack.push(0);
    //stack里面放的数字无意义，如果遇到#，弹出一个元素；否则弹出一个元素，放入两个元素

    for(int i = 0; i < order.size(); i++) {
        if(myStack.empty()) {
            //如果没遍历结束就空了，无效
            return false;
        }
        else {
            myStack.pop();
            if(order[i] != "#") {
                myStack.push(0);
                myStack.push(0);
            }
        }
    }
    //如果遍历结束，栈没有空，无效
    if(myStack.empty() == false) return false;

    return true;
}




int main() {
    string preorder = "9,9,#,#,#";
    cout << isValidSerialization(preorder) << endl;

    return 0;
}