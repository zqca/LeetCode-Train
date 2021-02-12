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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    TreeNode* fa = NULL;
    TreeNode* cur = root;

    if(cur == NULL) return newNode;

    int isLeft = 1;
    while(cur) {
        if(cur->val < val) {
            fa = cur;
            cur = cur->right;
            isLeft = 0;
            continue;
        }
        else {
            fa = cur;
            cur = cur->left;
            isLeft = 1;
        }
    }
    if(isLeft) {
        fa->left = newNode;
    }
    else {
        fa->right = newNode;
    }

    return root;
        
}

int main() {

    vector<int> input1 = {4,2,7,1,3};//使用999来代表null
    int input2 = 5;

    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);


    TreeNode* result = insertIntoBST(root1, input2);

    system("pause");
    return 0;
}