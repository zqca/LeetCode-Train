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

bool isValid(TreeNode* node, int low, int high) {
    return ((node->val >=low) && (node->val <= high));
}

TreeNode* trim(TreeNode* node, int low, int high) {
    if(node == NULL) return NULL;

    if(isValid(node,low,high)) {
        if(node->left) {
            node->left = trim(node->left,low,high);
        }
        if(node->right) {
            node->right = trim(node->right,low,high);
        }   
        return node;
    }

    if(node->val < low) {
        return trim(node->right,low,high);
    }
    else {
        return trim(node->left,low,high);
    }

}

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(!root) return root;

    TreeNode* result = trim(root,low,high);
    return result;
}

int main() {

    vector<int> input1 = {3,0,4,999,2,999,999,1};
    //{1,0,2};
    //{3,0,4,999,2,999,999,1};//使用999来代表null
    int low = 1;
    int high = 3;

    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);


    TreeNode* result = trimBST(root1,low,high);

    system("pause");
    return 0;
}