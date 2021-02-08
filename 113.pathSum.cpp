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


void findPath(TreeNode* node, int count, vector<int> path, vector<vector<int>>& result) {
    //count代表到达当前节点之后，（加上当前节点的值之前）还差多少完成目标
    //递归出口：1.到达符合要求的叶子结点
    if(node->left == NULL && node->right == NULL && count == node->val) {
        path.push_back(node->val);
        result.push_back(path);
        path.pop_back();//去掉叶子结点
        return;
    }
    //递归出口：2.到达叶子结点，并且不符合要求
    if(node->left == NULL && node->right == NULL) {
        //到达不符合的叶子结点
        return;
    }
    

    if(node->left) {
        path.push_back(node->val);//加入当前节点
        count -= node->val;
        findPath(node->left, count, path, result);
        //回溯
        path.pop_back();//去掉当前节点
        count += node->val;
    }

    if(node->right) {
        path.push_back(node->val);
        count -= node->val;
        findPath(node->right, count, path, result);
        //回溯
        path.pop_back();
        count += node->val;
    }


}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int> > result;
    vector<int> path;
    
    if(!root) {
        return result;
    }
    findPath(root, targetSum, path, result);
    return result;

}

int main() {
    //本题输入
    vector<int> input = {5,4,8,11,999,13,4,7,2,999,999,5,1};//使用999来代表null
    int targetSum = 22;

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    
    //本题输出
    vector<vector<int> > result = pathSum(root, targetSum);

    for(auto item = 0; item < result.size(); item++) {
        for(auto i = 0; i < result[item].size(); ++i) {
            cout << result[item][i] << " ";
        }
        cout << endl;
    }


    system("pause");
    return 0;


}




