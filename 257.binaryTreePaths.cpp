#include <iostream>
#include <string>
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


void travel(TreeNode* node, vector<int>& path, vector<string>& result) {
    
    path.push_back(node->val);
    //始终保证node不是NULL,因此上面不会有error

    //TODO:这才到达了叶子节点
    if(node && node->left == NULL && node->right == NULL) {
        //到达叶子节点，结束。递归出口
        string curPath;
        for(int i = 0; i < path.size() - 1; ++i) {
            curPath += to_string(path[i]);
            curPath += "->";
        }
        curPath += to_string(path[path.size() - 1]);

        result.push_back(curPath);
        return;
        //TODO:回溯统一在调用时做
    }

    if (node->left) {
        //有左孩子，访问左孩子，回溯
        travel(node->left, path, result);
        path.pop_back();//回溯
    }

    if (node->right) {
        //有左孩子，访问左孩子，回溯
        travel(node->right, path, result);
        path.pop_back();//回溯
    }

}

vector<string> binaryTreePaths(TreeNode* root) {

    vector<string> result;
    vector<int> path;

    if(!root) return result;

    travel(root, path, result);

    return result;
}

int main() {

    vector<int> input = {1,2,3,999,5};//使用999来代表null
    //vector<int> input = {3,9,20,999,999,15,7};//使用999来代表null
    

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    vector<string> result = binaryTreePaths(root);//本题的输出

    for(auto item = result.begin(); item != result.end(); ++item) {
        cout << *item << endl;
    }
     
    system("pause");
    return 0;

}
