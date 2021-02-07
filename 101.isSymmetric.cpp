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


bool compare(TreeNode* left, TreeNode* right) {

    if(left != nullptr && right == nullptr) return false;
    if(left == nullptr && right != nullptr) return false;
    if(left == nullptr && right == nullptr) return true;

    if(left->val != right->val) return false;

    bool OutIsOk = compare(left->left, right->right);//比较二叉树的外侧
    bool InIsOk = compare(left->right, right->left);//比较二叉树的内测

    return (OutIsOk && InIsOk);

}

bool isSymmetric(TreeNode* root) {
    /*递归，比较二叉树的内外侧;
        0
       / \
      1   1
     /\   /\
    3  4 4  3
   */
  if(root == nullptr)   return true;

  return compare(root->left, root->right);

}


int main() {

    //vector<int> input = {1,2,2,3,4,4,3};//使用999来代表null
    vector<int> input = {1,2,2,999,3,999,3};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    bool result = isSymmetric(root);//本题的输出
    cout << result << endl;
    
    return 0;

}