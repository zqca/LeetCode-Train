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


vector<int> visit(TreeNode* node) {
    if(node == NULL) {
        return vector<int>{0,0};
    }
    //后续遍历
    vector<int> left = visit(node->left);
    vector<int> right = visit(node->right);

    vector<int> cur = {0, 0};
    //如果抢当前节点,左右孩子都不能抢
    cur[0] = node->val + left[1] + right[1];

    //如果不抢当前节点,左右孩子都是可抢可不抢
    cur[1] = max(left[0], left[1]) + max(right[0], right[1]);

    return cur;
}

int rob(TreeNode* root) {
    
    //每个节点记录一个数组dp={抢的收益，不抢的收益}
    vector<int> res = visit(root);
    return max(res[0], res[1]);
}


int main() {

    vector<int> input = {3,4,5,1,3,999,1};//使用999来代表null
    TreeNode* root = new TreeNode();
    constructTree(root, input);

    cout << rob(root) << endl;

    return 0;

}