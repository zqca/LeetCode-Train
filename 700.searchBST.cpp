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

TreeNode* searchBST(TreeNode* root, int val) {
    //注意，这是BST，左孩子小于父节点的值，右孩子大于。。。
    if(!root) {
        //没找到
        return NULL;
    }

    if(root->val > val) {
        return searchBST(root->left,val);
    }

    if(root->val < val) {
        return searchBST(root->right,val);
    }

    return root;
    

}



int main() {

    vector<int> input1 = {4,2,7,1,3};//使用999来代表null
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    int val = 2;

    TreeNode* result = searchBST(root1,val);

    system("pause");
    return 0;
}