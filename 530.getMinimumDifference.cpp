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

void Travel(TreeNode* root, vector<int>& result) {

    if(!root) {
        return;
    }

    if(root->left) {
        Travel(root->left, result);
    }

    result.push_back(root->val);

    if(root->right) {
        Travel(root->right, result);
    }

    return;
}


int getMinimumDifference(TreeNode* root) {
    vector<int> midTravel;//中序遍历的结果
    Travel(root,midTravel);

    int len = midTravel.size();

    int diff;

    int minDiff = midTravel[1] - midTravel[0];
    

    for(int j = 1; j < len; ++j) {
        diff = midTravel[j] - midTravel[j - 1];
        if (minDiff > diff) minDiff = diff;   
    }

    return minDiff;
}

int main() {

    vector<int> input1 = {1,999,3,2};//使用999来代表null
    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);


    int result = getMinimumDifference(root1);

    system("pause");
    return 0;
}