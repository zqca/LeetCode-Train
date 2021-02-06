#include <iostream>
#include <vector>
#include <queue>//构造二叉树
#include <stack>//非递归遍历

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//不使用递归，方便记忆

vector<int> preorderTraversal(TreeNode* root) {
    //前序，中左右=>右左中
    vector<int> result;
    stack<TreeNode*> myStack;
    if(root) {
        //非空
        myStack.push(root);
    }

    while(!myStack.empty()) {
        TreeNode * node = myStack.top();

        if(node != NULL) {
            myStack.pop();
            //右
            if(node->right) {
                myStack.push(node->right);
            }
            //左
            if(node->left) {
                myStack.push(node->left);
            }
            //中
            myStack.push(node);
            myStack.push(NULL);
        }
        else {
            myStack.pop();
            node = myStack.top();
            myStack.pop();
            result.push_back(node->val);
        }      

    }
   
    return result;
}


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

int main() {

    vector<int> input = {1,999,2,3};//使用999来代表null

    int i;
    TreeNode* root = new TreeNode();
    constructTree(root, input);

    vector<int> result = preorderTraversal(root);

    for (auto i = result.begin(); i != result.end(); i++) {
        cout << *i << endl;
    }

    return 0;


}