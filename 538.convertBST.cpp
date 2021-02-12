#include <iostream>
#include <vector>
#include <queue>//构造二叉树
#include <deque>

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

void getValue(deque<int> &values,TreeNode* root) {
    if(root == NULL) return;

    if(root->left) getValue(values,root->left);
    values.push_back(root->val);
    if(root->right) getValue(values,root->right);

    return;//递增的
}

void processValue(deque<int> &values) {
    for(int i = values.size() - 2; i >= 0 ; --i) {
        values[i] = values[i] + values[i + 1];
    }
    return;
}

void setValue(deque<int>& values,TreeNode* root) {
    if(root == NULL) return;

    if(root->left) setValue(values,root->left);

    root->val = values.front();
    values.pop_front();

    if(root->right) setValue(values,root->right);

    return;
}


TreeNode* convertBST(TreeNode* root) {
    if(!root) return root;
    deque<int> values;
    getValue(values,root);
    processValue(values);
    setValue(values,root);

    return root;
}

int main() {

    vector<int> input = {4,1,6,0,2,5,7,999,999,999,3,999,999,999,8};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    TreeNode* result = convertBST(root);//本题的输出

    system("pause");
    return 0;


}




