#include <iostream>
#include <vector>
#include <queue>//构造二叉树

#include <unordered_map>

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

int getPath(int val, TreeNode* node, vector<TreeNode*>& path) {
    //找到从root到 值等于val的节点 的路径，回溯;
    //返回值0表示没找到，1表示找到了

    //出口1
    if(!node) return 0;

    //出口2
    if(node->val == val) {
        path.push_back(node);
        return 1;
    }

    //已经到达了叶子，并且不符合,需要回溯
    if(node->left == NULL && node->right == NULL) {
        return 0;
    }

    path.push_back(node);//将当前节点放入，开始寻找

    int hasfound = getPath(val, node->left, path);

    if(hasfound == 0) {//左树没找到
        //找右树
        hasfound = getPath(val, node->right, path);
        if(hasfound == 0) {//右树也没有，回溯
            path.pop_back();
            return 0;
        }
    }

    return 1;
    
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path_p; 
    getPath(p->val, root, path_p);
    vector<TreeNode*> path_q; 
    getPath(q->val, root, path_q);

    int i;
    for(i = 0; i < min(path_p.size(), path_q.size()); ++i) {
        if(path_p[i] != path_q[i]) {
            break;
        }
    }

    return path_q[i - 1];
        
}

int main() {

    vector<int> input1 = {3,5,1,6,2,0,8,999,999,7,4};//使用999来代表null

    TreeNode* root1 = new TreeNode();
    constructTree(root1, input1);

    //本题较特殊，首先构造二叉树，然后找到指针p,q(需要根据已经改造的树来确定p,q)
    TreeNode* p = root1->left;
    TreeNode* q = p->right->right;

    TreeNode* result = lowestCommonAncestor(root1, p, q);

    system("pause");
    return 0;
}