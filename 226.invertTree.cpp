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

//层次遍历，非本题需要
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    vector<vector<int>> result;

    if(root != NULL) {
        que.push(root);
    }

    while(!que.empty()) {
        vector<int> curVec;
        int levelSize = que.size();//当前队列（本层）的元素个数

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = que.front();
            que.pop();//将当前队列（本层）的元素依次弹出
            curVec.push_back(node->val);

            if(node->left) {
                que.push(node->left);//将下一层的元素加入
            }
            if(node->right) {
                que.push(node->right);//将下一层的元素加入
            }
        }
        result.push_back(curVec); 
    }

    return result;
        
}


void invert(TreeNode* root) {
    if(!root) {
        return;
    }
    invert(root->left);
    invert(root->right);

    TreeNode* tmp =root->left;
    root->left = root->right;
    root->right = tmp;
}

TreeNode* invertTree(TreeNode* root) {
    //递归反转二叉树
    invert(root);
    return root;
}



int main() {

    vector<int> input = {4,2,7,1,3,6,9};//使用999来代表null

    TreeNode* root = new TreeNode();
    constructTree(root, input);

    TreeNode* tmp = invertTree(root);//本题的输出

    //debug使用
    vector<vector<int> > result = levelOrder(tmp);
    for (auto i = 0; i < result.size(); i++) {
        for (auto item = result[i].begin(); item != result[i].end(); item++) {
            cout << *item <<" ";
        }
        cout << endl;
    }

    return 0;


}




