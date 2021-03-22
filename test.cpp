#include <iostream>
#include <vector>
#include <queue>//构造二叉树

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//由数组构造二叉树，非本题需要
void constructTree(TreeNode* root, vector<int> input) {
    queue<TreeNode*> que;//存放即将构造的节点
    int len = input.size();
    int i;
    TreeNode* cur;

    TreeNode* lchild;
    TreeNode* rchild;

    if(input[0] == 999) {
        return;
    }
    else {
        root->val = input[0];
    }

    que.push(root);

    for(i = 1; i < len; i++) {
        cur = que.front();
        //设置左节点
        if(i < len && input[i] != 999) {//不是null
            lchild = new TreeNode();
            lchild->val = input[i];
            cur->left = lchild;
            que.push(lchild);   
        }

        i++; 
    //设置右节点
        if(i < len && input[i] != 999) {//不是null
            rchild = new TreeNode();
            rchild->val = input[i];
            cur->right = rchild;
            que.push(rchild);  
        }
        que.pop();

    }


}


vector<int> path;

int backtracking(TreeNode* node, int target) {
    if(node == NULL) return 0;
    if(node->val == target) {
        return 1;
    }

    int left = 0, right = 0;
    path.push_back(node->val);

    if(node->left) {
        path.push_back(node->left->val);
        left = backtracking(node->left, target);
        if(left) {
            //找到了
            return 1;
        }
        else {
            path.pop_back();//吐出当前左孩子
        }
    }

    if(node->right) {
        path.push_back(node->right->val);
        right = backtracking(node->right, target);
        if(right) {
            //找到了
            return 1;
        }
        else {
            path.pop_back();//吐出当前左孩子
        }
    }
    path.pop_back();//吐出当前节点

    return 0;
}

void findpath(TreeNode* node, int val) {
    backtracking(node, val);
}

int main() {

    vector<int> input1 = {5,1,4,999,999,3,6};//使用999来代表null
    int target = 7;
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    findpath(root1, target);//结果存在result数组中

    if(path.size() == 0) {
        cout << "Not found" << endl;
    }
    else {
        for(int item: path) {
            cout << item << " ";
        }
    }

    return 0;
}