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



TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 ==  NULL && root2 == NULL) {
        return NULL;
    }
    
    if(root1 ==  NULL && root2 != NULL) {
        return root2;
    }
    if(root1 !=  NULL && root2 == NULL) {
        
        return root1;
    }
    //最后一中情况，两个输入参数都不是空

    TreeNode* leftTree = mergeTrees(root1->left, root2->left);//新左节点
    TreeNode* rightTree = mergeTrees(root1->right, root2->right);//新右节点
    TreeNode* root = new TreeNode(root1->val + root2->val);
    root->left = leftTree;
    root->right = rightTree;
    
    return root;

}



int main() {

    vector<int> input1 = {1,2,999,3};//使用999来代表null
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    vector<int> input2 = {1,999,2,999,3};//使用999来代表null
    TreeNode* root2 = new TreeNode();
    constructTree(root2, input2);

    TreeNode* result = mergeTrees(root1,root2);

    system("pause");
    return 0;
}