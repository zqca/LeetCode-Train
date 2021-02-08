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


bool check(TreeNode* node, int count) {
    //count代表到达当前节点之后，（加上当前节点的值之前）还差多少完成目标
    //递归出口：到达叶子结点，并且不符合要求
    if(node->left == NULL && node->right == NULL && count == node->val) {
        return 1;
    }
    //到达叶子但是不符合要求
    if(node->left == NULL && node->right == NULL) {
        return 0;
    }

    if(node->left) {
        count -= node->val;
        if(check(node->left, count)) {
            return 1;
        }
        //回溯
        count += node->val;
    }

    if(node->right) {
        count -= node->val;
        if(check(node->right, count)) {
            return 1;
        }
        //回溯
        count += node->val;
    }

    return 0;

}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;
    return check(root, targetSum);
}


int main() {

    vector<int> input = {5,4,8,11,999,13,4,7,2,999,999,999,1};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    int targetSum = 22;
    bool result = hasPathSum(root, targetSum);//本题的输出

    cout << result;

    system("pause");
    return 0;


}




